#include "gtest/gtest.h"
#include "lexer.hpp"

TEST(DecimalLexerTests, EatInteger){
    mep::TokenStream ts("11+12");
    auto t = ts.next();
    EXPECT_EQ(t.token_type, mep::TokenType::DecimalInteger);
    EXPECT_EQ(std::get<std::string>(t.payload), "11");
}
TEST(DecimalLexerTests, EatFloat) {
    {
        mep::TokenStream ts("11.11");
        auto t = ts.next();
        EXPECT_EQ(t.token_type, mep::TokenType::DecimalFloat);
        EXPECT_EQ(std::get<std::string>(t.payload), "11.11");
    }
    {
        mep::TokenStream ts("22.");
        auto t = ts.next();
        EXPECT_EQ(t.token_type, mep::TokenType::DecimalFloat);
        EXPECT_EQ(std::get<std::string>(t.payload), "22.");
    }
    {
        mep::TokenStream ts(".333");
        auto t = ts.next();
        EXPECT_EQ(t.token_type, mep::TokenType::DecimalFloat);
        EXPECT_EQ(std::get<std::string>(t.payload), ".333");
    }
}
