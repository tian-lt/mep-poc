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
    void _expect(const std::unique_ptr<_T>& t) {
        if (t == nullptr) {
            throw ParserError();
        }
    }

    void _expect(const Token& t, const TokenType& ty) {
        if (t.token_type != ty) {
            throw ParserError();
        }
    }

    template<class _T>
    constexpr bool _match_first(const Token& t);

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

    /* **************************************************************
    <expression> ::= <addition>
                   | <subtraction>
                   | <term>
    ************************************************************** */
    std::unique_ptr<ast::Expression> expression(const next_f& next, const restore_f& restore, kac_t& kac){
        auto lan = term(next, restore, kac); // look ahead node
        _expect(lan);
        kac.push(std::move(lan));
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
        else if(_choose(lat, TokenType::EOE)) { // end of expression
            restore(std::move(lat));
            auto trm = term(next, restore, kac);
            _expect(trm);
            return _mk_uptr(ast::Expression{ .term = std::move(trm) });
        }
        throw ParserError();
    }

    /* **************************************************************
    <addition> ::= <term> "+" <term> <continued_addition_or_subtraction>
    ************************************************************** */
    //std::unique_ptr<ast::Addition> addition(const next_f& next, const restore_f& restore) {
    //    auto lhs = term(next, restore);
    //    _expect(lhs);
    //    _expect(next(), TokenType::Plus);
    //    auto rhs = term(next, restore);
    //    _expect(rhs);
    //    auto continued = continued_addition_or_subtraction(next, restore);
    //    return _mk_uptr(ast::Addition{
    //        .lhs = std::move(lhs),
    //        .rhs = std::move(rhs),
    //        .continued = _choose(continued) ? _mk_opt(std::move(continued)) : std::nullopt });
    //}


    /* **************************************************************
    <subtraction> ::= <term> "-" <term> <continued_addition_or_subtraction>
    ************************************************************** */
    //std::unique_ptr<ast::Subtraction> subtraction(const next_f& next, const restore_f& restore) {
    //    auto lhs = term(next, restore);
    //    _expect(lhs);
    //    _expect(next(), TokenType::Minus);
    //    auto rhs = term(next, restore);
    //    _expect(rhs);
    //    auto continued = continued_addition_or_subtraction(next, restore);
    //    return _mk_uptr(ast::Subtraction{
    //        .lhs = std::move(lhs),
    //        .rhs = std::move(rhs),
    //        .continued = _choose(continued) ? _mk_opt(std::move(continued)) : std::nullopt });
    //}

    /* **************************************************************
    <continued_addition_or_subtraction> ::= "+" <term> <continued_addition_or_subtraction>
                                          | "-" <term> <continued_addition_or_subtraction>
                                          | <empty>
    ************************************************************** */
    //std::unique_ptr<ast::ContinuedAdditionOrSubtraction> continued_addition_or_subtraction(const next_f& next, const restore_f& restore) {
    //    Token lat = next(); // look ahead token
    //    if (_choose(lat, TokenType::Plus)) { // "+"
    //        auto trm = term(next, restore);
    //        _expect(trm);
    //        auto continued = continued_addition_or_subtraction(next, restore);
    //        return _mk_uptr(ast::ContinuedAdditionOrSubtraction{
    //            .add_continued = _mk_otpl(std::move(trm), _choose(continued) ? _mk_opt(std::move(continued)) : std::nullopt),
    //            .is_empty = false });
    //    }
    //    else if (_choose(lat, TokenType::Minus)) { // "-"
    //        auto trm = term(next, restore);
    //        _expect(trm);
    //        auto continued = continued_addition_or_subtraction(next, restore);
    //        return _mk_uptr(ast::ContinuedAdditionOrSubtraction{
    //            .sub_continued = _mk_otpl(std::move(trm), _choose(continued) ? _mk_opt(std::move(continued)) : std::nullopt),
    //            .is_empty = false });
    //    }
    //    else if (_choose(lat, TokenType::EOE)) { // empty
    //        restore(std::move(lat));
    //        return _mk_uptr(ast::ContinuedAdditionOrSubtraction{ .is_empty = true });
    //    }
    //    else {
    //        throw ParserError();
    //    }
    //}

    /* **************************************************************
    <term> ::= <multiplication>
             | <division>
             | <factor>
    ************************************************************** */
    //std::unique_ptr<ast::Term> term(const next_f& next, const restore_f& restore) {
        //auto mul = multiplication(next, restore);
        //if (_choose(mul)) {
        //    return _mk_uptr(ast::Term{ .multiplication = _mk_opt(std::move(mul)) });
        //}
        //auto div = division(next, restore);
        //if (_choose(div)) {
        //    return _mk_uptr(ast::Term{ .division = _mk_opt(std::move(div)) });
        //}
        //auto ft = factor(next, restore);
        //if (_choose(ft)) {
        //    return _mk_uptr(ast::Term{ .factor = _mk_opt(std::move(ft)) });
        //}
    //    throw ParserError();
    //}


    /* **************************************************************
    <multiplication> ::= <factor> "*" <factor> <continued_multiplication_or_division>
                       | <multiplication_sign_omitted>
    ************************************************************** */
    //std::unique_ptr<ast::Multiplication> multiplication(const next_f& next, const restore_f& restore, kac_t& kac);

    /* **************************************************************
    ************************************************************** */
    //std::unique_ptr<ast::Division> division(const next_f& next, const restore_f& restore, kac_t& kac) {

    //}

    /* **************************************************************
    <factor> ::= <postfix_unary_expression>
               | <exponentiation>
               | <atom>
    ************************************************************** */
    std::unique_ptr<ast::Factor> factor(const next_f& next, const restore_f& restore, kac_t& kac) {
        Token lat = next(); // look ahead token
        if (_match_first<ast::PostfixUnaryExpression>(lat)) {
            restore(std::move(lat));
            auto p = postfix_unary_expression(next, restore, kac);
            _expect(p);
            return _mk_uptr(ast::Factor{ .postfix_unary_expression = std::move(p) });
        }
        else if (_match_first<ast::Exponentiation>(lat)) {
            restore(std::move(lat));
            auto e = exponentiation(next, restore, kac);
            _expect(e);
            return _mk_uptr(ast::Factor{ .exponentiation = std::move(e) });
        }
        else if (_match_first<ast::Atom>(lat)) {
            restore(std::move(lat));
            auto a = atom(next, restore, kac);
            _expect(a);
            return _mk_uptr(ast::Factor{ .atom = std::move(a) });
        }
        throw ParserError();
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
                .continued = std::move(con)});
        }
        else {
            restore(std::move(lat));
            return _mk_uptr(ast::ContinuedParameterList{.is_empty = true});
        }
    }

    bool is_num_token(const Token& t) {
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



