#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double y1, y2, x;
    double a = 1.5;
    cout << "Введите x: ";
    cin >> x;
    y1 = (pow(a, x) * pow(x, a) + 2 * pow(a, 2 * x) * pow(x, a) - 2 * pow(a, x) * pow(x, 2 * a) - 4 * pow(a, 2 * x) * pow(x, 2 * a)) / (log10(a) + log10(x));
    double x2a = pow(x, 2 * a);
    double a2x = pow(a, 2 * x);
    double xa = pow(x, a);
    double ax = pow(a, x);
    double znam = log10(a) + log10(x);
    double chisl = ax * xa + 2 * a2x * xa - 2 * ax * x2a - 4 * a2x * x2a;
    y2 = chisl/znam;
    cout << "Y1 = " << y1 << "\n";
    cout << "Y2 = " << y2;
    return 0;
}
