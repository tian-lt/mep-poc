#include <cmath>
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

TEST_F(CommonEvaluatorTests, Expression) {
    auto expr = aep::Parser<aep::RadixDecimal>::parse(aep::TokenStream<aep::RadixDecimal>("1.0 + 2.0 - 0.5"));
    auto val = evaluator->eval_expression(*expr);
    EXPECT_DOUBLE_EQ(val, 2.5);
}

TEST_F(CommonEvaluatorTests, Addition) {
    auto add = MockParser<aep::ast::Addition, aep::RadixDecimal, decltype(aep::details::addition)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("1.1 + 2.2"), aep::details::addition);
    auto val = evaluator->eval_addition(*add);
    EXPECT_DOUBLE_EQ(val, 3.3);

    auto add2 = MockParser<aep::ast::Addition, aep::RadixDecimal, decltype(aep::details::addition)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("1.1 + 2.2 + 3.3"), aep::details::addition);
    auto val2 = evaluator->eval_addition(*add2);
    EXPECT_DOUBLE_EQ(val2, 6.6);
}

TEST_F(CommonEvaluatorTests, Subtraction) {
    auto sub = MockParser<aep::ast::Subtraction, aep::RadixDecimal, decltype(aep::details::subtraction)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("10.0 - 9.5"), aep::details::subtraction);
    auto val = evaluator->eval_subtraction(*sub);
    EXPECT_DOUBLE_EQ(val, 0.5);

    auto sub2 = MockParser<aep::ast::Subtraction, aep::RadixDecimal, decltype(aep::details::subtraction)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("10.0 - 9.5 - 0.1"), aep::details::subtraction);
    auto val2 = evaluator->eval_subtraction(*sub2);
    EXPECT_DOUBLE_EQ(val2, 0.4);
}

TEST_F(CommonEvaluatorTests, Multiplication) {
    auto mock_parsing =
        [](const aep::details::next_f& next, const aep::details::restore_f& restore, aep::details::kac_t& kac) -> std::unique_ptr<aep::ast::Multiplication> {
        auto factor = aep::details::factor(next, restore, kac);
        kac.push(std::move(factor));
        return aep::details::multiplication(next, restore, kac);
    };
    auto mul = MockParser<aep::ast::Multiplication, aep::RadixDecimal, decltype(mock_parsing)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("1.1*2.2"), mock_parsing);
    auto val = evaluator->eval_multiplication(*mul);
    EXPECT_DOUBLE_EQ(val, 2.42);

    auto mul2 = MockParser<aep::ast::Multiplication, aep::RadixDecimal, decltype(mock_parsing)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("1.1*2.2*3.33"), mock_parsing);
    auto val2 = evaluator->eval_multiplication(*mul2);
    EXPECT_DOUBLE_EQ(val2, 8.0586);
}

TEST_F(CommonEvaluatorTests, Division) {
    auto div = MockParser<aep::ast::Division, aep::RadixDecimal, decltype(aep::details::division)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("12.3/4.56"), aep::details::division);
    auto val = evaluator->eval_division(*div);
    EXPECT_DOUBLE_EQ(val, 2.69736842105263157894);

    auto div2 = MockParser<aep::ast::Division, aep::RadixDecimal, decltype(aep::details::division)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("12.3/4.56/2.2"), aep::details::division);
    auto val2 = evaluator->eval_division(*div2);
    EXPECT_DOUBLE_EQ(val2, 1.22607655502392344497);
}

TEST_F(CommonEvaluatorTests, Factor) {
    // number
    auto factor = MockParser<aep::ast::Factor, aep::RadixDecimal, decltype(aep::details::factor)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("32.23"), aep::details::factor);
    auto val = evaluator->eval_factor(*factor);
    EXPECT_DOUBLE_EQ(val, 32.23);

    // TODO:
    // exponentiation
    // postfix unary expression
}

TEST_F(CommonEvaluatorTests, PostfixUnaryExpression) {
    auto post = MockParser<aep::ast::PostfixUnaryExpression, aep::RadixDecimal, decltype(aep::details::postfix_unary_expression)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("3!"), aep::details::postfix_unary_expression);
    auto val = evaluator->eval_postfix_unary_expression(*post);
    EXPECT_DOUBLE_EQ(val, 6);

    auto post2 = MockParser<aep::ast::PostfixUnaryExpression, aep::RadixDecimal, decltype(aep::details::postfix_unary_expression)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("2^3%"), aep::details::postfix_unary_expression);
    auto val2 = evaluator->eval_postfix_unary_expression(*post2);
    EXPECT_DOUBLE_EQ(val2, 0.08);
}

TEST_F(CommonEvaluatorTests, Exponentiation) {
    auto exp = MockParser<aep::ast::Exponentiation, aep::RadixDecimal, decltype(aep::details::exponentiation)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("2^3"), aep::details::exponentiation);
    auto val = evaluator->eval_exponentiation(*exp);
    EXPECT_DOUBLE_EQ(val, 8.0);

    auto exp2 = MockParser<aep::ast::Exponentiation, aep::RadixDecimal, decltype(aep::details::exponentiation)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("4^0.5"), aep::details::exponentiation);
    auto val2 = evaluator->eval_exponentiation(*exp2);
    EXPECT_DOUBLE_EQ(val2, 2.0);
}

TEST_F(CommonEvaluatorTests, Function) {
    auto func1 = MockParser<aep::ast::Function, aep::RadixDecimal, decltype(aep::details::function)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("test(1, 2, 3)"), aep::details::function);
    auto val = evaluator->eval_function(*func1);
    EXPECT_DOUBLE_EQ(val, 6.0);
}

TEST_F(CommonEvaluatorTests, Number) {
    aep::Token tok{.token_type = aep::TokenType::DecimalFloat, .payload = std::string("123.456")};
    auto val = evaluator->eval_number(tok);
    EXPECT_DOUBLE_EQ(val, 123.456);
}

TEST_F(CommonEvaluatorTests, Atom) {
    // number
    auto atom = MockParser<aep::ast::Atom, aep::RadixDecimal, decltype(aep::details::atom)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("123.45"), aep::details::atom);
    auto val = evaluator->eval_atom(*atom);
    EXPECT_DOUBLE_EQ(val, 123.45);
}

TEST_F(CommonEvaluatorTests, PrefixUnaryExpression) {
    auto prefix = MockParser<aep::ast::PrefixUnaryExpression, aep::RadixDecimal, decltype(aep::details::prefix_unary_expression)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("+23"), aep::details::prefix_unary_expression);
    auto val = evaluator->eval_prefix_unary_expression(*prefix);
    EXPECT_DOUBLE_EQ(val, 23);

    auto prefix2 = MockParser<aep::ast::PrefixUnaryExpression, aep::RadixDecimal, decltype(aep::details::prefix_unary_expression)>::parse_proxy(
        aep::TokenStream<aep::RadixDecimal>("-32"), aep::details::prefix_unary_expression);
    auto val2 = evaluator->eval_prefix_unary_expression(*prefix2);
    EXPECT_DOUBLE_EQ(val2, -32);
}


