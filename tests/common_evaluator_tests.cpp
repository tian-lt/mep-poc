#include "gtest/gtest.h"

#include "parser.hpp"
#include "evaluator.hpp"

TEST(CommonEvaluatorTests, Addition) {

}

TEST(CommonEvaluatorTests, Number) {
    mep::Token tok{.token_type = mep::TokenType::DecimalFloat, .payload = std::string("123.456")};
    auto val = mep::eval_number<double>(tok, mep::token_to_double_converter);
    EXPECT_FLOAT_EQ(val, 123.456);

    const auto& conv = [](const bool&)->int { return 234; };
    auto val2 = mep::eval_number<int, bool, decltype(conv)>(false, conv);
    EXPECT_EQ(val2, 234);
}


