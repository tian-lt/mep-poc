#include "gtest/gtest.h"
#include "lexer.hpp"

TEST(CommonLexerTests, EatOperators) {
    aep::TokenStream ts("+-*/^%!mod=");
    auto t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::Plus);
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::Minus);
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::Mult);
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::Divide);
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::Caret);
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::Percent);
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::Factorial);
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::Mod);
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::Equals);
}
TEST(CommonLexerTests, EatOthers) {
    aep::TokenStream ts("()Hello hello2");
    auto t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::LeftParenthesis);
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::RightParenthesis);
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::Identifier);
    EXPECT_EQ(std::get<std::string>(t.payload), "Hello");
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::Identifier);
    EXPECT_EQ(std::get<std::string>(t.payload), "hello2");
}
TEST(CommonLexerTests, EatWhitespaces) {
    aep::TokenStream ts("     1+1 = sqrt  (      4   \t)    ");
    auto t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::DecimalInteger);
    EXPECT_EQ(std::get<std::string>(t.payload), "1");
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::Plus);
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::DecimalInteger);
    EXPECT_EQ(std::get<std::string>(t.payload), "1");
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::Equals);
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::Identifier);
    EXPECT_EQ(std::get<std::string>(t.payload), "sqrt");
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::LeftParenthesis);
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::DecimalInteger);
    EXPECT_EQ(std::get<std::string>(t.payload), "4");
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::RightParenthesis);
    t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::EOE);
}


