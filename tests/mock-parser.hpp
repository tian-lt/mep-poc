#pragma once

#include "parser.hpp"

template<class _ASTType, class _RadixType, class ParseFuncT>
struct MockParser {
    static inline std::unique_ptr<_ASTType> parse_proxy(aep::TokenStream<_RadixType>&& stream, ParseFuncT parsef) {
        std::stack<aep::Token> hold;
        aep::details::kac_t kac;
        return parsef([&]() {
                if (hold.size() > 0) {
                    aep::Token retval = hold.top();
                    hold.pop();
                    return retval;
                }
                else {
                    return stream.next();
                }
            },
            [&](aep::Token&& t) {
                hold.emplace(std::move(t));
            },
            kac);
    }
};


