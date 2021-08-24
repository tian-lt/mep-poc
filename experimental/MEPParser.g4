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
    | number;

paren_expr: LeftParen expr RightParen;

unary_expr
    : Plus expr
    | Minus expr
    | lexpr Percent;

lexpr
    : paren_expr
    | function
    | number;

rexpr
    : expr;

binary_expr
    : lexpr binary_opt rexpr;

function
    : Identifier LeftParen expr (Comma expr)* RightParen;

number
    : sci_number
    | Float
    | Integer;

sci_number
    : sci_num_base E sign sci_num_exp;

sign
    : Plus
    | Minus;

sci_num_base
    : Float | Integer;

sci_num_exp
    : Integer;

binary_opt
    : Caret 
    | Mul
    | Div
    | Plus
    | Minus;

