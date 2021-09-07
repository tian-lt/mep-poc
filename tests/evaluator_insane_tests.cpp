#include "gtest/gtest.h"

#include "parser.hpp"
#include "evaluator.hpp"

struct EvaluatorInsaneTests : ::testing::Test {
    static double _TestFunc(const std::string& identifier, const std::vector<double>& params) {
        if (identifier == "test") {
            EXPECT_EQ(params.size(), 3);
            return params[0] * params[1] * params[2];
        }
        throw "unknown function name.";
    }

    static double _Factorial(const double& n){
        double result = 1.0;
        const uint32_t _n = static_cast<uint32_t>(n);
        for (auto i = 2; i <= n; ++i) {
            result *= static_cast<double>(i);
        }
        return result;
    }

    void SetUp() override {
        mep::required_int_t<double> ints(
            mep::RequiredIntTypes<double>::number_t(mep::token_to_double_converter),
            mep::RequiredIntTypes<double>::positive_t([](const double& operand){ return operand; }),
            mep::RequiredIntTypes<double>::negative_t([](const double& operand){ return -operand; }),
            mep::RequiredIntTypes<double>::add_t([](const double& lhs, const double& rhs) { return lhs + rhs; }),
            mep::RequiredIntTypes<double>::sub_t([](const double& lhs, const double& rhs) { return lhs - rhs; }),
            mep::RequiredIntTypes<double>::mul_t([](const double& lhs, const double& rhs) { return lhs * rhs; }),
            mep::RequiredIntTypes<double>::div_t([](const double& lhs, const double& rhs) { return lhs / rhs; }),
            mep::RequiredIntTypes<double>::pow_t([](const double& base, const double& exp){ return std::pow(base, exp); }),
            mep::RequiredIntTypes<double>::percent_t([](const double& operand){ return operand/100.0; }),
            mep::RequiredIntTypes<double>::factorial_t(_Factorial),
            mep::RequiredIntTypes<double>::func_t(_TestFunc)
        );
        evaluator = std::make_unique<mep::Evaluator<double>>(std::move(ints));
    }
    std::unique_ptr<mep::Evaluator<double>> evaluator;
};

TEST_F(EvaluatorInsaneTests, Expressions){
    auto expr = mep::Parser<mep::RadixDecimal>::parse(mep::TokenStream<mep::RadixDecimal>("((43 - -77)/37^-94 + (-66*67)^(-24*49))/((43 - -77)/37^-94 + (-66*67)^(-24*49)) + 2.0"));
    auto val = evaluator->eval_expression(*expr);
    EXPECT_DOUBLE_EQ(val, 3.0);
}

