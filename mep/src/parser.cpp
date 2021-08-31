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
        return std::make_optional<std::make_tuple<_Ts...>>(std::forward<_Ts>(elements)...);
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

    /* **************************************************************
    <expression> ::= <addition>
                   | <subtraction>
                   | <term>
    ************************************************************** */
    std::unique_ptr<ast::Expression> expression(const next_f& next, const restore_f& restore){
        auto add = addition(next, restore);
        if (_choose(add)) {
            return _mk_uptr(ast::Expression{ .addition = _mk_opt(std::move(add)) });
        }
        auto sub = subtraction(next, restore);
        if (_choose(sub)) {
            return _mk_uptr(ast::Expression{ .subtraction = _mk_opt(std::move(sub)) });
        }
        auto trm = term(next, restore);
        if (_choose(trm)) {
            return _mk_uptr(ast::Expression{ .term = _mk_opt(std::move(trm)) });
        }
        throw ParserError();
    }

    /* **************************************************************
    <addition> ::= <term> "+" <term> <continued_addition_or_subtraction>
    ************************************************************** */
    std::unique_ptr<ast::Addition> addition(const next_f& next, const restore_f& restore) {
        auto lhs = term(next, restore);
        _expect(lhs);
        _expect(next(), TokenType::Plus);
        auto rhs = term(next, restore);
        _expect(rhs);
        auto continued = continued_addition_or_subtraction(next, restore);
        return _mk_uptr(ast::Addition{
            .lhs = std::move(lhs),
            .rhs = std::move(rhs),
            .continued = _choose(continued) ? _mk_opt(std::move(continued)) : std::nullopt });
    }


    /* **************************************************************
    <subtraction> ::= <term> "-" <term> <continued_addition_or_subtraction>
    ************************************************************** */
    std::unique_ptr<ast::Subtraction> subtraction(const next_f& next, const restore_f& restore) {
        auto lhs = term(next, restore);
        _expect(lhs);
        _expect(next(), TokenType::Minus);
        auto rhs = term(next, restore);
        _expect(rhs);
        auto continued = continued_addition_or_subtraction(next, restore);
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
    std::unique_ptr<ast::ContinuedAdditionOrSubtraction> continued_addition_or_subtraction(const next_f& next, const restore_f& restore) {
        Token lat = next(); // look ahead token
        if (_choose(lat, TokenType::Plus)) { // "+"
            auto trm = term(next, restore);
            _expect(trm);
            auto continued = continued_addition_or_subtraction(next, restore);
            return _mk_uptr(ast::ContinuedAdditionOrSubtraction{
                .add_continued = _mk_otpl(std::move(trm), _choose(continued) ? _mk_opt(std::move(continued)) : std::nullopt),
                .is_empty = false });
        }
        else if (_choose(lat, TokenType::Minus)) { // "-"
            auto trm = term(next, restore);
            _expect(trm);
            auto continued = continued_addition_or_subtraction(next, restore);
            return _mk_uptr(ast::ContinuedAdditionOrSubtraction{
                .sub_continued = _mk_otpl(std::move(trm), _choose(continued) ? _mk_opt(std::move(continued)) : std::nullopt),
                .is_empty = false });
        }
        else if (_choose(lat, TokenType::EOE)) { // empty
            return _mk_uptr(ast::ContinuedAdditionOrSubtraction{ .is_empty = true });
        }
        else {
            throw ParserError();
        }
    }

    std::unique_ptr<ast::Term> term(const next_f& next, const restore_f& restore);

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



