#ifndef MEP_LEXER_H
#define MEP_LEXER_H

#include <functional>
#include <memory>
#include <regex>
#include <stdexcept>
#include <sstream>
#include <string>
#include <string_view>
#include <type_traits>
#include <variant>

namespace mep {
    enum class TokenType {
        None = 0,
        // operators
        //   binary operators
        Plus, // (pre-unary operator as well)
        Minus, // (pre-unary operator as well)
        Mult,
        Divide,
        Caret,
        Mod,
        Equals,
        //   unary operators (pre- and -post)
        Percent, // (post-unary operator)
        Factorial, // (post-unary operator) 
        
        // decimal number
        DecimalInteger,
        DecimalFloat,
        DecimalScientificNumber,

        // other radices
        OctalInteger,
        HexadecimalInteger,
        BinaryInteger,

        // others
        LeftParenthesis,
        RightParenthesis,
        Comma,
        Identifier,
        EOE, // end of expression
    };

    struct Token {
        TokenType token_type;
        std::variant<std::string> payload;
    };
    inline const Token NonToken {.token_type = TokenType::None};
    inline const Token EOEToken {.token_type = TokenType::EOE};
    inline bool operator==(const Token& lhs, const Token& rhs) {
        return lhs.token_type == rhs.token_type
            && lhs.payload == rhs.payload;
    };

    struct TokenStreamError : std::runtime_error{
        TokenStreamError() noexcept : std::runtime_error("error: failed to parse token.") {}
        TokenStreamError(std::string&& msg) noexcept : std::runtime_error(msg) {}
        TokenStreamError(const TokenStreamError&) = delete;
        TokenStreamError(TokenStreamError&&) noexcept = default;
    };

    struct RadixHexadecimal;
    struct RadixDecimal;
    struct RadixOctal;
    struct RadixBinary;

    template<class _RadixT = RadixDecimal>
    class TokenStream{
    public:
        explicit TokenStream(const std::string& source) noexcept 
            : _source(source)
            , _view(_source)
        {}
        TokenStream() = delete;
        TokenStream(const TokenStream&) = delete;
        TokenStream(TokenStream&& rhs) = default;

    public:
        Token next();
    private:
        // TODO: using Stream to replace this member
        // because theoretically we don't need to know everything while recogniting tokens
        std::string _source; 
        std::string_view _view;
    };

    namespace details {
        void skip_whitespaces(std::string_view& v);
        size_t common_token_lex(Token& t, std::string_view& v);
        size_t radix16_token_lex(Token& t, const std::string_view& v);
        size_t radix10_token_lex(Token& t, const std::string_view& v);
        size_t radix8_token_lex(Token& t, const std::string_view& v);
        size_t radix2_token_lex(Token& t, const std::string_view& v);

        using lex_f = size_t(*)(Token&, const std::string_view&);

        // TODO: in future, we can replace below std::regex with built-in NFA/DFAs
        // to speed up the process of lexeme recognition
        inline const std::regex decimal_number("^[0-9]+");
        inline const std::regex decimal_float("^([0-9]+\\.[0-9]+)|(\\.[0-9]+)|([0-9]+\\.)");
        inline const std::regex decimal_scientific_number("^(([0-9]+)|([0-9]+\\.[0-9]+)|(\\.[0-9]+)|([0-9]+\\.))e(\\+|-)?[0-9]+");
        inline const std::regex whitespaces("^\\s+");
        inline const std::regex identifier("^([a-zA-Z][0-9a-zA-Z]*)");
    }

    template<class _RadixT>
    inline constexpr details::lex_f _pick_token_lex()
    {
        if constexpr (std::is_same_v<_RadixT, RadixDecimal>)
        {
            return details::radix10_token_lex;
        }
    }

    template<class _RadixT>
    inline Token TokenStream<_RadixT>::next() {
        constexpr details::lex_f radix_variant_lex = _pick_token_lex<_RadixT>();
        Token t = EOEToken;
        if (_view.size() > 0)
        {
            details::skip_whitespaces(_view);
            if (_view.size() <= 0) {
                return EOEToken;
            }
            auto offset = details::common_token_lex(t, _view);
            if (offset > 0) {
                _view = _view.substr(offset);
                return t;
            }
            offset = radix_variant_lex(t, _view);
            if(offset > 0){
                _view = _view.substr(offset);
                return t;
            }
            throw TokenStreamError();
        }
        return EOEToken;
    }
}

#endif // MEP_LEXER_H