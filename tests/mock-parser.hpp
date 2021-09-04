#pragma once

#include "parser.hpp"

template<class _ASTType, class _RadixType, class ParseFuncT>
struct MockParser {
    static inline std::unique_ptr<_ASTType> parse_proxy(mep::TokenStream<_RadixType>&& stream, ParseFuncT parsef) {
        std::stack<mep::Token> hold;
        mep::details::kac_t kac;
        return parsef([&]() {
                if (hold.size() > 0) {
                    mep::Token retval = hold.top();
                    hold.pop();
                    return retval;
                }
                else {
                    return stream.next();
                }
            },
            [&](mep::Token&& t) {
                hold.emplace(std::move(t));
            },
            kac);
    }
};


