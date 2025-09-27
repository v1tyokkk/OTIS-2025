#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double u, y;
    cout << "Enter u(input warm) and y(input temperature): " << endl;
    cin >> u >> y;

    double a, b, c, d;
    cout << "Enter a,b,c,d(some constants): " << endl;
    cin >> a >> b >> c >> d;

    int count;
    cout << "Enter the number of steps: " << endl;
    cin >> count;

    double yl = y, ynl = y;
    for (int i = 0; i < count; i++)
    {
        yl = a * yl + b * u;
        ynl = a * ynl - b * ynl * ynl + c * u + d * sin(u);

        cout << "Result of the " << i + 1 << " step of linear model: " << yl << ";\n";
        cout << "Result of the " << i + 1 << " step of non-linear model: " << ynl << ";\n";
    }

    return 0;
}