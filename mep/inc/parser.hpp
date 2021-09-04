#ifndef MEP_PARSER_H
#define MEP_PARSER_H

#include <functional>
#include <memory>
#include <stack>
#include <stdexcept>
#include <string>
#include <variant>

#include "ast.hpp"
#include "lexer.hpp"

/*
# mep poc expression grammar specification

<expression> ::= <addition>
               | <subtraction>
               | <term>
               
<addition> ::= <term> "+" <term> <continued_addition_or_subtraction>

<subtraction> ::= <term> "-" <term> <continued_addition_or_subtraction>

<continued_addition_or_subtraction> ::= "+" <term> <continued_addition_or_subtraction>
                                      | "-" <term> <continued_addition_or_subtraction>
                                      | <empty>
                                      
<term> ::= <multiplication>
         | <division>
         | <factor>
         
<multiplication> ::= <factor> "*" <factor> <continued_multiplication_or_division>
                   | <multiplication_sign_omitted>
                   
multiplication_sign_omitted ::=
      <factor> <parenthesized> <continued_multiplication_or_division>
   	| <factor> <function> <continued_multiplication_or_division>
	| <parenthesized> <parenthesized> <continued_multiplication_or_division>
   	| <function> <function> <continued_multiplication_or_division>

<division> ::= <dividend> "/" <divisor> <continued_multiplication_or_division>

<continued_multiplication_or_division> ::=
	  "*" <factor> <continued_multiplication_or_division>
	| "/" <divisor> <continued_multiplication_or_division>
	| <continued_multiplication_sign_omitted>
	| <empty>
    
<continued_multiplication_sign_omitted> ::=
	| <parenthesized> <continued_multiplication_or_division>
	| <function> <continued_multiplication_or_division>
    
<dividend> ::= <factor>

<divisor> ::= <factor>

<factor> ::= <postfix_unary_expression>
		   | <exponentiation>
           | <atom>
           
<postfix_unary_expression> ::= <exponentiation> <postfix_unary_operator>
                             | <atom> <postfix_unary_operator>
                             
<exponentiation> ::= <atom> "^" <atom>

<postfix_unary_operator> ::= "!"
                           | "%"
                           
<atom> ::= <parenthesized>
         | <prefix_unary_expression>
         | <function>
         | <number>
         
<parenthesized> ::= "(" expression ")"

<prefix_unary_expression> ::= "+" <atom>
                            | "-" <atom>
                            
<function> ::= <Identifier> "(" <parameter_list> ")"

<parameter_list> ::= <expression> <continued_parameter_list>
                   | <empty>
                   
<continued_parameter_list> ::= "," <expression> <continued_parameter_list>
                             | <empty>
*/

namespace mep {
    namespace details {
        using next_f = std::function<Token()>;
        using restore_f = std::function<void(Token&&)>;

        template<class... _Ts>
        class KnownASTCollection {
        public:
            template<class _Tv>
            void push(_Tv&& value) {
                _get<_Tv>().push(std::move(value));
            }
            template<class _Tv>
            bool has_item() {
                return _get<_Tv>().size() > 0;
            }
            template<class _Tv>
            _Tv pop() {
                _Tv v = std::move(_get<_Tv>().top());
                _get<_Tv>().pop();
                return v;
            }
            template<class _Tv>
            _Tv& top() {
                return _get<_Tv>().top();
            }
        private:
            template<class _Tv>
            std::stack<_Tv>& _get() {
                return std::get<std::stack<_Tv>>(_ast_stacks);
            }
        private:
            std::tuple<std::stack<_Ts>...>_ast_stacks;
        };

        using kac_t = KnownASTCollection<
            std::unique_ptr<ast::Atom>,
            std::unique_ptr<ast::Exponentiation>,
            std::unique_ptr<ast::Factor>,
            std::unique_ptr<ast::Term>
        >;

        std::unique_ptr<ast::Expression> expression(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::Addition> addition(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::Subtraction> subtraction(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::ContinuedAdditionOrSubtraction> continued_addition_or_subtraction(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::Term> term(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::Multiplication> multiplication(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::Division> division(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::MultiplicationSignOmitted> multiplication_sign_omitted(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::ContinuedMultiplicationOrDivision> continued_multiplication_or_division(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::ContinuedMultiplicationSignOmitted> continued_multiplication_sign_omitted(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::Factor> factor(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::Exponentiation> exponentiation(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::ContinuedExponentiation> continued_exponentiation(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::PostfixUnaryExpression> postfix_unary_expression(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::Atom> atom(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::Parenthesized> parenthesized(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::PrefixUnaryExpression> prefix_unary_expression(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::Function> function(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::ParameterList> parameter_list(const next_f& next, const restore_f& restore, kac_t& kac);
        std::unique_ptr<ast::ContinuedParameterList> continued_parameter_list(const next_f& next, const restore_f& restore, kac_t& kac);

        constexpr bool is_num_token(const Token& t);
        bool is_binary_operator_token(const Token& t);
        bool is_identifier_token(const Token& t);
        bool is_pre_unary_token(const Token& t);
        bool is_post_unary_token(const Token& t);
        bool is_non_token(const Token& t);
        bool is_eoe_token(const Token& t);
        bool is_leftparen_token(const Token& t);
        bool is_rightparen_token(const Token& t);
    }

    struct ParserError : public std::runtime_error {
        ParserError() noexcept : std::runtime_error("error: failed to parse the token stream.") {}
        explicit ParserError(std::string&& msg) noexcept : std::runtime_error(msg) {}
        ParserError(const ParserError&) = delete;
        ParserError(ParserError&&) = default;
    };

    template<class _RadixT = RadixDecimal>
    class Parser {
    public:
        static inline std::unique_ptr<ast::Expression> parse(TokenStream<_RadixT>&& tstr) {
            std::stack<Token> hold;
            details::kac_t kac;
            auto expr = details::expression([&]() {
                if (hold.size() > 0) {
                    Token retval = hold.top();
                    hold.pop();
                    return retval;
                }
                else {
                    return tstr.next();
                }
                }, [&](Token&& t) {
                    hold.emplace(std::move(t));
                },
                kac);
            return expr;
        }
    };
}

#endif // MEP_PARSER_H