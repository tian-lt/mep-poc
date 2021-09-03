#include <cassert>
#include <unordered_map>
#include "lexer.hpp"

namespace mep::details {
    const std::unordered_map<char, TokenType> _ch_to_tokentype{
        {'+', TokenType::Plus},
        {'-', TokenType::Minus},
        {'*', TokenType::Mult},
        {'/', TokenType::Divide},
        {'^', TokenType::Caret},
        {'%', TokenType::Percent},
        {'(', TokenType::LeftParenthesis},
        {')', TokenType::RightParenthesis},
        {'!', TokenType::Factorial},
        {',', TokenType::Comma},
        {'=', TokenType::Equals},
    };

    template<class _BiDiIt>
    size_t distance(const std::sub_match<_BiDiIt>& m) {
        return m.second - m.first;
    }

    bool try_search(
        const std::string_view& v,
        const std::regex& re,
        std::function<void(std::sub_match<std::string_view::const_iterator>)>&& cb) {
        std::match_results<std::string_view::const_iterator> matches;
        if (std::regex_search(v.cbegin(), v.cend(), matches, re)) {
            cb(matches[0]);
            return true;
        }
        return false;
    }

    void skip_whitespaces(std::string_view& v) {
        // try skip whitespaces
        size_t dist = 0;
        if (try_search(v, whitespaces, [&](auto&& m) {
                dist = distance(m);
            })) {
            v = v.substr(dist); // skip whitespaces
        }
    }

    size_t common_token_lex(Token& t, std::string_view& v) {
        assert(v.size() > 0);
        size_t dist = 0;
        char single_sym = v.front();
        const auto& symit = _ch_to_tokentype.find(single_sym);
        if (symit != _ch_to_tokentype.cend()) {
            t = Token{.token_type = symit->second};
            dist = 1;
        }
        else if(v.starts_with("mod")) {
            t = Token{.token_type = TokenType::Mod};
            dist = 3;
        }
        else if (try_search(v, identifier, [&](auto&& m) {
                t = Token{
                    .token_type = TokenType::Identifier,
                    .payload = std::string(m.first, m.second)
                };
                dist = distance(m);
            })) {
            return dist;
        }
        return dist;
    }

    size_t radix10_token_lex(Token& t, const std::string_view& v) {
        assert(v.size() > 0);
        std::match_results<std::string_view::const_iterator> matches;
        size_t dist = 0;
        if (try_search(v, decimal_scientific_number, [&](auto&& m) {
                t = Token{
                    .token_type = TokenType::DecimalScientificNumber,
                    .payload = std::string(m.first, m.second)
                };
                dist = distance(m);
            }) ||
            try_search(v, decimal_float, [&](auto&& m) {
                t = Token{
                    .token_type = TokenType::DecimalFloat,
                    .payload = std::string(m.first, m.second)
                };
                dist = distance(m);
            }) ||
            try_search(v, decimal_number, [&](auto&& m) {
                t = Token{
                    .token_type = TokenType::DecimalInteger,
                    .payload = std::string(m.first, m.second)
                };
                dist = distance(m);
            })) {
            return dist;
        }
        return 0;
    }
}

