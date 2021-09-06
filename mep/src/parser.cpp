#include <set>
#include "parser.hpp"

namespace mep::details {
    template<class _T>
    bool _choose(const std::unique_ptr<_T>& opt) {
        return opt != nullptr;
    }
    
    bool _choose(const Token& t, const TokenType& ty) {
        return t.token_type == ty;
    }

    template<class _T>
    std::unique_ptr<_T> _mk_uptr(_T&& rhs) {
        return std::make_unique<_T>(std::forward<_T>(rhs));
    }

    template<class _T>
    std::optional<_T> _mk_opt(_T&& rhs) {
        return std::make_optional<_T>(std::forward<_T>(rhs));
    }

    template<class... _Ts>
    std::optional<std::tuple<_Ts...>> _mk_otpl(_Ts&& ...elements){
        return std::make_optional(std::make_tuple<_Ts...>((std::forward<_Ts>(elements))...));
    };

    template<class _T>
    constexpr void _expect(const std::unique_ptr<_T>& t) {
        if (t == nullptr) {
            throw ParserError();
        }
    }

    constexpr void _expect(const Token& t, const TokenType& ty) {
        if (t.token_type != ty) {
            throw ParserError();
        }
    }

    constexpr void _expect(bool compare_result) {
        if (!compare_result) {
            throw ParserError();
        }
    }

    template<class _T>
    constexpr bool _match_first(const Token&) {
        throw std::logic_error("not implemented");
    }
    template<>
    constexpr bool _match_first<ast::Parenthesized>(const Token& t) {
        return t.token_type == TokenType::LeftParenthesis;
    }
    template<>
    constexpr bool _match_first<ast::PrefixUnaryExpression>(const Token& t) {
        return t.token_type == TokenType::Plus
            || t.token_type == TokenType::Minus;
    }
    template<>
    constexpr bool _match_first<ast::Function>(const Token& t) {
        return t.token_type == TokenType::Identifier;
    }
    template<>
    constexpr bool _match_first<ast::Atom>(const Token& t){
        return _match_first<ast::Parenthesized>(t)
            || _match_first<ast::PrefixUnaryExpression>(t)
            || _match_first<ast::Function>(t)
            || is_num_token(t);
    }
    template<>
    constexpr bool _match_first<ast::Exponentiation>(const Token& t) {
        return _match_first<ast::Atom>(t);
    }
    template<>
    constexpr bool _match_first<ast::PostfixUnaryExpression>(const Token& t) {
        return _match_first<ast::Atom>(t);
    }
    template<>
    constexpr bool _match_first<ast::Factor>(const Token& t) {
        return _match_first<ast::PostfixUnaryExpression>(t)
            || _match_first<ast::Exponentiation>(t)
            || _match_first<ast::Atom>(t);
    }
    template<>
    constexpr bool _match_first<ast::MultiplicationSignOmitted>(const Token& t) {
        return _match_first<ast::Factor>(t)
            || _match_first<ast::ParameterList>(t)
            || _match_first<ast::Function>(t);
    }
    template<>
    constexpr bool _match_first<ast::ContinuedMultiplicationSignOmitted>(const Token& t) {
        return _match_first<ast::Parenthesized>(t)
            || _match_first<ast::Function>(t);
    }
    template<>
    constexpr bool _match_first<ast::ContinuedMultiplicationOrDivision>(const Token& t) {
        return t.token_type == TokenType::Mult
            || t.token_type == TokenType::Divide
            || _match_first<ast::ContinuedMultiplicationSignOmitted>(t);
    }
    template<>
    constexpr bool _match_first<ast::Multiplication>(const Token& t) {
        return _match_first<ast::Factor>(t)
            || _match_first<ast::MultiplicationSignOmitted>(t);
    }
    template<>
    constexpr bool _match_first<ast::Division>(const Token& t) {
        return _match_first<ast::Factor>(t);
    }
    template<>
    constexpr bool _match_first<ast::Term>(const Token& t) {
        return _match_first<ast::Multiplication>(t)
            || _match_first<ast::Division>(t)
            || _match_first<ast::Factor>(t);
    }

    /* **************************************************************
    <expression> ::= <addition>
                   | <subtraction>
                   | <term>
    ************************************************************** */
    std::unique_ptr<ast::Expression> expression(const next_f& next, const restore_f& restore, kac_t& kac){
        // to avoid backtracking, we need to decide which fork we have choose
        // so, we can parse the common syntax part - a **term** - and then check the operator
        // if the operator is "+", then the next selection must be addition
        // if the operator is "-", then the next selection must be subtraction
        // if the operator is EOE, then we meet the finish of expression
        // otherwise, the input expression must be wrong in syntax
        auto trm = term(next, restore, kac); // look ahead to seek for a term
        _expect(trm);
        kac.push(std::move(trm));

        // look ahead to decide which fork to choose
        Token lat = next(); // look ahead token
        if (_choose(lat, TokenType::Plus)) { // addition
            restore(std::move(lat));
            auto add = addition(next, restore, kac);
            _expect(add);
            return _mk_uptr(ast::Expression{ .addition = std::move(add) });
        }
        else if (_choose(lat, TokenType::Minus)) { // subtraction 
            restore(std::move(lat));
            auto sub = subtraction(next, restore, kac);
            _expect(sub);
            return _mk_uptr(ast::Expression{ .subtraction = std::move(sub) });
        }
        else { // term
            restore(std::move(lat));
            auto t = kac.pop<std::unique_ptr<ast::Term>>();
            return _mk_uptr(ast::Expression{ .term = std::move(t) });
        }
    }

    /* **************************************************************
    <addition> ::= <term> "+" <term> <continued_addition_or_subtraction>
    ************************************************************** */
    std::unique_ptr<ast::Addition> addition(const next_f& next, const restore_f& restore, kac_t& kac) {
        // we expects that the firt term has been parsed by the upstream process - expression().
        std::unique_ptr<ast::Term> lhs;
        if (kac.has_item<std::unique_ptr<ast::Term>>()) {
            lhs = kac.pop<std::unique_ptr<ast::Term>>();
        }
        else {
            lhs = term(next, restore, kac);
        }
        _expect(lhs);

        _expect(next(), TokenType::Plus);
        auto rhs = term(next, restore, kac);
        _expect(rhs);
        auto continued = continued_addition_or_subtraction(next, restore, kac);
        return _mk_uptr(ast::Addition{
            .lhs = std::move(lhs),
            .rhs = std::move(rhs),
            .continued = _choose(continued) ? _mk_opt(std::move(continued)) : std::nullopt });
    }

    /* **************************************************************
    <subtraction> ::= <term> "-" <term> <continued_addition_or_subtraction>
    ************************************************************** */
    std::unique_ptr<ast::Subtraction> subtraction(const next_f& next, const restore_f& restore, kac_t& kac) {
        // we expects that the firt term has been parsed by the upstream process - expression().
        std::unique_ptr<ast::Term> lhs;
        if (kac.has_item<std::unique_ptr<ast::Term>>()) {
            lhs = kac.pop<std::unique_ptr<ast::Term>>();
        }
        else {
            lhs = term(next, restore, kac);
        }
        _expect(lhs);

        _expect(next(), TokenType::Minus);
        auto rhs = term(next, restore, kac);
        _expect(rhs);
        auto continued = continued_addition_or_subtraction(next, restore, kac);
        return _mk_uptr(ast::Subtraction{
            .lhs = std::move(lhs),
            .rhs = std::move(rhs),
            .continued = _choose(continued) ? _mk_opt(std::move(continued)) : std::nullopt });
    }

    /* **************************************************************
    <continued_addition_or_subtraction> ::= "+" <term> <continued_addition_or_subtraction>
                                          | "-" <term> <continued_addition_or_subtraction>
                                          | <empty>
    ************************************************************** */
    std::unique_ptr<ast::ContinuedAdditionOrSubtraction> continued_addition_or_subtraction(const next_f& next, const restore_f& restore, kac_t& kac) {
        Token lat = next(); // look ahead token
        if (_choose(lat, TokenType::Plus)) { // "+"
            auto trm = term(next, restore, kac);
            _expect(trm);
            auto continued = continued_addition_or_subtraction(next, restore, kac);
            return _mk_uptr(ast::ContinuedAdditionOrSubtraction{
                .add_continued = _mk_otpl(std::move(trm), _choose(continued) ? _mk_opt(std::move(continued)) : std::nullopt),
                .is_empty = false });
        }
        else if (_choose(lat, TokenType::Minus)) { // "-"
            auto trm = term(next, restore, kac);
            _expect(trm);
            auto continued = continued_addition_or_subtraction(next, restore, kac);
            return _mk_uptr(ast::ContinuedAdditionOrSubtraction{
                .sub_continued = _mk_otpl(std::move(trm), _choose(continued) ? _mk_opt(std::move(continued)) : std::nullopt),
                .is_empty = false });
        }
        else { // empty
            restore(std::move(lat));
            return _mk_uptr(ast::ContinuedAdditionOrSubtraction{ .is_empty = true });
        }
    }

    /* **************************************************************
    <term> ::= <multiplication>
             | <division>
             | <factor>
    ************************************************************** */
    std::unique_ptr<ast::Term> term(const next_f& next, const restore_f& restore, kac_t& kac) {
        Token lat = next(); // look ahead token
        // choose which fork we need to go with.
        // attention: below implementation requires that:
        //    FIRST(factor) INTERSECTS FIRST(parenthesized) INTERSECTS FIRST(function) = empty
        if (_match_first<ast::Factor>(lat)) {
            // in this fork, there might be:
            //  - Multiplication/factor ...
            //  - Multiplication/MultiplicationSignOmitted/factor ...
            //  - Division/factor ...
            //  - factor
            restore(std::move(lat));
            auto fctr = factor(next, restore, kac);
            _expect(fctr);

            lat = next();
            if (_choose(lat, TokenType::Mult)) {
                // case - Multiplication/factor * factor ...
                restore(std::move(lat));
                kac.push(std::move(fctr));
                auto mul = multiplication(next, restore, kac);
                _expect(mul);
                return _mk_uptr(ast::Term{ .multiplication = std::move(mul) });
            }
            if (_choose(lat, TokenType::Divide)) {
                // case - Division/factor ...
                restore(std::move(lat));
                kac.push(std::move(fctr));
                auto div = division(next, restore, kac);
                _expect(div);
                return _mk_uptr(ast::Term{ .division = std::move(div) });
            }
            else if(_match_first<ast::Parenthesized>(lat)
                || _match_first<ast::Function>(lat))  {
                // case - Multiplication/MultiplicationSignOmitted/factor ...
                restore(std::move(lat));
                kac.push(std::move(fctr));
                auto mul = multiplication(next, restore, kac);
                _expect(mul);
                return _mk_uptr(ast::Term{ .multiplication = std::move(mul) });
            }
            else {
                // case - factor
                restore(std::move(lat));
                return _mk_uptr(ast::Term{ .factor = std::move(fctr) });
            }
        }
        else if (_match_first<ast::Parenthesized>(lat)
            || _match_first<ast::Function>(lat)) {
            // in this fork, there might be:
            //  - Multiplication/MultiplicationSignOmitted/parenthesized ...
            //  - Multiplication/MultiplicationSignOmitted/function ...
            restore(std::move(lat));
            auto mul = multiplication(next, restore, kac);
            _expect(mul);
            return _mk_uptr(ast::Term{ .multiplication = std::move(mul) });
        }
        throw ParserError();
    }

    /* **************************************************************
    <multiplication> ::= <factor> "*" <factor> <continued_multiplication_or_division>
                       | <multiplication_sign_omitted>
    ************************************************************** */
    std::unique_ptr<ast::Multiplication> multiplication(const next_f& next, const restore_f& restore, kac_t& kac) {
        if (kac.has_item<std::unique_ptr<ast::Factor>>()) {
            // we expects that the firt factor has been parsed by the upstream process - term().
            auto fctr = kac.pop<std::unique_ptr<ast::Factor>>();

            Token lat = next(); // look ahead token
            if (_choose(lat, TokenType::Mult)) {
                // case - factor * factor con
                auto rhs = factor(next, restore, kac);
                _expect(rhs);
                auto con = continued_multiplication_or_division(next, restore, kac);
                _expect(con);
                return _mk_uptr(ast::Multiplication{
                    .lhs = std::move(fctr),
                    .rhs = std::move(rhs),
                    .continued = std::move(con) });
            }
            else if (_match_first<ast::Parenthesized>(lat)
                || _match_first<ast::Function>(lat)) {
                restore(std::move(lat));
                kac.push(std::move(fctr));
                auto mso = multiplication_sign_omitted(next, restore, kac);
                _expect(mso);
                return _mk_uptr(ast::Multiplication{
                    .omitted = std::move(mso) });
            }
            throw ParserError();
        }
        else {
            // Multiplication/MultiplicationSignOmitted/parenthesized ...
            // Multiplication/MultiplicationSignOmitted/function ...
            auto mso = multiplication_sign_omitted(next, restore, kac);
            _expect(mso);
            return _mk_uptr(ast::Multiplication{
                .omitted = std::move(mso) });
        }
    }

    /* **************************************************************
    <division> ::= <dividend> "/" <divisor> <continued_multiplication_or_division>
      =>
    <division> ::= <factor> "/" <factor> <continued_multiplication_or_division>
    ************************************************************** */
    std::unique_ptr<ast::Division> division(const next_f& next, const restore_f& restore, kac_t& kac) {
        // we expects that the firt term has been parsed by the upstream process - term().
        _expect(kac.has_item<std::unique_ptr<ast::Factor>>());
        auto lhs = kac.pop<std::unique_ptr<ast::Factor>>();
        auto div_token = next();
        _expect(div_token, TokenType::Divide);
        auto rhs = factor(next, restore, kac);
        auto con = continued_multiplication_or_division(next, restore, kac);
        return _mk_uptr(ast::Division{
            .lhs = std::move(lhs),
            .rhs = std::move(rhs),
            .continued = std::move(con) });
    }

    /* **************************************************************
    multiplication_sign_omitted ::=
          <factor> <parenthesized> <continued_multiplication_or_division>
        | <factor> <function> <continued_multiplication_or_division>
        | <parenthesized> <parenthesized> <continued_multiplication_or_division>
	    | <parenthesized> <function> <continued_multiplication_or_division>
        | <function> <function> <continued_multiplication_or_division>
        | <function> <parenthesized> <continued_multiplication_or_division>
    ************************************************************** */
    std::unique_ptr<ast::MultiplicationSignOmitted> multiplication_sign_omitted(const next_f& next, const restore_f& restore, kac_t& kac) {
        if (kac.has_item<std::unique_ptr<ast::Factor>>()) {
            // we expects that the firt factor has been parsed by the upstream process - multiplication().
            auto lhs = kac.pop<std::unique_ptr<ast::Factor>>();
            _expect(lhs);
            Token lat = next(); // look ahead token
            if (_match_first<ast::Parenthesized>(lat)) {
                // factor parenthesized con
                restore(std::move(lat));
                auto rhs = parenthesized(next, restore, kac);
                _expect(rhs);
                auto con = continued_multiplication_or_division(next, restore, kac);
                return _mk_uptr(ast::MultiplicationSignOmitted{
                    .factor_parenthesized = _mk_otpl(std::move(lhs), std::move(rhs), std::move(con)) });
            }
            else if (_match_first<ast::Function>(lat)) {
                // factor function con
                restore(std::move(lat));
                auto rhs = function(next, restore, kac);
                _expect(rhs);
                auto con = continued_multiplication_or_division(next, restore, kac);
                return _mk_uptr(ast::MultiplicationSignOmitted{
                    .factor_function = _mk_otpl(std::move(lhs), std::move(rhs), std::move(con)) });
            }
            throw ParserError();
        }
        else {
            // Multiplication/MultiplicationSignOmitted/parenthesized ...
            // Multiplication/MultiplicationSignOmitted/function ...
            Token lat = next(); // look ahead token
            if (_match_first<ast::Parenthesized>(lat)) {
                // parenthesized ...
                restore(std::move(lat));
                auto lhs = parenthesized(next, restore, kac);
                _expect(lhs);
                lat = next();
                if (_match_first<ast::Parenthesized>(lat)) {
                    // parenthesized parenthesized 
                    restore(std::move(lat));
                    auto rhs = parenthesized(next, restore, kac);
                    _expect(rhs);
                    auto con = continued_multiplication_or_division(next, restore, kac);
                    _expect(con);
                    return _mk_uptr(ast::MultiplicationSignOmitted{
                        .parenthesized_parenthesized = _mk_otpl(std::move(lhs), std::move(rhs), std::move(con)) });
                }
                else if (_match_first<ast::Function>(lat)) {
                    // parenthesized function 
                    restore(std::move(lat));
                    auto rhs = function(next, restore, kac);
                    _expect(rhs);
                    auto con = continued_multiplication_or_division(next, restore, kac);
                    _expect(con);
                    return _mk_uptr(ast::MultiplicationSignOmitted{
                        .parenthesized_function = _mk_otpl(std::move(lhs), std::move(rhs), std::move(con)) });
                }
            }
            else if (_match_first<ast::Function>(lat)) {
                // function ...
                restore(std::move(lat));
                auto lhs = function(next, restore, kac);
                _expect(lhs);
                lat = next();
                if (_match_first<ast::Function>(lat)) {
                    // function function
                    restore(std::move(lat));
                    auto rhs = function(next, restore, kac);
                    _expect(rhs);
                    auto con = continued_multiplication_or_division(next, restore, kac);
                    _expect(con);
                    return _mk_uptr(ast::MultiplicationSignOmitted{
                        .function_function = _mk_otpl(std::move(lhs), std::move(rhs), std::move(con)) });
                }
                else if (_match_first<ast::Parenthesized>(lat)) {
                    // function parenthesized 
                    restore(std::move(lat));
                    auto rhs = parenthesized(next, restore, kac);
                    _expect(rhs);
                    auto con = continued_multiplication_or_division(next, restore, kac);
                    _expect(con);
                    return _mk_uptr(ast::MultiplicationSignOmitted{
                        .function_parenthesized = _mk_otpl(std::move(lhs), std::move(rhs), std::move(con)) });
                }
            }
            throw ParserError();
        }
    }

    /* **************************************************************
    <continued_multiplication_or_division> ::=
          "*" <factor> <continued_multiplication_or_division>
        | "/" <divisor> <continued_multiplication_or_division>
        | <continued_multiplication_sign_omitted>
        | <empty>
    ************************************************************** */
    std::unique_ptr<ast::ContinuedMultiplicationOrDivision> continued_multiplication_or_division(const next_f& next, const restore_f& restore, kac_t& kac) {
        Token lat = next(); // look ahead token
        if (_choose(lat, TokenType::Mult)) {
            // "*" <factor> <continued_multiplication_or_division>
            auto fctr = factor(next, restore, kac);
            _expect(fctr);
            auto con = continued_multiplication_or_division(next, restore, kac);
            _expect(con);
            return _mk_uptr(ast::ContinuedMultiplicationOrDivision{
                .mul_continued = _mk_otpl(std::move(fctr), std::move(con)),
                .is_empty = false });
        }
        else if (_choose(lat, TokenType::Divide)) {
            // "/" <divisor> <continued_multiplication_or_division>
            auto fctr = factor(next, restore, kac);
            _expect(fctr);
            auto con = continued_multiplication_or_division(next, restore, kac);
            _expect(con);
            return _mk_uptr(ast::ContinuedMultiplicationOrDivision{
                .div_continued = _mk_otpl(std::move(fctr), std::move(con)),
                .is_empty = false });
        }
        else if (_match_first<ast::ContinuedMultiplicationSignOmitted>(lat)) {
            // <continued_multiplication_sign_omitted>
            restore(std::move(lat));
            auto con = continued_multiplication_sign_omitted(next, restore, kac);
            _expect(con);
            return _mk_uptr(ast::ContinuedMultiplicationOrDivision{
                .mo_continued = std::move(con),
                .is_empty = false });
        }
        else {
            // empty
            restore(std::move(lat));
            return _mk_uptr(ast::ContinuedMultiplicationOrDivision{ .is_empty = true });
        }
    }

    /* **************************************************************
    <continued_multiplication_sign_omitted> ::=
        | <parenthesized> <continued_multiplication_or_division>
        | <function> <continued_multiplication_or_division>
    ************************************************************** */
    std::unique_ptr<ast::ContinuedMultiplicationSignOmitted> continued_multiplication_sign_omitted(const next_f& next, const restore_f& restore, kac_t& kac) {
        Token lat = next(); // look ahead token
        if (_match_first<ast::Parenthesized>(lat)) {
            restore(std::move(lat));
            auto p = parenthesized(next, restore, kac);
            _expect(p);
            auto con = continued_multiplication_or_division(next, restore, kac);
            _expect(con);
            return _mk_uptr(ast::ContinuedMultiplicationSignOmitted{
                .parenthesized_continued = _mk_otpl(std::move(p), std::move(con)) });
        }
        else if (_match_first<ast::Function>(lat)) {
            restore(std::move(lat));
            auto f = function(next, restore, kac);
            _expect(f);
            auto con = continued_multiplication_or_division(next, restore, kac);
            _expect(con);
            return _mk_uptr(ast::ContinuedMultiplicationSignOmitted{
                .function_continued = _mk_otpl(std::move(f), std::move(con)) });
        }
        throw ParserError();
    }

    /* **************************************************************
    <factor> ::= <postfix_unary_expression>
               | <exponentiation>
               | <atom>
    ************************************************************** */
    std::unique_ptr<ast::Factor> factor(const next_f& next, const restore_f& restore, kac_t& kac) {
        // to avoid backtracking, we need to decide which fork we have choose
        // so, we can parse the common syntax part - a **atom** - and then check the operator
        // if the operator is "^", then the next selection must be postfix_unary_expression or exponentiation 
        // if the operator is <postfix_unary_operator>, then the next selection must be postfix_expression 
        // otherwise, the next selection is atom it self
        auto a = atom(next, restore, kac);
        Token lat = next(); // look ahead token
        if (_choose(lat, TokenType::Caret)) {
            // exponentiation or postfix_unary_expression
            restore(std::move(lat));
            kac.push(std::move(a));
            auto e = exponentiation(next, restore, kac);
            _expect(e);
            lat = next(); // look ahead token
            if (_choose(lat, TokenType::Factorial) ||
                _choose(lat, TokenType::Percent)) {
                // postfix_unary_expression
                restore(std::move(lat));
                kac.push(std::move(e));
                auto postfix_expr = postfix_unary_expression(next, restore, kac);
                _expect(postfix_expr);
                return _mk_uptr(ast::Factor{ .postfix_unary_expression = std::move(postfix_expr) });
            }
            else {
                // exponentiation
                restore(std::move(lat));
                return _mk_uptr(ast::Factor{ .exponentiation = std::move(e) });
            }
        }
        else if (_choose(lat, TokenType::Factorial) ||
            _choose(lat, TokenType::Percent)) {
            // postfix_unary_expression
            restore(std::move(lat));
            kac.push(std::move(a));
            auto postfix_expr = postfix_unary_expression(next, restore, kac);
            _expect(postfix_expr);
            return _mk_uptr(ast::Factor{ .postfix_unary_expression = std::move(postfix_expr) });
        }
        else {
            // atom
            restore(std::move(lat));
            return _mk_uptr(ast::Factor{ .atom = std::move(a) });
        }
    }


    /* **************************************************************
    <postfix_unary_expression> ::= <exponentiation> <postfix_unary_operator>
                                 | <atom> <postfix_unary_operator>
    ************************************************************** */
    std::unique_ptr<ast::PostfixUnaryExpression> postfix_unary_expression(const next_f& next, const restore_f& restore, kac_t& kac) {
        if (kac.has_item<std::unique_ptr<ast::Atom>>()) {
            auto a = kac.pop<std::unique_ptr<ast::Atom>>();
            if (kac.has_item<std::unique_ptr<ast::Exponentiation>>()) {
                auto e = kac.pop<std::unique_ptr<ast::Exponentiation>>();
                Token operator_token = next();
                if (_choose(operator_token, TokenType::Factorial)
                    || _choose(operator_token, TokenType::Percent)) {
                    return _mk_uptr(ast::PostfixUnaryExpression{
                        .power = _mk_otpl(std::move(e), std::move(operator_token)) });
                }
                throw ParserError();
            }
            Token operator_token = next();
            if (_choose(operator_token, TokenType::Factorial)
                || _choose(operator_token, TokenType::Percent)) {
                return _mk_uptr(ast::PostfixUnaryExpression{
                    .atom_operator = _mk_otpl(std::move(a), std::move(operator_token)) });
            }
            throw ParserError();
        }
        else {
            auto a = atom(next, restore, kac);
            _expect(a);
            Token lat = next(); // look ahead token
            if (_choose(lat, TokenType::Caret)) {
                // exponentiation
                kac.push(std::move(a));
                restore(std::move(lat));
                auto e = exponentiation(next, restore, kac);
                _expect(e);
                Token operator_token = next();
                if (_choose(operator_token, TokenType::Factorial)
                    || _choose(operator_token, TokenType::Percent)) {
                    return _mk_uptr(ast::PostfixUnaryExpression{
                        .power = _mk_otpl(std::move(e), std::move(operator_token)) });
                }
            }
            else {
                if (_choose(lat, TokenType::Factorial)
                    || _choose(lat, TokenType::Percent)) {
                    return _mk_uptr(ast::PostfixUnaryExpression{
                        .atom_operator = _mk_otpl(std::move(a), std::move(lat)) });
                }
            }
            throw ParserError();
        }
    }

    /* **************************************************************
    <exponentiation> ::= <atom> "^" <atom>
    ************************************************************** */
    std::unique_ptr<ast::Exponentiation> exponentiation(const next_f& next, const restore_f& restore, kac_t& kac) {
        std::unique_ptr<ast::Atom> lhs;
        if (kac.has_item<std::unique_ptr<ast::Atom>>()){
            lhs = kac.pop<std::unique_ptr<ast::Atom>>();
        }
        else {
            lhs = atom(next, restore, kac);
        }
        _expect(lhs);
        Token caret = next();
        _expect(caret, TokenType::Caret);
        auto rhs = atom(next, restore, kac);
        _expect(rhs);
        auto con = continued_exponentiation(next, restore, kac);
        _expect(con);
        return _mk_uptr(ast::Exponentiation{
            .base = std::move(lhs),
            .exponent = std::move(rhs),
            .continued = std::move(con) });
    }

    /* **************************************************************
    <continued_exponentiation> ::= "^" <atom>
                                 | <empty>
    ************************************************************** */
    std::unique_ptr<ast::ContinuedExponentiation> continued_exponentiation(const next_f& next, const restore_f& restore, kac_t& kac) {
        Token lat = next(); // look ahead token
        if (_choose(lat, TokenType::Caret)) {
            auto a = atom(next, restore, kac);
            _expect(a);
            auto con = continued_exponentiation(next, restore, kac);
            _expect(con);
            return _mk_uptr(ast::ContinuedExponentiation{
                .exponent = std::move(a),
                .continued = std::move(con),
                .is_empty = false });
        }
        else {
            // empty
            restore(std::move(lat));
            return _mk_uptr(ast::ContinuedExponentiation{ .is_empty = true });
        }
    }

    /* **************************************************************
    <atom> ::= <parenthesized>
             | <prefix_unary_expression>
             | <function>
             | <number>
    ************************************************************** */
    std::unique_ptr<ast::Atom> atom(const next_f& next, const restore_f& restore, kac_t& kac) {
        Token lat = next(); // look ahead token
        if (_match_first<ast::Parenthesized>(lat)) {
            restore(std::move(lat));
            auto p = parenthesized(next, restore, kac);
            _expect(p);
            return _mk_uptr(ast::Atom{ .parenthesized = std::move(p) });
        }
        else if (_match_first<ast::PrefixUnaryExpression>(lat)) {
            restore(std::move(lat));
            auto p = prefix_unary_expression(next, restore, kac);
            _expect(p);
            return _mk_uptr(ast::Atom{ .prefix_unary_expression = std::move(p) });
        }
        else if (_match_first<ast::Function>(lat)) {
            restore(std::move(lat));
            auto func = function(next, restore, kac);
            return _mk_uptr(ast::Atom{ .function = std::move(func) });
        }
        else if (is_num_token(lat)) {
            return _mk_uptr(ast::Atom{ .number = std::move(lat) });
        }
        throw ParserError();
    }

    /* **************************************************************
    <parenthesized> ::= "(" expression ")"
    ************************************************************** */
    std::unique_ptr<ast::Parenthesized> parenthesized(const next_f& next, const restore_f& restore, kac_t& kac) {
        Token leftp_token = next();
        _expect(leftp_token, TokenType::LeftParenthesis);
        auto expr = expression(next, restore, kac);
        _expect(expr);
        Token right_token = next();
        _expect(right_token, TokenType::RightParenthesis);
        return _mk_uptr(ast::Parenthesized{ .expression = std::move(expr) });
    }

    /* **************************************************************
    <prefix_unary_expression> ::= "+" <atom>
                                | "-" <atom>
    ************************************************************** */
    std::unique_ptr<ast::PrefixUnaryExpression> prefix_unary_expression(const next_f& next, const restore_f& restore, kac_t& kac) {
        Token unary_opt_token = next();
        if (_choose(unary_opt_token, TokenType::Plus)) {
            auto at = atom(next, restore, kac);
            _expect(at);
            return _mk_uptr(ast::PrefixUnaryExpression{ .plus_atom = std::move(at) });
        }
        else if (_choose(unary_opt_token, TokenType::Minus)) {
            auto at = atom(next, restore, kac);
            _expect(at);
            return _mk_uptr(ast::PrefixUnaryExpression{ .minus_atom = std::move(at) });
        }
        throw ParserError();
    }

    /* **************************************************************
    <function> ::= <Identifier> "(" <parameter_list> ")"
    ************************************************************** */
    std::unique_ptr<ast::Function> function(const next_f& next, const restore_f& restore, kac_t& kac) {
        Token id_token = next();
        _expect(id_token, TokenType::Identifier);
        Token leftp_token = next();
        _expect(leftp_token, TokenType::LeftParenthesis);

        // check the right parenthesis proactively to make the descent deterministic.
        Token lat = next(); // look ahead token
        if (_choose(lat, TokenType::RightParenthesis)) {
            // parameter list is empty
            return _mk_uptr(ast::Function{
                .identifier = std::move(id_token),
                .paramlist = _mk_uptr(ast::ParameterList{.is_empty = true}) });
        }
        else {
            restore(std::move(lat)); // put it back
            // there must be a parameter list
            auto plist = parameter_list(next, restore, kac);
            _expect(plist);
            auto retval = _mk_uptr(ast::Function{
                .identifier = std::move(id_token),
                .paramlist = std::move(plist) });
            Token rightp_token = next();
            _expect(rightp_token, TokenType::RightParenthesis);
            return retval;
        }
    }

    /* **************************************************************
    <parameter_list> ::= <expression> <continued_parameter_list>
                       | <empty>
    ************************************************************** */
    std::unique_ptr<ast::ParameterList> parameter_list(const next_f& next, const restore_f& restore, kac_t& kac) {
        // the parent parsing phase shoud ensure it does have parameter list
        // in this phase, we don't handle the empty case since it costs too much.
        auto expr = expression(next, restore, kac);
        _expect(expr);
        auto con = continued_parameter_list(next, restore, kac);
        _expect(con);
        return _mk_uptr(ast::ParameterList{
            .expression = std::move(expr),
            .continued = std::move(con),
            .is_empty = false });
    }

    /* **************************************************************
    <continued_parameter_list> ::= "," <expression> <continued_parameter_list>
                                 | <empty>
    ************************************************************** */
    std::unique_ptr<ast::ContinuedParameterList> continued_parameter_list(const next_f& next, const restore_f& restore, kac_t& kac) {
        Token lat = next(); // look ahead token
        if (_choose(lat, TokenType::Comma)) {
            auto expr = expression(next, restore, kac);
            _expect(expr);
            auto con = continued_parameter_list(next, restore, kac);
            _expect(con);
            return _mk_uptr(ast::ContinuedParameterList{
                .expression = std::move(expr),
                .continued = std::move(con),
                .is_empty = false });
        }
        else {
            restore(std::move(lat));
            return _mk_uptr(ast::ContinuedParameterList{.is_empty = true});
        }
    }

    constexpr bool is_num_token(const Token& t) {
        return t.token_type == TokenType::DecimalInteger
            || t.token_type == TokenType::DecimalFloat
            || t.token_type == TokenType::DecimalScientificNumber
            || t.token_type == TokenType::HexadecimalInteger
            || t.token_type == TokenType::OctalInteger
            || t.token_type == TokenType::BinaryInteger;
    }

    bool is_identifier_token(const Token& t) {
        return t.token_type == TokenType::Identifier;
    }

    bool is_pre_unary_token(const Token& t) {
        return t.token_type == TokenType::Plus
            || t.token_type == TokenType::Minus;
    }

    bool is_post_unary_token(const Token& t) {
        return t.token_type == TokenType::Percent
            || t.token_type == TokenType::Factorial;
    }

    bool is_non_token(const Token& t) {
        return t.token_type == TokenType::None;
    }
    
    bool is_eoe_token(const Token& t) {
        return t.token_type == TokenType::EOE;
    }

    bool is_binary_operator_token(const Token& t) {
        return t.token_type == TokenType::Plus
            || t.token_type == TokenType::Minus
            || t.token_type == TokenType::Mult
            || t.token_type == TokenType::Divide
            || t.token_type == TokenType::Mod
            || t.token_type == TokenType::Equals
            || t.token_type == TokenType::Caret;
    }

    bool is_leftparen_token(const Token& t) {
        return t.token_type == TokenType::LeftParenthesis;
    }

    bool is_rightparen_token(const Token& t) {
        return t.token_type == TokenType::RightParenthesis;
    }
}



