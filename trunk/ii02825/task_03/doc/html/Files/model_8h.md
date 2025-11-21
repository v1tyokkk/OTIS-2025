---
title: src/model.h
summary: Линейная модель объекта 

---

# src/model.h

Линейная модель объекта 

## Functions

|                | Name           |
| -------------- | -------------- |
| double | **[linear](Files/model_8h.md#function-linear)**(double y, double u, double a, double b)<br>Линейная модель объекта.  |


## Functions Documentation

### function linear

```cpp
double linear(
    double y,
    double u,
    double a_1,
    double b
)
```

Линейная модель объекта. 

**Parameters**: 

  * **y** Текущая температура 
  * **u** Управляющее воздействие 
  * **a** Коэффициент влияния температуры 
  * **b** Коэффициент влияния управления 
  * **y** Текущее значение состояния объекта. 
  * **u** Управляющее воздействие. 
  * **a** Коэффициент влияния предыдущего состояния. 
  * **b** Коэффициент влияния управляющего воздействия.


**Return**: 

  * Новое значение температуры
  * Новое значение параметра объекта. 



Функция рассчитывает новое состояние системы на основе текущего значения ( y ) и управляющего воздействия ( u ).




## Source code

```cpp


#ifndef MODEL_H
#define MODEL_H

double linear(double y, double u, double a_1, double b);

#endif
```


-------------------------------

Updated on 2025-11-21 at 11:50:33 +0300
