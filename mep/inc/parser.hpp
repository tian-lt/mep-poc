#ifndef MEP_PARSER_H
#define MEP_PARSER_H

#include <functional>
#include <memory>
#include <stdexcept>
#include <string>
#include <variant>

#include "lexer.hpp"

/*
# mep poc expression grammar specification

original rules for easy understanding:
    <expr> ::= <expr> <binary_operator> <expr>
             | <end_term>
    <end_term> := <end_term> <post_unary_operator>
                | <pre_unary_operator> <end_term>
                | <LEFT_PAREN> <expr> <RIGHT_PAREN>
                | <func>
                | <num>

adjusted rules for top-down parsing:
    <expr> ::= <end_term> <expr_tail>
    <expr_tail> ::= <binary_operator> <expr> <expr_tail>
                  | <empty>
    <end_term> ::= (   <pre_unary_operator> <end_term>
                     | <LEFT_PAREN> <expr> <RIGHT_PAREN>
                     | <func>
                     | <num>
                   ) <end_term_tail>
    <end_term_tail> ::= <post_unary_operator> <end_term_tail>
                      | <empty>
*/

namespace mep {
    namespace ast {
        // forward declaration
        struct expr_s;
        struct expr_tail_s;
        struct end_term_s;
        struct end_term_tail_s;
        struct binary_operator_s;
        struct pre_unary_operator_s;
        struct post_unary_operator_s;
        struct func_s;
        struct num_s;
        struct empty_s;

        // memory layouts
        struct expr_s {
            std::unique_ptr<end_term_s> end_term;
            std::unique_ptr<expr_tail_s> expr_tail;
        };

        struct expr_tail_s {
            std::unique_ptr<binary_operator_s> binary_operator;
            std::unique_ptr<expr_s> expr;
            std::unique_ptr<expr_tail_s> expr_tail;
            bool is_empty;
        };

        struct end_term_s {
            struct options_s {
                struct o0_s {
                    std::unique_ptr<pre_unary_operator_s> pre_unary_operator;
                    std::unique_ptr<end_term_s> end_term;
                };
                struct o1_s {
                    std::unique_ptr<expr_s> expr;
                };
                struct o2_s {
                    std::unique_ptr<func_s> func;
                };
                struct o3_s {
                    std::unique_ptr<num_s> num;
                };
                std::variant<o0_s, o1_s, o2_s, o3_s> payload;
            } options;
            std::unique_ptr<end_term_tail_s> end_term_tail;
            int opid;
        };

        struct end_term_tail_s{
            end_term_tail_s() noexcept : is_empty(false) {}
            explicit end_term_tail_s(bool empty) noexcept : is_empty(empty) {}
            end_term_tail_s(end_term_tail_s&&) = default;
            end_term_tail_s(const end_term_tail_s&) = delete;

            std::unique_ptr<post_unary_operator_s> post_unary_operator;
            std::unique_ptr<end_term_tail_s> end_term_tail;
            bool is_empty;
        };

        struct binary_operator_s {
            Token token;
        };

        struct pre_unary_operator_s {
            Token token;
        };

        struct post_unary_operator_s {
            Token token;
        };

        struct func_s {
            Token identifier;
            std::unique_ptr<expr_s> expr;
        };

        struct num_s {
            Token token;
        };
    }

    namespace details {
        using next_f = std::function<Token()>;
        ast::expr_s expr(const next_f& next);
        ast::expr_tail_s expr_tail(const next_f& next);
        ast::end_term_s end_term(const next_f& next);
        ast::end_term_s::options_s::o0_s end_term_o0(const Token& lat, const next_f& next);
        ast::end_term_s::options_s::o1_s end_term_o1(const Token& lat, const next_f& next);
        ast::end_term_s::options_s::o2_s end_term_o2(const Token& lat, const next_f& next);
        ast::end_term_s::options_s::o3_s end_term_o3(const Token& lat, const next_f& next);
        ast::end_term_tail_s end_term_tail(const next_f& next);
        ast::binary_operator_s binary_operator(const Token& lat, const next_f& next);
        ast::pre_unary_operator_s pre_unary_operator(const Token& lat, const next_f& next);
        ast::post_unary_operator_s post_unary_operator(const Token& lat, const next_f& next);
        ast::func_s func(const Token& lat, const next_f& next);
        ast::num_s num(const Token& lat, const next_f& next);

        bool is_num_token(const Token& t);
        bool is_binary_operator_token(const Token& t);
        bool is_identifier_token(const Token& t);
        bool is_pre_unary_token(const Token& t);
        bool is_post_unary_token(const Token& t);
        bool is_non_token(const Token& t);
        bool is_eoe_token(const Token& t);
        bool is_leftparen_token(const Token& t);
    }

    struct ParserError : public std::runtime_error {
        ParserError() noexcept : std::runtime_error("error: failed to parse the token stream.") {}
        explicit ParserError(std::string&& msg) noexcept : std::runtime_error(msg) {}
        ParserError(const ParserError&) = delete;
        ParserError(ParserError&&) = default;
    };

    template<class _RadixT>
    class Parser {
    public:
        Parser() noexcept {}
        Parser(const Parser&) = delete;
        Parser(Parser&&) noexcept = default;
    public:
        ast::expr_s parse(TokenStream<_RadixT>&& tstr) {
            return details::expr([&]() {
                return tstr.next();
            });
        }
    private:
    private:
        TokenStream<_RadixT> _cur_ts;
        Token   _cur_t;
    };
}

#endif // MEP_PARSER_H