# Arithmetic Expressions Parser - PoC
A hand-written recursive-descent parser that parses simple arithmetic expressions which are usually used by scientific calculator.
This is a PoC(proof of concept) codebase. Not ready for production usage.

## Build AEP

### Prerequisites

Before starting to build the code base, it's required to make sure your dev-environment has [vcpkg][1] installed and below listed package(s) is(are) ready as well.

Note the default triplet that `make.ps1` is using is `x64-windows`.

- gtest

### Steps to build source code

1. Clone this repository into a local directory. Let's say it's `C:\users\happy\aep`.
1. `cd` to the local directory. In this example: `C: && cd C:\users\happy\aep`.
1. Run `make.ps1`to generate a build folder for development works. 
   1. Note that the first run requires a path to [vcpkg][1]'s root folder. For example: `make.ps1 -VcpkgRoot='C:\users\happy\vcpkg'`
1. `cd` to the build folder. In this example: `cd .\build`.
1. Run `cmake --build . -j8` to build the source code into native binaries.
1. Run `ctest . -j16` to test the code base.



## AEP Expression Specification

AEP Expression is a [context-free language](https://en.wikipedia.org/wiki/Context-free_language) (CFL). 

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
| 5 | **\***, **/** | Left-to-right | |
| 6 | **+** *(binary)*, **-** *(binary)* | Left-to-right | |



### AEP Grammar (*in BNF*)

```BNF
<expression> ::= <addition>
               | <subtraction>
               | <term>
               
<addition> ::= <term> "+" <term> <continued_addition_or_subtraction>

<subtraction> ::= <term> "-" <term> <continued_addition_or_subtraction>

<continued_addition_or_subtraction> ::=
      "+" <term> <continued_addition_or_subtraction>
    | "-" <term> <continued_addition_or_subtraction>
    | <empty>
                                      
<term> ::= <multiplication>
         | <division>
         | <factor>
         
<multiplication> ::= <factor> "*" <factor> <continued_multiplication_or_division>
                   | <multiplication_sign_omitted>
                   
multiplication_sign_omitted ::=
      <factor> <parenthesized> <continued_multiplication_or_division>
   	| <factor> <function> <continued_multiplication_or_division>

<division> ::= <dividend> "/" <divisor> <continued_multiplication_or_division>

<continued_multiplication_or_division> ::=
	  "*" <factor> <continued_multiplication_or_division>
	| "/" <divisor> <continued_multiplication_or_division>
	| <continued_multiplication_sign_omitted>
	| <empty>
    
<continued_multiplication_sign_omitted> ::=
	| <parenthesized> <continued_multiplication_or_division>
	| <function> <continued_multiplication_or_division>
    
<dividend> ::= <factor>

<divisor> ::= <factor>

<factor> ::= <postfix_unary_expression>
		   | <exponentiation>
           | <atom>
           
<postfix_unary_expression> ::= <exponentiation> <postfix_unary_operator>
                             | <atom> <postfix_unary_operator>
                             
<exponentiation> ::= <atom> "^" <atom> <continued_exponentiation>

<continued_exponentiation> ::= "^" <atom>
                             | <empty>

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



## Codebase paths

1. Primary Codebase: `./aep`

1. Unit Tests and Integration Tests: `./tests`

1. Demo console application: `./console`

1. Experimental tests and feature explorations: `/experimental`

   





[1]: https://github.com/microsoft/vcpkg