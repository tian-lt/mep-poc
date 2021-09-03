#ifndef MEP_AST_H
#define MEP_AST_H

#include <memory>
#include <optional>
#include <tuple>

#include "lexer.hpp"

namespace mep::ast {
    template <class _T>
    using uptr = std::unique_ptr<_T>;
    template <class _T>
    using ouptr = std::optional<std::unique_ptr<_T>>;
    template <class... _Ts>
    using tpl = std::tuple<_Ts...>;
    template <class... _Ts>
    using otpl = std::optional<std::tuple<_Ts...>>;

    // forward declaration
    struct Expression;
    struct Addition;
    struct Subtraction;
    struct ContinuedAdditionOrSubtraction;
    struct Term;
    struct Multiplication;
    struct Division;
    struct ContinuedMultiplicationOrDivision;
    struct ContinuedMultiplicationSignOmitted;
    struct MultiplicationSignOmitted;
    struct Factor;
    struct PostfixUnaryExpression;
    struct Exponentiation;
    struct ContinuedExponentiation;
    struct Atom;
    struct Parenthesized;
    struct PrefixUnaryExpression;
    struct Function;
    struct ParameterList;
    struct ContinuedParameterList;

    // memory layouts
    struct Expression {
        ouptr<Addition> addition;
        ouptr<Subtraction> subtraction;
        ouptr<Term> term;
    };
    struct Addition {
        uptr<Term> lhs;
        uptr<Term> rhs;
        ouptr<ContinuedAdditionOrSubtraction> continued;
    };
    struct Subtraction {
        uptr<Term> lhs;
        uptr<Term> rhs;
        ouptr<ContinuedAdditionOrSubtraction> continued;
    };
    struct ContinuedAdditionOrSubtraction {
        otpl<uptr<Term>, ouptr<ContinuedAdditionOrSubtraction>> add_continued;
        otpl<uptr<Term>, ouptr<ContinuedAdditionOrSubtraction>> sub_continued;
        bool is_empty;
    };
    struct Term {
        ouptr<Multiplication> multiplication;
        ouptr<Division> division;
        ouptr<Factor> factor;
    };
    struct Multiplication {
        ouptr<Factor> lhs;
        ouptr<Factor> rhs;
        ouptr<ContinuedMultiplicationOrDivision> continued;
        ouptr<MultiplicationSignOmitted> omitted;
    };
    struct Division {
        uptr<Factor> lhs;
        uptr<Factor> rhs;
        ouptr<ContinuedMultiplicationOrDivision> continued;
    };
    struct MultiplicationSignOmitted {
        otpl<uptr<Factor>, uptr<Parenthesized>, ouptr<ContinuedMultiplicationOrDivision>> factor_parenthesized;
        otpl<uptr<Factor>, uptr<Function>, ouptr<ContinuedMultiplicationOrDivision>> factor_function;
        otpl<uptr<Parenthesized>, uptr<Parenthesized>, ouptr<ContinuedMultiplicationOrDivision>> parenthesized_parenthesized;
        otpl<uptr<Parenthesized>, uptr<Function>, ouptr<ContinuedMultiplicationOrDivision>> parenthesized_function;
        otpl<uptr<Function>, uptr<Function>, ouptr<ContinuedMultiplicationOrDivision>> function_function;
        otpl<uptr<Function>, uptr<Parenthesized>, ouptr<ContinuedMultiplicationOrDivision>> function_parenthesized;
    };
    struct ContinuedMultiplicationOrDivision {
        otpl<uptr<Factor>, ouptr<ContinuedMultiplicationOrDivision>> mul_continued; // Mul
        otpl<uptr<Factor>, ouptr<ContinuedMultiplicationOrDivision>> div_continued; // Div
        ouptr<ContinuedMultiplicationSignOmitted> mo_continued;
        bool is_empty;
    };
    struct ContinuedMultiplicationSignOmitted {
        otpl<uptr<Parenthesized>, ouptr<ContinuedMultiplicationOrDivision>> parenthesized_continued;
        otpl<uptr<Function>, ouptr<ContinuedMultiplicationOrDivision>> function_continued;
    };
    struct Factor {
        ouptr<PostfixUnaryExpression> postfix_unary_expression;
        ouptr<Exponentiation> exponentiation;
        ouptr<Atom> atom;
    };
    struct PostfixUnaryExpression {
        otpl<uptr<Exponentiation>, Token> power;
        otpl<uptr<Atom>, Token> atom_operator;
    };
    struct Exponentiation {
        uptr<Atom> lhs;
        uptr<Atom> rhs;
        uptr<ContinuedExponentiation> continued;
    };
    struct ContinuedExponentiation {
        uptr<Atom> atom;
        uptr<ContinuedExponentiation> continued;
        bool is_empty;
    };
    struct Atom {
        ouptr<Parenthesized> parenthesized;
        ouptr<PrefixUnaryExpression> prefix_unary_expression;
        ouptr<Function> function;
        std::optional<Token> number;
    };
    struct Parenthesized {
        uptr<Expression> expression;
    };
    struct PrefixUnaryExpression {
        ouptr<Atom> plus_atom;
        ouptr<Atom> minus_atom;
    };
    struct Function {
        Token identifier;
        uptr<ParameterList> paramlist;
    };
    struct ParameterList {
        uptr<Expression> expression;
        uptr<ContinuedParameterList> continued;
        bool is_empty;
    };
    struct ContinuedParameterList {
        uptr<Expression> expression;
        uptr<ContinuedParameterList> continued;
        bool is_empty;
    };
} // namespace mep::ast

#endif // !MEP_AST_H
