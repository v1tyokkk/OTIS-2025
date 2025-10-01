#include <iostream>
#include <cmath>

int main()
{
    double u;
    double y;
    std::cout << "Enter u(input warm) and y(input temperature): " << std::endl;
    std::cin >> u >> y;

    double a;
    double b; 
    double c;
    double d;
    std::cout << "Enter a,b,c,d(some constants): " << std::endl;
    std::cin >> a >> b >> c >> d;

    int count;
    std::cout << "Enter the number of steps: " << std::endl;
    std::cin >> count;

    double yl = y;
    double ynl = y;
    for (int i = 0; i < count; i++)
    {
        yl = a * yl + b * u;
        ynl = a * ynl - b * ynl * ynl + c * u + d * std::sin(u);

        std::cout << "Result of the " << i + 1 << " step of linear model: " << yl << ";\n";
        std::cout << "Result of the " << i + 1 << " step of non-linear model: " << ynl << ";\n";
    }

    return 0;
}