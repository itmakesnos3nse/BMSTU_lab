#include <iostream>
#include <cmath>
using namespace std;

// x + ln(x/3) = 0
// g(x) = -ln(x/3)
// g'(x) = -1/x
// f'(x) = 1 + 1/x
// f''(x) = -1/(x^2)

void easy_iterations(double x0, double eps) {
    double x1, y;
    int i = 1;
    if ((fabs(-1 * log(x0/3) + eps) - (-1) * log(x0/3)/eps) < 1){
        do
        {
            x1 = x0;
            x0 = -1 * log(x0/3);
            i++;
        } while (fabs(x1 - x0) > eps);
    }
    cout << "количество итераций: "<< i << endl;
    cout << "значение корня: " << x1 << endl;
    cout << "значение фунуции в корне: " << x1 + log(x1/3) << endl;
}


void tangents(double x0, double eps){
    int i = 1;
    if (((x0 + log(x0/3)) * ((-1)/(x0 * x0))) > 0) {
    double x1 = x0 - ((x0 + log(x0/3)) /(1 + (1/x0)));
    while (fabs(x0 - x1) < eps){
        ++i;
        x1 = x0 - ((x0 + log(x0/3)) /(1 + (1/x0)));  
    }
    cout << "количество итераций: "<< i << endl;
    cout << "значение корня: " << x1 << endl;
    cout << "значение фунуции в корне: " << x1 + log(x1/3) << endl;
    }
    else{
    cout << "корней нет" << endl;
    }
}


int main() {
    double eps, x0;
    cout << "Введите X: ";
    cin >> x0;
    cout << "Введите требуемую точность: ";
    cin >> eps;
    easy_iterations(x0, eps);
    tangents(x0, eps);
    return 0;
}
