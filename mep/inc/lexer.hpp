#ifndef MEP_LEXER_H
#define MEP_LEXER_H

#include <format>
#include <memory>
#include <regex>
#include <stdexcept>
#include <string>

namespace mep {
    enum class TokenType {
        // operators
        Plus,
        Minus,
        Mult,
        Divide,
        Percent,
        
        // decimal number
        DecimalInteger,
        DecimalFloat,
        DecimalScientificNumber,

        // other radices
        OctalInteger,
        HexadecimalInteger,
        BinaryInteger
    };

    struct Token {
        TokenType token_type;
    };

    struct TokenStreamError : std::runtime_error{
        TokenStreamError() : std::runtime_error("error: failed to parse token.") {}
        TokenStreamError(int position, const std::string& msg)
            : std::runtime_error(std::format("error: pos={0}, msg={1}.", position, msg)) {}
        TokenStreamError(const TokenStreamError&) = delete;
        TokenStreamError(TokenStreamError&&) = default;
    };

    struct _RadixDecimal;

    template<class _RadixT = _RadixDecimal>
    class TokenStream{
    public:
        Token next();
    };

    inline const std::regex decimal_number("[0-9]+");
    inline const std::regex decimal_float("([0-9]+\\.[0-9]+)|(\\.[0-9]+)|([0-9]+\\.)");
    inline const std::regex decimal_scientific_number("([0-9]+\\.[0-9]*e(\\+|\\-)[0-9])");

    template<class _RadixT>
    inline Token TokenStream<_RadixT>::next() {
        return { 0 };
    }
}

#endif // MEP_LEXER_H