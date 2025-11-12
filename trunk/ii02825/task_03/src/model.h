/**
 * @file model.h
 * @brief Линейная модель объекта
 */

#ifndef MODEL_H
#define MODEL_H

/**
 * @brief Линейная модель объекта.
 * @param y Текущая температура
 * @param u Управляющее воздействие
 * @param a Коэффициент влияния температуры
 * @param b Коэффициент влияния управления
 * @return Новое значение температуры
 */
double linear(double y, double u, double a, double b);

#endif
