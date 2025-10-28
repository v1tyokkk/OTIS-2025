#include <gtest/gtest.h>
#include <cmath>
#include "functions.h"

// Тесты линейной модели
TEST(LinearModelTest, BaseCase) {
    EXPECT_NEAR(linear(0.1, 0.3, 0.5, 0.0), 0.05, 1e-6);
}

TEST(LinearModelTest, WithNonZeroY) {
    EXPECT_NEAR(linear(0.2, 0.4, 2.0, 1.0), 1.0, 1e-6);
}

// Тесты нелинейной модели
TEST(NonlinearModelTest, BaseCase) {
    double result = non_linear(0.0, 0.1, 0.5, 0.2, 0.3, 0.1);
    double expected = 0.5*0.0 - 0.2*0.0*0.0 + 0.3*0.1 + 0.1*std::sin(0.1);
    EXPECT_NEAR(result, expected, 1e-6);
}

TEST(NonlinearModelTest, WithValues) {
    double result = non_linear(0.4, 0.2, 0.5, 0.2, 0.3, 0.1);
    double expected = 0.5*0.4 - 0.2*0.4*0.4 + 0.3*0.2 + 0.1*std::sin(0.2);
    EXPECT_NEAR(result, expected, 1e-6);
}
