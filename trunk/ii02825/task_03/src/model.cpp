#include "model.h"

/**
 * @brief Линейная модель объекта
 */
double linear(double y, double u, double a, double b)
{
    return a * y + b * u;
}
