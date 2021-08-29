grammar m1;

translation_unit : expression;

expression: 
          | addition
          | subtraction
          | factor;
addition: term Plus term continued_addition_or_subtraction;
subtraction: term Minus term continued_addition_or_subtraction;
continued_addition_or_subtraction: Plus term continued_addition_or_subtraction
                                 | Minus term continued_addition_or_subtraction
                                 |;
term: multiplication
    | division
    | factor;
multiplication: factor Mul factor continued_multiplication_or_division;
division: factor Div factor continued_multiplication_or_division;
continued_multiplication_or_division: Mul factor continued_multiplication_or_division
                                    | Div factor continued_multiplication_or_division
                                    |;
factor: postfix_unary_expression
      | atom;
postfix_unary_expression: exponentiation (Fact | Percent)
                        | atom (Fact | Percent);
exponentiation: atom Caret atom;
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

