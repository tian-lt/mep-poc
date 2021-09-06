#include "gtest/gtest.h"

#include "parser.hpp"
#include "evaluator.hpp"
#include "mock-parser.hpp"

struct CommonEvaluatorTests : ::testing::Test {
    static double _TestFunc(const std::string& identifier, const std::vector<double>& params) {
        if (identifier == "test") {
            EXPECT_EQ(params.size(), 3);
            return params[0] * params[1] * params[2];
        }
        throw "unknown function name.";
    }

    void SetUp() override {
        mep::required_int_t<double> ints(
            mep::RequiredIntTypes<double>::number_t(mep::token_to_double_converter),
            mep::RequiredIntTypes<double>::positive_t([](const double& operand){ return operand; }),
            mep::RequiredIntTypes<double>::negative_t([](const double& operand){ return -operand; }),
            mep::RequiredIntTypes<double>::pow_t([](const double& base, const double& exp){ return std::pow(base, exp); }),
            mep::RequiredIntTypes<double>::func_t(_TestFunc)
        );
        evaluator = std::make_unique<mep::Evaluator<double>>(std::move(ints));
    }
    std::unique_ptr<mep::Evaluator<double>> evaluator;
};

TEST_F(CommonEvaluatorTests, Addition) {

}

TEST_F(CommonEvaluatorTests, Exponentiation) {
    auto exp = MockParser<mep::ast::Exponentiation, mep::RadixDecimal, decltype(mep::details::exponentiation)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("2^3"), mep::details::exponentiation);
    auto val = evaluator->eval_exponentiation(*exp);
    EXPECT_DOUBLE_EQ(val, 8.0);

    auto exp2 = MockParser<mep::ast::Exponentiation, mep::RadixDecimal, decltype(mep::details::exponentiation)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("4^0.5"), mep::details::exponentiation);
    auto val2 = evaluator->eval_exponentiation(*exp2);
    EXPECT_DOUBLE_EQ(val2, 2.0);
}

TEST_F(CommonEvaluatorTests, Function) {
    auto func1 = MockParser<mep::ast::Function, mep::RadixDecimal, decltype(mep::details::function)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("test(1, 2, 3)"), mep::details::function);
    auto val = evaluator->eval_function(*func1);
    EXPECT_DOUBLE_EQ(val, 6.0);
}

TEST_F(CommonEvaluatorTests, Number) {
    mep::Token tok{.token_type = mep::TokenType::DecimalFloat, .payload = std::string("123.456")};
    auto val = evaluator->eval_number(tok);
    EXPECT_DOUBLE_EQ(val, 123.456);
}

TEST_F(CommonEvaluatorTests, Atom) {
    // number
    auto atom = MockParser<mep::ast::Atom, mep::RadixDecimal, decltype(mep::details::atom)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("123.45"), mep::details::atom);
    auto val = evaluator->eval_atom(*atom);
    EXPECT_DOUBLE_EQ(val, 123.45);
}

TEST_F(CommonEvaluatorTests, PrefixUnaryExpression) {
    auto prefix = MockParser<mep::ast::PrefixUnaryExpression, mep::RadixDecimal, decltype(mep::details::prefix_unary_expression)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("+23"), mep::details::prefix_unary_expression);
    auto val = evaluator->eval_prefix_unary_expression(*prefix);
    EXPECT_DOUBLE_EQ(val, 23);

    auto prefix2 = MockParser<mep::ast::PrefixUnaryExpression, mep::RadixDecimal, decltype(mep::details::prefix_unary_expression)>::parse_proxy(
        mep::TokenStream<mep::RadixDecimal>("-32"), mep::details::prefix_unary_expression);
    auto val2 = evaluator->eval_prefix_unary_expression(*prefix2);
    EXPECT_DOUBLE_EQ(val2, -32);
}


