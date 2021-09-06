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

TEST(CommonParserTests, ComplexExpression) {
    auto expr = mep::Parser<mep::RadixDecimal>::parse(
        mep::TokenStream<mep::RadixDecimal>("1+2/3000"));

    expr = mep::Parser<mep::RadixDecimal>::parse(
        mep::TokenStream<mep::RadixDecimal>("(1+2)(3+4)"));

    expr = mep::Parser<mep::RadixDecimal>::parse(
        mep::TokenStream<mep::RadixDecimal>("sin(23)(1+2)(3+4)cos(8383)"));

    expr = mep::Parser<mep::RadixDecimal>::parse(
        mep::TokenStream<mep::RadixDecimal>("1+2/3000(758*133421/32^121)"));
}

TEST(CommonParserTests, Addition) {
    auto addition = MockParser<mep::ast::Addition, mep::RadixDecimal, decltype(mep::details::addition)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("1+2"), mep::details::addition);
    EXPECT_EQ(std::get<std::string>(addition->lhs->factor.value()->atom.value()->number.value().payload), "1");
    EXPECT_EQ(std::get<std::string>(addition->rhs->factor.value()->atom.value()->number.value().payload), "2");

    auto addition2 = MockParser<mep::ast::Addition, mep::RadixDecimal, decltype(mep::details::addition)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("1+2+3"), mep::details::addition);
    EXPECT_EQ(std::get<std::string>(addition2->lhs->factor.value()->atom.value()->number.value().payload), "1");
    EXPECT_EQ(std::get<std::string>(addition2->rhs->factor.value()->atom.value()->number.value().payload), "2");
    EXPECT_EQ(std::get<std::string>(std::get<std::unique_ptr<mep::ast::Term>>(addition2->continued.value()->add_continued.value())->factor.value()->atom.value()->number.value().payload), "3");
    EXPECT_TRUE(std::get<std::optional<std::unique_ptr<mep::ast::ContinuedAdditionOrSubtraction>>>(addition2->continued.value()->add_continued.value()).value()->is_empty);
}

TEST(CommonParserTests, Subtraction) {
    auto subtraction = MockParser<mep::ast::Subtraction, mep::RadixDecimal, decltype(mep::details::subtraction)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("1-2"), mep::details::subtraction);
    EXPECT_EQ(std::get<std::string>(subtraction->lhs->factor.value()->atom.value()->number.value().payload), "1");
    EXPECT_EQ(std::get<std::string>(subtraction->rhs->factor.value()->atom.value()->number.value().payload), "2");

    auto subtraction2 = MockParser<mep::ast::Subtraction, mep::RadixDecimal, decltype(mep::details::subtraction)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("1-2-3"), mep::details::subtraction);
    EXPECT_EQ(std::get<std::string>(subtraction2->lhs->factor.value()->atom.value()->number.value().payload), "1");
    EXPECT_EQ(std::get<std::string>(subtraction2->rhs->factor.value()->atom.value()->number.value().payload), "2");
    EXPECT_EQ(std::get<std::string>(std::get<std::unique_ptr<mep::ast::Term>>(subtraction2->continued.value()->sub_continued.value())->factor.value()->atom.value()->number.value().payload), "3");
    EXPECT_TRUE(std::get<std::optional<std::unique_ptr<mep::ast::ContinuedAdditionOrSubtraction>>>(subtraction2->continued.value()->sub_continued.value()).value()->is_empty);
}

TEST(CommonParserTests, Term) {
    // multiplication
    auto term = MockParser<mep::ast::Term, mep::RadixDecimal, decltype(mep::details::term)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("8*9"), mep::details::term);
    EXPECT_EQ(std::get<std::string>(term->multiplication.value()->lhs.value()->atom.value()->number.value().payload), "8");
    EXPECT_EQ(std::get<std::string>(term->multiplication.value()->rhs.value()->atom.value()->number.value().payload), "9");
    EXPECT_FALSE(term->division.has_value());
    EXPECT_FALSE(term->factor.has_value());

    // division
    auto term2 = MockParser<mep::ast::Term, mep::RadixDecimal, decltype(mep::details::term)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("10/11"), mep::details::term);
    EXPECT_EQ(std::get<std::string>(term2->division.value()->lhs->atom.value()->number.value().payload), "10");
    EXPECT_EQ(std::get<std::string>(term2->division.value()->rhs->atom.value()->number.value().payload), "11");
    EXPECT_FALSE(term2->multiplication.has_value());
    EXPECT_FALSE(term2->factor.has_value());

    // factor
    auto term3 = MockParser<mep::ast::Term, mep::RadixDecimal, decltype(mep::details::term)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("1234"), mep::details::term);
    EXPECT_EQ(std::get<std::string>(term3->factor.value()->atom.value()->number.value().payload), "1234");
    EXPECT_FALSE(term3->multiplication.has_value());
    EXPECT_FALSE(term3->division.has_value());
}

TEST(CommonParserTests, Factor) {
    // postfix unary expression
    auto factor = MockParser<mep::ast::Factor, mep::RadixDecimal, decltype(mep::details::factor)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("123!"), mep::details::factor);
    EXPECT_EQ(std::get<std::string>(std::get<std::unique_ptr<mep::ast::Atom>>(factor->postfix_unary_expression.value()->atom_operator.value())->number.value().payload), "123");
    EXPECT_FALSE(factor->exponentiation.has_value());
    EXPECT_FALSE(factor->atom.has_value());

    // exponentiation
    auto factor2 = MockParser<mep::ast::Factor, mep::RadixDecimal, decltype(mep::details::factor)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("6^7"), mep::details::factor);
    EXPECT_EQ(std::get<std::string>(factor2->exponentiation.value()->base->number.value().payload), "6");
    EXPECT_EQ(std::get<std::string>(factor2->exponentiation.value()->exponent->number.value().payload), "7");
    EXPECT_FALSE(factor2->atom.has_value());
    EXPECT_FALSE(factor2->postfix_unary_expression.has_value());

    // atom
    auto factor3 = MockParser<mep::ast::Factor, mep::RadixDecimal, decltype(mep::details::factor)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("55"), mep::details::factor);
    EXPECT_EQ(std::get<std::string>(factor3->atom.value()->number.value().payload), "55");
    EXPECT_FALSE(factor3->exponentiation.has_value());
    EXPECT_FALSE(factor3->postfix_unary_expression.has_value());
}

TEST(CommonParserTests, Atom) {
    // number
    auto atom = MockParser<mep::ast::Atom, mep::RadixDecimal, decltype(mep::details::atom)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("123"), mep::details::atom);
    EXPECT_EQ(std::get<std::string>(atom->number.value().payload), "123");
    EXPECT_EQ(atom->function, std::nullopt);
    EXPECT_EQ(atom->parenthesized, std::nullopt);
    EXPECT_EQ(atom->prefix_unary_expression, std::nullopt);

    // parenthesized 
    auto atom2 = MockParser<mep::ast::Atom, mep::RadixDecimal, decltype(mep::details::atom)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("(456)"), mep::details::atom);
    EXPECT_EQ(std::get<std::string>(atom2->parenthesized.value()->expression->term.value()->factor.value()->atom.value()->number.value().payload), "456");
    EXPECT_FALSE(atom2->parenthesized.value()->expression->addition.has_value());
    EXPECT_FALSE(atom2->parenthesized.value()->expression->subtraction.has_value());
    EXPECT_EQ(atom2->number, std::nullopt);
    EXPECT_EQ(atom2->function, std::nullopt);
    EXPECT_EQ(atom2->prefix_unary_expression, std::nullopt);

    // function
    auto atom3 = MockParser<mep::ast::Atom, mep::RadixDecimal, decltype(mep::details::atom)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("cos(180)"), mep::details::atom);
    EXPECT_EQ(std::get<std::string>(atom3->function.value()->identifier.payload), "cos");
    EXPECT_EQ(std::get<std::string>(atom3->function.value()->paramlist->expression->term.value()->factor.value()->atom.value()->number.value().payload), "180");
    EXPECT_EQ(atom3->number, std::nullopt);
    EXPECT_EQ(atom3->parenthesized, std::nullopt);
    EXPECT_EQ(atom3->prefix_unary_expression, std::nullopt);

    // prefix unary expression
    auto atom4 = MockParser<mep::ast::Atom, mep::RadixDecimal, decltype(mep::details::atom)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("+5"), mep::details::atom);
    EXPECT_EQ(std::get<std::string>(atom4->prefix_unary_expression.value()->plus_atom.value()->number.value().payload), "5");
    EXPECT_FALSE(atom4->prefix_unary_expression.value()->minus_atom.has_value());
    EXPECT_EQ(atom4->number, std::nullopt);
    EXPECT_EQ(atom4->parenthesized, std::nullopt);
    EXPECT_EQ(atom4->function, std::nullopt);
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

TEST(CommonParserTests, Exponentiation) {
    auto exp = MockParser<mep::ast::Exponentiation, mep::RadixDecimal, decltype(mep::details::exponentiation)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("1^2"), mep::details::exponentiation);
    EXPECT_EQ(std::get<std::string>(exp->base->number.value().payload), "1");
    EXPECT_EQ(std::get<std::string>(exp->exponent->number.value().payload), "2");
    EXPECT_TRUE(exp->continued->is_empty);

    auto exp2 = MockParser<mep::ast::Exponentiation, mep::RadixDecimal, decltype(mep::details::exponentiation)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("1^2^3"), mep::details::exponentiation);
    EXPECT_EQ(std::get<std::string>(exp2->base->number.value().payload), "1");
    EXPECT_EQ(std::get<std::string>(exp2->exponent->number.value().payload), "2");
    EXPECT_EQ(std::get<std::string>(exp2->continued->exponent->number.value().payload), "3");
    EXPECT_FALSE(exp2->continued->is_empty);
}


