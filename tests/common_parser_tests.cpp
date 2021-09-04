#include "gtest/gtest.h"
#include "parser.hpp"

#include "utils.hpp"
#include "mock-parser.hpp"

TEST(CommonParserTests, EmptyExpression) {
    EXPECT_TRUE(handle_parser_error([]() {
        auto expr = mep::Parser<mep::RadixDecimal>::parse(
            mep::TokenStream<mep::RadixDecimal>(""));
        },
        [](const mep::ParserError& error) {
            return true;
        }));
}

TEST(CommonParserTests, SimpleExpression) {
    auto expr = mep::Parser<mep::RadixDecimal>::parse(
        mep::TokenStream<mep::RadixDecimal>("1+2"));
    EXPECT_EQ(std::get<std::string>(expr->addition.value()->lhs->factor.value()->atom.value()->number.value().payload), "1");
    EXPECT_EQ(std::get<std::string>(expr->addition.value()->rhs->factor.value()->atom.value()->number.value().payload), "2");
    EXPECT_FALSE(expr->subtraction.has_value());
    EXPECT_FALSE(expr->term.has_value());
}

TEST(CommonParserTests, Atom) {
    auto atom = MockParser<mep::ast::Atom, mep::RadixDecimal, decltype(mep::details::atom)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("123"), mep::details::atom);
    EXPECT_EQ(std::get<std::string>(atom->number.value().payload), "123");
    EXPECT_EQ(atom->function, std::nullopt);
    EXPECT_EQ(atom->parenthesized, std::nullopt);
    EXPECT_EQ(atom->prefix_unary_expression, std::nullopt);
}

TEST(CommonParserTests, Parenthesized) {
    auto parenthesized = MockParser<mep::ast::Parenthesized, mep::RadixDecimal, decltype(mep::details::parenthesized)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("(123)"), mep::details::parenthesized);
    EXPECT_EQ(std::get<std::string>(parenthesized->expression->term.value()->factor.value()->atom.value()->number.value().payload), "123");
    EXPECT_FALSE(parenthesized->expression->addition.has_value());
    EXPECT_FALSE(parenthesized->expression->subtraction.has_value());
}

TEST(CommonParserTests, Function) {
    auto function = MockParser<mep::ast::Function, mep::RadixDecimal, decltype(mep::details::function)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("sin(180)"), mep::details::function);
    EXPECT_EQ(std::get<std::string>(function->identifier.payload), "sin");
    EXPECT_EQ(std::get<std::string>(function->paramlist->expression->term.value()->factor.value()->atom.value()->number.value().payload), "180");
    EXPECT_FALSE(function->paramlist->is_empty);
    EXPECT_TRUE(function->paramlist->continued->is_empty);

    auto function2 = MockParser<mep::ast::Function, mep::RadixDecimal, decltype(mep::details::function)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("func(1, 2, 3)"), mep::details::function);
    EXPECT_EQ(std::get<std::string>(function2->identifier.payload), "func");
    EXPECT_EQ(std::get<std::string>(function2->paramlist->expression->term.value()->factor.value()->atom.value()->number.value().payload), "1");
    EXPECT_EQ(std::get<std::string>(function2->paramlist->continued->expression->term.value()->factor.value()->atom.value()->number.value().payload), "2");
    EXPECT_EQ(std::get<std::string>(function2->paramlist->continued->continued->expression->term.value()->factor.value()->atom.value()->number.value().payload), "3");

    auto function3 = MockParser<mep::ast::Function, mep::RadixDecimal, decltype(mep::details::function)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("empty()"), mep::details::function);
    EXPECT_EQ(std::get<std::string>(function3->identifier.payload), "empty");
    EXPECT_TRUE(function3->paramlist->is_empty);
}


