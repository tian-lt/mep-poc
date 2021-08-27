grammar m1;

translation_unit : expression;

expression: expression Plus expression | atom;
atom: Number;

Plus : '+';
Minus : '-';

Number : [0-9]+;
Whitespace: [ \t]+ -> skip;

