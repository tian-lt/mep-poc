# Mathematical Expression Parser - PoC
A hand-written recursive-descent parser that parses simple mathematical expressions which are usually used by scientific calculator.
This is a PoC(proof of concept) codebase. Not ready for production usage.

## MEP Expression Specification

MEP Expression is a [context-free language]([Context-free language - Wikipedia](https://en.wikipedia.org/wiki/Context-free_language)) (CFL). 

Operators

| Operator | Type          | Description                                                  |
| -------- | ------------- | ------------------------------------------------------------ |
| **+**    | Prefix-unary  | Plus sign, which leaves its operand unchanged (***+x*** means the same as ***x***) |
| **-**    | Prefix-unary  | Minus sign, in contrast with Plus-sign, which changes the operand to negative number if it's positive, and vice versa. |
| **%**    | Postfix-unary | Percent sign, which changes operand ***x*** into ***(x/100)* ✕ *100%*** |
| **!**    | Postfix-unary | Factorial sign. ***n! = n • (n-1) • (n-2) ... 3 • 2 • 1***   |
| **( )**  | Unary         | Parenthesis signs, which declares its inner expression to be evaluated with a higher precedence.  ***( expression )*** |
| **+**    | Binary        | Addition sign. ***term + term = sum***                       |
| **-**    | Binary        | Subtraction sign. ***term - term = difference***             |
| **\***    | Binary        | Multiplication sign. ***factor \* factor = product***        |
| **/**    | Binary        | Division sign. ***dividend / divisor = quotient***           |
| **^**    | Binary        | Exponentiation sign. ***base ^ exponent = power***           |
| **mod**  | Binary        | Modulo sign. ***dividend*** **mod** ***divisor = modulus (remainder)*** |

Operator precedence

| Precedence | Operators                      | Associativity | Description |
| ---------- | ------------------------------ | ------------- | ----------- |
| 1          | **( )**                        | Left-to-right |             |
| 2          | **+** *(unary)*, **-** *(unary)* | Left-to-right |             |
| 3 | **^** | Left-to-right | |
| 4         | **!**, **%** | Left-to-right |             |
| 5 | **\***, **/**, **mod** | Left-to-right | |
| 6 | **+** *(binary)*, **-** *(binary)* | Left-to-right | |



### Human Friendly BNF Grammar

```BNF
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
<division> ::= <dividend> "/" <divisor> <continued_multiplication_or_division>
<continued_multiplication_or_division> ::=
	  "*" <factor> <continued_multiplication_or_division>
	| "/" <divisor> <continued_multiplication_or_division>
	| <empty>										
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
```

### Verifies that above grammar is LL(1) grammar

| FIRST(X)                             | Reduction                                                    | Results                        |
| ------------------------------------ | ------------------------------------------------------------ | ------------------------------ |
| expression                           | FIRST(addition)  ∪ FIRST(subtraction) ∪ FIRST(factor)<br/>=FIRST(term) ∪ FIRST(factor) | {"(", "+", "-", *Id*, *Digit*} |
| addition                             | FIRST(term)                                                  | {"(", "+", "-", *Id*, *Digit*} |
| subtraction                          | FIRST(term)                                                  | {"(", "+", "-", *Id*, *Digit*} |
| continued_addition_or_subtraction    |                                                              | {"+", "-", ε}                  |
| term                                 | FIRST(Multiplication) ∪ FIRST(Division) ∪ FIRST(factor)<br/>= FIRST(factor)<br/>= {"(", "+", "-", *Id*, *Digit*} | {"(", "+", "-", *Id*, *Digit*} |
| continued_multiplication_or_division |                                                              | {"\*", "/", ε}                 |
| factor                               | FIRST(postfix_unary_expression) ∪ FIRST(exponentiation) ∪ FIRST(atom)<br/>= {"(", "+", "-", *Id*, *Digit*} | {"(", "+", "-", *Id*, *Digit*} |
| postfix_unary_expression             | FIRST(exponentiation) ∪ FIRST(atom)<br/>= {"(", "+", "-", *Id*, *Digit*} | {"(", "+", "-", *Id*, *Digit*} |
| exponentiation                       | FIRST(atom)                                                  | {"(", "+", "-", *Id*, *Digit*} |
| atom                                 | FIRST(parenthesized) ∪ FIRST(prefix_unary_expression) ∪ FIRST(function) ∪ FIRST(number)<br/>= {"("} ∪ {"+", "-"} ∪ {*Id*} ∪ {*Digit*}<br/>= {"(", "+", "-", *Id*, *Digit*} | {"(", "+", "-", *Id*, *Digit*} |
| parenthesized                        |                                                              | {"("}                          |
| prefix_unary_expression              |                                                              | {"+", "-"}                     |
| function                             |                                                              | {Id}                           |
| number                               |                                                              | {Digit}                        |
| continued_parameter_list             |                                                              | {","}                          |
| postfix_unary_operator               |                                                              | {"!", "%"}                     |



| FOLLOW(X)                            |                                                              |                                                    |
| ------------------------------------ | ------------------------------------------------------------ | -------------------------------------------------- |
| expression                           | {")"} ∪ FIRST(continued_parameter_list)                      | {")", ",",$}                                       |
| addition                             | FOLLOW(expression)                                           | {")", ",", $}                                      |
| subtraction                          | FOLLOW(expression)                                           | {")", ",", $}                                      |
| continued_addition_or_subtraction    | FOLLOW(addition) ∪ FOLLOW(subtraction) ∪ FOLLOW(term)<br/>= {")", ","} ∪ FOLLOW(term) |                                                    |
| term                                 | {"+", "-"} ∪ FIRST(continued_addition_or_subtraction) ∪ FOLLOW(addition) ∪ FOLLOW(subtraction)<br/>={"+", "-"} ∪ {"+", "-", ε} ∪ {")", ",",$} | {")", ",","+", "-", $, ε}                          |
| multiplication                       | FOLLOW(term)                                                 | {")", ",","+", "-", $, ε}                          |
| division                             | FOLLOW(term)                                                 | {")", ",","+", "-", $, ε}                          |
| continued_multiplication_or_division | FOLLOW(factor) ∪ FOLLOW(multiplication) ∪ FOLLOW(division)<br/>=FOLLOW(factor) ∪ {")", ",","+", "-", $, ε} |                                                    |
| factor                               | {"\*", "/"} ∪ FIRST(continued_multiplication_or_division) ∪ FOLLOW(expression) ∪ FOLLOW(term) ∪ FOLLOW(multiplication) ∪ FOLLOW(division) ∪ FOLLOW(continued_multiplication_or_division)<br/>={"\*", "/"} ∪ {"\*", "/", ε} ∪ {")", ",",$} ∪ {")", ",","+", "-", $, ε} ∪ {")", ",","+", "-", $, ε} | {"\*", "/", ")", ",","+", "-", $, ε}               |
| postfix_unary_expression             | FOLLOW(factor)                                               | {"\*", "/", ")", ",","+", "-", $, ε}               |
| exponentiation                       | FIRST(postfix_unary_operator) ∪ FOLLOW(factor)               | {"\*", "/", ")", ",","+", "-", "!", "%", $, ε}     |
| postfix_unary_operator               | FOLLOW(postfix_unary_expression)                             | {"\*", "/", ")", ",","+", "-", $, ε}               |
| atom                                 | {"^"} ∪ FOLLOW(factor) ∪ FIRST(postfix_unary_expression) ∪ FOLLOW(exponentiation) ∪ FOLLOW(prefix_unary_expression) <br/>={"^"} ∪ FOLLOW(exponentiation) | {"^","\*", "/", ")", ",","+", "-", "!", "%", $, ε} |
| parenthesized                        | FOLLOW(atom)                                                 | {"^","\*", "/", ")", ",","+", "-", "!", "%", $, ε} |
| prefix_unary_expression              | FOLLOW(atom)                                                 | {"^","\*", "/", ")", ",","+", "-", "!", "%", $, ε} |
| function                             | FOLLOW(atom)                                                 | {"^","\*", "/", ")", ",","+", "-", "!", "%", $, ε} |
| parameter_list                       |                                                              | {")"}                                              |
| continued_parameter_list             | FOLLOW(parameter_list) ∪ FOLLOW(expression)                  | {")", ",",$}                                       |



### 

