#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double Pr_one(double x){
    double a = cos(x) * log(2 * + pow(sin(x) , 2));
    double b = (2 * pow(sin(x) , 2) * cos(x)) / (2 + pow(sin(x), 2));
    double c = pow(log(2 + pow(sin(x), 2)), 2);
    double y = (a - b) / c;
    return y;
}

double Pr_two(double x){
    double y = ((cos(x) + log(2 + pow(sin(x), 2))) - (2 * pow(sin(x) , 2) * cos(x)) / (2 + pow(sin(x), 2))) /
    pow(log(2 + pow(sin(x), 2)), 2);
    return y;
}

double Func(double x) {
    double y = sin(x) / (log(2 + pow(sin(x), 2)));
    return y;
}

int main() {
    double x;
    vector <double> data = {0.0005, 0.001, 0.002, 0.004, 0.008, 0.016};
    vector <double> Dy;
    vector <double> pr_zn;
    vector <double> absolute;
    vector <double> Dx;

    cout << "Введите x: ";

    cin >> x;
    double ans1 = Pr_one(x);
    double ans2 = Pr_two(x);
    int i = 0;
    while (i < 5){
        Dx.push_back(Pr_one(data[i]));
        ++i;
    }
    i = 0;
    while (i < 5){
        Dy.push_back(Func(x + (data[i]/2)) - Func(x - (data[i]/2)));
        ++i;
    }    
    i = 0;
    while (i < 5){
        pr_zn.push_back(Dy[i] / data[i]);
        ++i;
    }
    i = 0;
    while (i < 5){
        absolute.push_back(ans1 - pr_zn[i]);
        ++i;
    }
    i = 0;
    cout << "X" << "\t" << "DX" << "\t" << "Y'(1)" << "\t\t" << "Y'(2)" << "\t\t" << "Для DX" << "\t\t" << "DY" << "\t\t" << "Приближенные значения" << "\t  " << "Абсолютные значения"<< endl;
    while (i < 5){
        cout << x << "\t" << data[i] << "\t" << ans1 << "\t" << ans1 << "\t" << Dx[i] << "\t" << Dy[i] << "\t\t" << pr_zn[i] << "\t\t" << absolute[i] << endl;
        ++i;
    }
    return 0;
}