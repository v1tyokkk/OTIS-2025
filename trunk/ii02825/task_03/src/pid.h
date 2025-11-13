/**
 * @file pid.h
 * @brief Класс PID-регулятора для дискретного моделирования.
 */

#ifndef PID_H
#define PID_H

/**
 * @class PID
 * @brief Класс дискретного ПИД-регулятора.
 */
class PID {
private:
    double K;     /**< Коэффициент усиления */
    double T;     /**< Время интегрирования */
    double Td;    /**< Время дифференцирования */
    double T0;    /**< Шаг дискретизации */

    double q0; 
    double q1; 
    double q2; /**< Вспомогательные коэффициенты */

    double u_prev = 0.0;     /**< Предыдущее управляющее воздействие */
    double e_prev1 = 0.0;    /**< Предыдущая ошибка */
    double e_prev2 = 0.0;    /**< Предыдущая ошибка за два шага назад */

public:
    /**
     * @brief Конструктор PID-регулятора.
     * @param K Усиление
     * @param T Время интегрирования
     * @param Td Время дифференцирования
     * @param T0 Шаг моделирования
     */
    PID(double K_, double T_, double Td_, double T0_);

    /**
     * @brief Вычислить новое управляющее воздействие.
     * @param e Текущая ошибка
     * @return Вычисленное управляющее воздействие
     */
    double compute(double e);
};

#endif

