#include "parser.hpp"

namespace mep::details {
    ast::expr_s expr(const next_f& next, Token& lat_back) {
        Token latback;
        auto&& endterm = end_term(next, latback);
        if (!is_non_token(latback) && !is_eoe_token(latback)) {
            auto&& exprtail = expr_tail(latback, next, latback);
            return ast::expr_s{
                .end_term = std::make_unique<ast::end_term_s>(std::move(endterm)),
                .expr_tail = std::make_unique<ast::expr_tail_s>(std::move(exprtail))
            };
        }
        else {
            lat_back = latback;
            return ast::expr_s{.is_empty = true};
        }
        throw ParserError();
    }

    ast::num_s num(const Token& lat, const next_f& next) {
        Token t = is_non_token(lat) ? next() : lat;
        if (!is_num_token(t)) {
            throw ParserError();
        }
        return ast::num_s{ .token = t };
    }

    ast::func_s func(const Token& lat, const next_f& next, Token& lat_back) {
        Token t = is_non_token(lat) ? next() : lat;
        if (!is_identifier_token(t)) {
            throw ParserError();
        }
        return ast::func_s{
            .identifier = t,
            .expr = std::move(std::make_unique<ast::expr_s>(expr(next, lat_back)))
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

    ast::binary_operator_s binary_operator(const Token& lat, const next_f& next) {
        Token t = is_non_token(lat) ? next() : lat;
        if (is_binary_operator_token(t)) {
            return ast::binary_operator_s{.token = t};
        }
        throw ParserError();
    }

    ast::end_term_tail_s end_term_tail(const next_f& next, Token& lat_back) {
        Token t = next();
        if (is_post_unary_token(t)) {
            ast::end_term_tail_s retval(false); // not empty
            retval.post_unary_operator = std::make_unique<ast::post_unary_operator_s>(post_unary_operator(t, next));
            retval.end_term_tail = std::make_unique<ast::end_term_tail_s>(end_term_tail(next, lat_back));
            return retval;
        }
        else {
            lat_back = t;
            return ast::end_term_tail_s(true); // empty
        }
    }

    ast::end_term_s end_term(const next_f& next, Token& lat_back) {
        Token t = next();
        ast::end_term_s retval;
        if (is_pre_unary_token(t)) { // o0: <pre_unary_operator> <end_term>
            using o0_t = ast::end_term_s::options_s::o0_s;
            retval.options.payload.emplace<o0_t>(end_term_o0(t, next, lat_back));
            retval.opid = 0; // o0
        }
        else if (is_leftparen_token(t)) { // o1: <LEFT_PAREN> <expr> <RIGHT_PAREN>
            using o1_t = ast::end_term_s::options_s::o1_s;
            retval.options.payload.emplace<o1_t>(end_term_o1(t, next, lat_back));
            retval.opid = 1; // o1
        }
        else if (is_identifier_token(t)) { // o2: <func>
            using o2_t = ast::end_term_s::options_s::o2_s;
            retval.options.payload.emplace<o2_t>(end_term_o2(t, next, lat_back));
            retval.opid = 2;
        }
        else if (is_num_token(t)) { // o3: <num>
            using o3_t = ast::end_term_s::options_s::o3_s;
            retval.options.payload.emplace<o3_t>(end_term_o3(t, next, lat_back));
            retval.opid = 3;
        }
        retval.end_term_tail = std::make_unique<ast::end_term_tail_s>(end_term_tail(next, lat_back));
        return retval;
    }

    ast::end_term_s::options_s::o0_s end_term_o0(const Token& lat, const next_f& next, Token& lat_back) {
        // o0: <pre_unary_operator> <end_term>
        return ast::end_term_s::options_s::o0_s{
            .pre_unary_operator = std::make_unique<ast::pre_unary_operator_s>(pre_unary_operator(lat, next)),
            .end_term = std::make_unique<ast::end_term_s>(end_term(next, lat_back))
        };
    }

    ast::end_term_s::options_s::o1_s end_term_o1(const Token& lat, const next_f& next, Token& lat_back) {
        Token t = is_non_token(lat) ? next() : lat;
        if (is_leftparen_token(t)) {
            ast::expr_s expr_v = expr(next, lat_back);
            t = next();
            if (is_rightparen_token(t)) {
                return ast::end_term_s::options_s::o1_s{
                    .expr = std::make_unique<ast::expr_s>(std::move(expr_v))
                };
            }
        }
        throw ParserError();
    }

    ast::end_term_s::options_s::o2_s end_term_o2(const Token& lat, const next_f& next, Token& lat_back) {
        return ast::end_term_s::options_s::o2_s{
            .func = std::make_unique<ast::func_s>(func(lat, next, lat_back))
        };
    }

    ast::end_term_s::options_s::o3_s end_term_o3(const Token& lat, const next_f& next, Token& lat_back) {
        return ast::end_term_s::options_s::o3_s{
            .num = std::make_unique<ast::num_s>(num(lat, next))
        };
    }

    ast::expr_tail_s expr_tail(const Token& lat, const next_f& next, Token& lat_back) {
        Token t = is_non_token(lat) ? next() : lat;
        ast::expr_tail_s retval;
        if (is_binary_operator_token(t)) {
            retval.is_empty = false;
            retval.binary_operator = std::make_unique<ast::binary_operator_s>(binary_operator(t, next));
            retval.expr = std::make_unique<ast::expr_s>(expr(next, lat_back));
            retval.expr_tail = std::make_unique<ast::expr_tail_s>(expr_tail(lat_back, next, lat_back));
        }
        else if (is_non_token(t) || is_eoe_token(t)) {
            retval.is_empty = true;
            lat_back = t;
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



