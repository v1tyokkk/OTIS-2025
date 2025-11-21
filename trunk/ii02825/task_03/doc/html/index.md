# API Reference

## Header files

- [src/model.h](#file-srcmodelh)
- [src/pid.h](#file-srcpidh)

## File src/model.h

_Линейная модель объекта_




## Functions

| Type | Name |
| ---: | :--- |
|  double | [**linear**](#function-linear) (double y, double u, double a, double b) <br>_Линейная модель объекта._ |



## Functions Documentation

### function `linear`

_Линейная модель объекта._
```c
double linear (
    double y,
    double u,
    double a,
    double b
) 
```


**Parameters:**


* `y` Текущая температура 
* `u` Управляющее воздействие 
* `a` Коэффициент влияния температуры 
* `b` Коэффициент влияния управления 


**Returns:**

Новое значение температуры


Функция рассчитывает новое состояние системы на основе текущего значения ( y ) и управляющего воздействия ( u ).



**Parameters:**


* `y` Текущее значение состояния объекта. 
* `u` Управляющее воздействие. 
* `a` Коэффициент влияния предыдущего состояния. 
* `b` Коэффициент влияния управляющего воздействия.


**Returns:**

Новое значение параметра объекта.


## File src/pid.h











