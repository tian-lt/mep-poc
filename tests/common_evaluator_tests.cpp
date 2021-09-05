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
            mep::token_to_double_converter,
            _TestFunc);
        evaluator = std::make_unique<mep::Evaluator<double>>(std::move(ints));
    }
    std::unique_ptr<mep::Evaluator<double>> evaluator;
};

TEST_F(CommonEvaluatorTests, Addition) {

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
    EXPECT_FLOAT_EQ(val, 123.456);
}


