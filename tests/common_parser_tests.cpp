#include "gtest/gtest.h"
#include "parser.hpp"

TEST(CommonParserTests, SimpleExpression) {
    const auto& expr = mep::Parser<mep::RadixDecimal>::parse(
        mep::TokenStream<mep::RadixDecimal>(""));
}


