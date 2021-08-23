#ifndef MEP_LEXER_H
#define MEP_LEXER_H

namespace mep {
    /*
    Lexer rules:
        Digit ::= [0-9A-F]
        DigitSeq ::= Digit+
        Integer ::= DigitSeq
    */

    enum class TokenType {
        // operators
        Plus,
        Minus,
        Mult,
        Divide,
        Percent,
        
        Digit,
        DigitSeq,
        Number,
    };


}

#endif // MEP_LEXER_H