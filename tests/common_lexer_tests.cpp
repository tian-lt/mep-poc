#include "gtest/gtest.h"
#include "lexer.hpp"

TEST(CommonLexerTests, EatOperators) {
    mep::TokenStream ts("+-*/^%!mod=");
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
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::Equals);
}
TEST(CommonLexerTests, EatOthers) {
    mep::TokenStream ts("()Hello hello2");
    auto t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::LeftParenthesis);
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::RightParenthesis);
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::Identifier);
    EXPECT_EQ(std::get<std::string>(t.payload), "Hello");
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::Identifier);
    EXPECT_EQ(std::get<std::string>(t.payload), "hello2");
}
TEST(CommonLexerTests, EatWhitespaces) {
    mep::TokenStream ts("     1+1 = sqrt  (      4   \t)    ");
    auto t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::DecimalInteger);
    EXPECT_EQ(std::get<std::string>(t.payload), "1");
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::Plus);
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::DecimalInteger);
    EXPECT_EQ(std::get<std::string>(t.payload), "1");
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::Equals);
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::Identifier);
    EXPECT_EQ(std::get<std::string>(t.payload), "sqrt");
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::LeftParenthesis);
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::DecimalInteger);
    EXPECT_EQ(std::get<std::string>(t.payload), "4");
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::RightParenthesis);
    t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::EOE);
}


