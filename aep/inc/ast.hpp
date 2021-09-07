#ifndef AEP_AST_H
#define AEP_AST_H

#include <memory>
#include <optional>
#include <tuple>

#include "lexer.hpp"

namespace aep::ast {
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
        uptr<ContinuedAdditionOrSubtraction> continued;
    };
    struct Subtraction {
        uptr<Term> lhs;
        uptr<Term> rhs;
        uptr<ContinuedAdditionOrSubtraction> continued;
    };
    struct ContinuedAdditionOrSubtraction {
        otpl<uptr<Term>, uptr<ContinuedAdditionOrSubtraction>> add_continued;
        otpl<uptr<Term>, uptr<ContinuedAdditionOrSubtraction>> sub_continued;
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
        uptr<ContinuedMultiplicationOrDivision> continued;
    };
    struct MultiplicationSignOmitted {
        otpl<uptr<Factor>, uptr<Parenthesized>, uptr<ContinuedMultiplicationOrDivision>> factor_parenthesized;
        otpl<uptr<Factor>, uptr<Function>, uptr<ContinuedMultiplicationOrDivision>> factor_function;
    };
    struct ContinuedMultiplicationOrDivision {
        otpl<uptr<Factor>, uptr<ContinuedMultiplicationOrDivision>> mul_continued; // Mul
        otpl<uptr<Factor>, uptr<ContinuedMultiplicationOrDivision>> div_continued; // Div
        ouptr<ContinuedMultiplicationSignOmitted> mo_continued;
        bool is_empty;
    };
    struct ContinuedMultiplicationSignOmitted {
        otpl<uptr<Parenthesized>, uptr<ContinuedMultiplicationOrDivision>> parenthesized_continued;
        otpl<uptr<Function>, uptr<ContinuedMultiplicationOrDivision>> function_continued;
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
        uptr<Atom> base;
        uptr<Atom> exponent;
        uptr<ContinuedExponentiation> continued;
    };
    struct ContinuedExponentiation {
        uptr<Atom> exponent;
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
} // namespace aep::ast

#endif // !AEP_AST_H
