#include "parser.hpp"

namespace mep::details {
    ast::expr_s expr(const next_f& next) {
        return ast::expr_s{
            .end_term = std::make_unique<ast::end_term_s>(end_term(next)),
            .expr_tail = std::make_unique<ast::expr_tail_s>(expr_tail(next))
        };
    }

    ast::num_s num(const Token& lat, const next_f& next) {
        Token t = is_non_token(lat) ? next() : lat;
        if (!is_num_token(t)) {
            throw ParserError();
        }
        return ast::num_s{ .token = t };
    }

    ast::func_s func(const Token& lat, const next_f& next) {
        Token t = is_non_token(lat) ? next() : lat;
        if (!is_identifier_token(t)) {
            throw ParserError();
        }
        return ast::func_s{
            .identifier = t,
            .expr = std::move(std::make_unique<ast::expr_s>(expr(next)))
        };
    }

    ast::pre_unary_operator_s pre_unary_operator(const Token& lat, const next_f& next) {
        Token t = is_non_token(lat) ? next() : lat;
        if (!is_pre_unary_token(t)) {
            throw ParserError();
        }
        return ast::pre_unary_operator_s{ .token = t };
    }

    ast::post_unary_operator_s post_unary_operator(const Token& lat, const next_f& next) {
        Token t = is_non_token(lat)? next() : lat;
        if (!is_post_unary_token(t)) {
            throw ParserError();
        }
        return ast::post_unary_operator_s{ .token = t };
    }

    ast::end_term_tail_s end_term_tail(const next_f& next) {
        Token lat = next();
        if (is_post_unary_token(lat)) {
            ast::end_term_tail_s retval(false);
            retval.post_unary_operator = std::make_unique<ast::post_unary_operator_s>(post_unary_operator(lat, next));
            retval.end_term_tail = std::make_unique<ast::end_term_tail_s>(end_term_tail(next));
            return retval;
        }
        else if (is_eoe_token(lat)) {
            return ast::end_term_tail_s(true);
        }
        else {
            throw ParserError();
        }
    }

    ast::end_term_s end_term(const next_f& next) {
        Token lat = next();
        ast::end_term_s retval;
        if (is_pre_unary_token(lat)) { // o0: <pre_unary_operator> <end_term>
            using o0_t = ast::end_term_s::options_s::o0_s;
            std::get<o0_t>(retval.options.payload) = end_term_o0(lat, next);
            retval.opid = 0; // o0
        }
        else if (is_leftparen_token(lat)) { // o1: <LEFT_PAREN> <expr> <RIGHT_PAREN>
            using o1_t = ast::end_term_s::options_s::o1_s;
            std::get<o1_t>(retval.options.payload) = end_term_o1(lat, next);
            retval.opid = 1; // o1
        }
        else if (is_identifier_token(lat)) { // o2: <func>
            using o2_t = ast::end_term_s::options_s::o2_s;
            std::get<o2_t>(retval.options.payload) = end_term_o2(lat, next);
            retval.opid = 2;
        }
        else if (is_num_token(lat)) { // o3: <num>
            using o3_t = ast::end_term_s::options_s::o3_s;
            std::get<o3_t>(retval.options.payload) = end_term_o3(lat, next);
            retval.opid = 3;
        }
        retval.end_term_tail = std::make_unique<ast::end_term_tail_s>(end_term_tail(next));
        return retval;
    }

    ast::expr_tail_s expr_tail(const next_f& next) {
        Token lat = next();
        ast::expr_tail_s retval;
        if (is_binary_operator_token(lat)) {
            retval.is_empty = false;
            retval.binary_operator = std::make_unique<ast::binary_operator_s>(binary_operator(lat, next));
            retval.expr = std::make_unique<ast::expr_s>(expr(next));
            retval.expr_tail = std::make_unique<ast::expr_tail_s>(expr_tail(next));
        }
        else if (is_eoe_token(lat)) {
            retval.is_empty = true;
        }
        return retval;
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
}



