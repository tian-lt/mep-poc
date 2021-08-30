#include "parser.hpp"

namespace mep::details {
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



