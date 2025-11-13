#include <iostream>
#include "pid.h"
#include "model.h"

using namespace std;

/**
 * @brief Основная программа моделирования ПИД-регулятора.
 */
int main() {
    double y0;
    double a;
    double b;

    cout << "Enter initial temperature y: ";
    cin >> y0;

    cout << "Enter a and b for linear model: ";
    cin >> a >> b;

    double w;  
    cout << "Enter target temperature w: ";
    cin >> w;

    int steps;
    cout << "Enter number of simulation steps: ";
    cin >> steps;

    double K  = 0.4;
    double T  = 3.0;
    double Td = 0.1;
    double T0 = 1.0;

    PID pid(K, T, Td, T0);
    double y = y0;

    for (int k = 0; k < steps; k++) {
        double e = w - y;
        double u = pid.compute(e);
        y = linear(y, u, a, b);

        cout << "Step " << k
             << "  e=" << e
             << "  u=" << u
             << "  y=" << y << endl;
    }

    return 0;
}
