#include <gtest/gtest.h>
#include "../src/functions.h"
#include <cmath>

TEST(LinearTest, PositiveValues) {
    EXPECT_DOUBLE_EQ(linear(2.0, 3.0, 1.0, 2.0), 1.0 * 2.0 + 2.0 * 3.0);
}

TEST(LinearTest, NegativeValues) {
    EXPECT_DOUBLE_EQ(linear(-2.0, -3.0, 2.0, 3.0), 2.0 * (-2.0) + 3.0 * (-3.0));
}

TEST(LinearTest, ZeroValues) {
    EXPECT_DOUBLE_EQ(linear(0.0, 0.0, 2.0, 3.0), 0.0);
}

TEST(NonLinearTest, BasicCalculation) {
    double result = non_linear(2.0, 3.0, 1.0, 0.5, 2.0, 1.0);
    double expected = 1.0 * 2.0 - 0.5 * 2.0 * 2.0 + 2.0 * 3.0 + 1.0 * std::sin(3.0);
    EXPECT_NEAR(result, expected, 1e-9);
}

TEST(NonLinearTest, ZeroInput) {
    EXPECT_DOUBLE_EQ(non_linear(0.0, 0.0, 1.0, 1.0, 1.0, 1.0), 0.0);
}

TEST(NonLinearTest, NegativeValues) {
    double y = -2.0, u = -3.0;
    double result = non_linear(y, u, 1.0, 1.0, 1.0, 1.0);
    double expected = 1.0 * y - 1.0 * y * y + 1.0 * u + 1.0 * std::sin(u);
    EXPECT_NEAR(result, expected, 1e-9);
}
