parser grammar MEPParser;
options {
    tokenVocab = MEPLexer;
}
translation_unit
    : expr EOF;

expr
    : paren_expr
    | function
    | binary_expr
    | unary_expr
    | Identifier
    | number_expr;

paren_expr: LeftParen expr RightParen;

unary_expr
    : Plus expr
    | Minus expr
    | lexpr Percent;

lexpr
    : paren_expr
    | function
    | number_expr;

rexpr
    : expr;

binary_expr
    : lexpr binary_opt rexpr;

function
    : Identifier LeftParen expr RightParen;

number_expr
    : SciNumber
    | Float
    | Integer;

binary_opt
    : Mul
    | Div
    | Plus
    | Minus;

