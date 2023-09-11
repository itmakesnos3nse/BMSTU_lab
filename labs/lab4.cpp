#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x;
    double y, y2, a, b, c;
    cout << "Введите значение x: ";
    cin >> x;
    a = x + pow(x, 3) - 3;
    b = 2 * pow(x, 2) - 4 * x + 2;
    c = 6 * pow(x, 3) - 4 * pow(x, 5);
    y = a / (b + c);
    y2 = ((x + pow(x, 3)) - 3) / (2 * pow(x, 2) - 4 * x + 2 + 6 * pow(x, 3) - 4 * pow(x, 5));
    cout << "y = " << y << "\n";
    cout << "y2 = " << y2;
    return 0;
}