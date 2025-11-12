#include "../src/pid.h"
#include "../src/model.h"
#include <gtest/gtest.h>
#include <cmath>

// Тест модели объекта

TEST(ModelTest, LinearModelBasic) {
    double y = 10;
    double u = 5;
    double a = 0.9;
    double b = 0.1;

    double result = linear(y, u, a, b);
    EXPECT_DOUBLE_EQ(result, a * y + b * u);
}

TEST(ModelTest, LinearModelZeroInput) {
    EXPECT_DOUBLE_EQ(linear(20, 0, 0.9, 0.1), 0.9 * 20);
}

//Тесты PID — проверка корректности коэффициентов

TEST(PIDTest, CoefficientsCorrect) {
    double K = 1.0;
    double T = 2.0;
    double Td = 0.5;
    double T0 = 1.0;

    PID pid(K, T, Td, T0);

    double u1 = pid.compute(1.0);
    double u2 = pid.compute(1.0);

    EXPECT_NEAR(u1, u2, 5.0);
}

//Тест PID поведения во времени

TEST(PIDSystemTest, SystemStabilizes) {
    double K  = 1.2;
    double T  = 1.0;
    double Td = 0.1;
    double T0 = 1.0;

    PID pid(K, T, Td, T0);

    double y = 20;     // стартовая температура
    double w = 50;     // заданная температура
    double a = 0.9;    // объект
    double b = 0.1;

    for (int i = 0; i < 50; i++) {
        double e = w - y;
        double u = pid.compute(e);
        y = linear(y, u, a, b);
    }

    EXPECT_NEAR(y, 50, 5); 
}
