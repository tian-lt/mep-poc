#include "gtest/gtest.h"
#include "parser.hpp"

#include "utils.hpp"

TEST(CommonParserTests, EmptyExpression) {
    EXPECT_TRUE(handle_parser_error([]() {
        const auto& expr = mep::Parser<mep::RadixDecimal>::parse(
            mep::TokenStream<mep::RadixDecimal>(""));
        },
        [](const mep::ParserError& error) {
            return true;
        }));
}

TEST(CommonParserTests, SimpleExpression) {
    const auto& expr = mep::Parser<mep::RadixDecimal>::parse(
        mep::TokenStream<mep::RadixDecimal>("1+1"));
}


