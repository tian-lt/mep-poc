#include "gtest/gtest.h"
#include "parser.hpp"

TEST(CommonParserTests, SimpleExpression) {
    mep::ast::expr_s ast = mep::Parser<mep::RadixDecimal>::parse(mep::TokenStream("1+1"));
}


