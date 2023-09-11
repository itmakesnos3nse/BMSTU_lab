#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

int main() {
    int r, n;
    float s, s1, deeg;
    cout << "Введите количество сторон: ";
    cin >> n;
    cout << "Введите радиус описанной окружности: ";
    cin >> r;
    deeg = ((360 / n) * M_PI) / 180;
    s = ((n * pow(r, 2)) / 2) * sin((deeg));
    s1 = M_PI * pow(r, 2);
    float s2 = 1 - (s / s1);
    cout << "Площадь правильного " << n << " угольника равна: " << s << "\n";
    cout << "Относительная ошибка замены площади круга площадью " << n << " угольника равна: " << s2 << "\n";
}