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
        aep::required_int_t<double> ints(
            aep::RequiredIntTypes<double>::number_t(aep::token_to_double_converter),
            aep::RequiredIntTypes<double>::positive_t([](const double& operand){ return operand; }),
            aep::RequiredIntTypes<double>::negative_t([](const double& operand){ return -operand; }),
            aep::RequiredIntTypes<double>::add_t([](const double& lhs, const double& rhs) { return lhs + rhs; }),
            aep::RequiredIntTypes<double>::sub_t([](const double& lhs, const double& rhs) { return lhs - rhs; }),
            aep::RequiredIntTypes<double>::mul_t([](const double& lhs, const double& rhs) { return lhs * rhs; }),
            aep::RequiredIntTypes<double>::div_t([](const double& lhs, const double& rhs) { return lhs / rhs; }),
            aep::RequiredIntTypes<double>::pow_t([](const double& base, const double& exp){ return std::pow(base, exp); }),
            aep::RequiredIntTypes<double>::percent_t([](const double& operand){ return operand/100.0; }),
            aep::RequiredIntTypes<double>::factorial_t(_Factorial),
            aep::RequiredIntTypes<double>::func_t(_TestFunc)
        );
        evaluator = std::make_unique<aep::Evaluator<double>>(std::move(ints));
    }
    std::unique_ptr<aep::Evaluator<double>> evaluator;
};

TEST_F(EvaluatorInsaneTests, Expressions){
    auto expr = aep::Parser<aep::RadixDecimal>::parse(aep::TokenStream<aep::RadixDecimal>("((43 - -77)/37^-94 + (-66*67)^(-24*49))/((43 - -77)/37^-94 + (-66*67)^(-24*49)) + 2.0"));
    auto val = evaluator->eval_expression(*expr);
    EXPECT_DOUBLE_EQ(val, 3.0);
}

