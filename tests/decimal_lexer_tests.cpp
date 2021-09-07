#include "gtest/gtest.h"
#include "lexer.hpp"

TEST(DecimalLexerTests, EatInteger){
    aep::TokenStream ts("11+12");
    auto t = ts.next();
    EXPECT_EQ(t.token_type, aep::TokenType::DecimalInteger);
    EXPECT_EQ(std::get<std::string>(t.payload), "11");
}
TEST(DecimalLexerTests, EatFloat) {
    {
        aep::TokenStream ts("11.11-2");
        auto t = ts.next();
        EXPECT_EQ(t.token_type, aep::TokenType::DecimalFloat);
        EXPECT_EQ(std::get<std::string>(t.payload), "11.11");
    }
    {
        aep::TokenStream ts("22.*3243");
        auto t = ts.next();
        EXPECT_EQ(t.token_type, aep::TokenType::DecimalFloat);
        EXPECT_EQ(std::get<std::string>(t.payload), "22.");
    }
    {
        aep::TokenStream ts(".333^343");
        auto t = ts.next();
        EXPECT_EQ(t.token_type, aep::TokenType::DecimalFloat);
        EXPECT_EQ(std::get<std::string>(t.payload), ".333");
    }
}
TEST(DecimalLexerTests, EatScientific) {
    {
        aep::TokenStream ts("11e22");
        auto t = ts.next();
        EXPECT_EQ(t.token_type, aep::TokenType::DecimalScientificNumber);
        EXPECT_EQ(std::get<std::string>(t.payload), "11e22");
    }
    {
        aep::TokenStream ts("3.1234e+567");
        auto t = ts.next();
        EXPECT_EQ(t.token_type, aep::TokenType::DecimalScientificNumber);
        EXPECT_EQ(std::get<std::string>(t.payload), "3.1234e+567");
    }
    {
        aep::TokenStream ts(".123e-45");
        auto t = ts.next();
        EXPECT_EQ(t.token_type, aep::TokenType::DecimalScientificNumber);
        EXPECT_EQ(std::get<std::string>(t.payload), ".123e-45");
    }
    {
        aep::TokenStream ts("2.e3");
        auto t = ts.next();
        EXPECT_EQ(t.token_type, aep::TokenType::DecimalScientificNumber);
        EXPECT_EQ(std::get<std::string>(t.payload), "2.e3");
    }
}

