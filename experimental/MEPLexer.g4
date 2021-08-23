lexer grammar MEPLexer;

Dot: '.';

Digit: [0-9a-fA-F];
DigitSeq: Digit+;
Integer: DigitSeq;
Float: Integer Dot Integer;

Whitespace: [ \t]+ -> skip;

Newline: ('\r' '\n'? | '\n') -> skip;

