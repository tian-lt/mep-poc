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
| *****    | Binary        | Multiplication sign. ***factor \* factor = product***        |
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
| 5 | *****, **/**, **mod** | Left-to-right | |
| 6 | **+** *(binary)*, **-** *(binary)* | Left-to-right | |



### Human Friendly BNF Grammar

```BNF
<expression> ::= <addition>
               | <subtraction>
               | <atom>
<addition> ::= <term> "+" <term>
<subtraction> ::= <term> "-" <term>
<term> ::= <product>
         | <quotient>
<product> ::= <factor> "*" <factor>
<quotient> ::= <dividend> "/" <divisor>
<dividend> ::= <factor>
<divisor> ::= <factor>
<factor> ::= <postfix_unary_expression>
           | <atom>
<postfix_unary_expression> ::= <exponentiation> <postfix_unary_operator>
							 | <atom> <postfix_unary_operator>
<exponentiation> ::= <atom> "^" <atom>
<atom> ::= <parenthesized>
         | <prefix_unary_expression>
         | <function>
         | <number>
```


### Converts into top-down parsing oriented BNF Grammar

