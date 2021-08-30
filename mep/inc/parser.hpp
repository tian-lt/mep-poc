#ifndef MEP_PARSER_H
#define MEP_PARSER_H

#include <deque>
#include <functional>
#include <memory>
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

        

        bool is_num_token(const Token& t);
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
        static inline ast::Expression parse(TokenStream<_RadixT>&& tstr) {
            std::deque<Token> hold;

        }
    };
}

#endif // MEP_PARSER_H