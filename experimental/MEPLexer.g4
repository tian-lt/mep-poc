lexer grammar MEPLexer;

Dot: '.';
Plus: '+';
Minus: '-';
Mul: '*';
Div: '/';
Caret: '^';
Percent: '%';
E: 'e' | 'E';
LeftParen : '(';
RightParen : ')';

fragment DIGIT: [0-9];
fragment NONDIGIT: [a-zA-Z_];

Integer: DIGIT+;
Float: (Integer Dot Integer?) | (Integer? Dot Integer);
SciNumber: Float E (Plus|Minus) Integer;

Identifier: NONDIGIT ( DIGIT | NONDIGIT )*;

fragment HEXDIGIT: [0-9a-fA-F];
HexNumber: HEXDIGIT+;

Whitespace: [ \t]+ -> skip;

Newline: ('\r' '\n'? | '\n') -> skip;

