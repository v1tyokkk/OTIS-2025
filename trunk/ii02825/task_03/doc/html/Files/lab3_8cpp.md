---
title: src/lab3.cpp

---

# src/lab3.cpp



## Namespaces

| Name           |
| -------------- |
| **[std](Namespaces/namespacestd.md)**  |

## Functions

|                | Name           |
| -------------- | -------------- |
| int | **[main](Files/lab3_8cpp.md#function-main)**()<br>Основная функция моделирования PID-регулятора.  |


## Functions Documentation

### function main

```cpp
int main()
```

Основная функция моделирования PID-регулятора. 

**Return**: Код завершения программы (0 — успешное выполнение). 

Функция выполняет последовательность шагов:

1. Считывание входных параметров пользователя.
2. Инициализация PID-регулятора.
3. Запуск цикла моделирования.
4. Вычисление ошибки e = w - y.
5. Получение управляющего воздействия u.
6. Обновление состояния объекта через линейную модель.
7. Вывод промежуточных результатов.


< Начальная температура объекта

< Коэффициент модели — сохранение предыдущего состояния

< Коэффициент модели — влияние управляющего воздействия

< Целевая температура

< Количество шагов моделирования

< Усиление

< Время интегрирования

< Время дифференцирования

< Шаг дискретизации

< Экземпляр PID-регулятора

< Текущее состояние объекта

< Ошибка управления

< Управляющее воздействие

< Обновлённое состояние объекта




## Source code

```cpp


#include <iostream>
#include "pid.h"
#include "model.h"

using namespace std;

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

    // Параметры PID-регулятора
    double K  = 0.4;  
    double T  = 3.0;  
    double Td = 0.1;  
    double T0 = 1.0;  

    PID pid(K, T, Td, T0);  

    double y1 = y0; 

    for (int k = 0; k < steps; k++) {
        double e = w - y;          
        double u = pid.compute(e); 
        y1 = linear(y, u, a, b);    

        cout << "Step " << k
             << "  e=" << e
             << "  u=" << u
             << "  y=" << y1 << endl;
    }

    return 0;
}
```


-------------------------------

Updated on 2025-11-21 at 11:50:33 +0300
