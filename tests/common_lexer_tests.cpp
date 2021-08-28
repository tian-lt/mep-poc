#include "gtest/gtest.h"
#include "lexer.hpp"

TEST(CommonLexerTests, EatOperators) {
    mep::TokenStream ts("+-*/^%!mod");
    auto t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::Plus);
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::Minus);
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::Mult);
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::Divide);
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::Caret);
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::Percent);
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::Factorial);
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::Mod);
}

