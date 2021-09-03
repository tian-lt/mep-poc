grammar m1;

translation_unit : expression;

expression: 
          | addition
          | subtraction
          | term;
addition: term Plus term continued_addition_or_subtraction;
subtraction: term Minus term continued_addition_or_subtraction;
continued_addition_or_subtraction: Plus term continued_addition_or_subtraction
                                 | Minus term continued_addition_or_subtraction
                                 |;
term: multiplication
    | division
    | factor;
multiplication: factor Mul factor continued_multiplication_or_division
              | multiplication_sign_omitted;
multiplication_sign_omitted:
              | factor parenthesized continued_multiplication_or_division
              | parenthesized parenthesized continued_multiplication_or_division
              | factor function continued_multiplication_or_division
              | function function continued_multiplication_or_division;
division: factor Div factor continued_multiplication_or_division;
continued_multiplication_or_division: Mul factor continued_multiplication_or_division
                                    | Div factor continued_multiplication_or_division
                                    | continued_multiplication_sign_omitted
                                    |;
continued_multiplication_sign_omitted: parenthesized continued_multiplication_or_division
                                     | function continued_multiplication_or_division;
factor: postfix_unary_expression
      | exponentiation
      | atom;
postfix_unary_expression: exponentiation (Fact | Percent)
                        | atom (Fact | Percent);
exponentiation: atom Caret atom continued_exp;
continued_exp: Caret atom continued_exp|;
atom: parenthesized
    | prefix_unary_expression
    | function
    | Number;
parenthesized: LeftP expression RightP;
prefix_unary_expression: Plus atom
                       | Minus atom;
function: Identifier LeftP parameter_list RightP;
parameter_list: expression continued_parameter_list|;
continued_parameter_list: Comma expression continued_parameter_list |;

Plus : '+';
Minus : '-';
Mul : '*';
Div : '/';
Caret: '^';
Fact: '!';
Percent: '%';
LeftP: '(';
RightP: ')';
Comma: ',';

Number : [0-9]+;
Identifier: [a-zA-Z][a-zA-Z0-9]*;
Whitespace: [ \t]+ -> skip;

