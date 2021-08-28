#include <cassert>
#include "lexer.hpp"

namespace mep::details {
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

    size_t radix10_token_lex(Token& t, const std::string_view& v) {
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

