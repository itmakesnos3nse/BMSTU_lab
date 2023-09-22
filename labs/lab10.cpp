#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    int x1, x2, x3, ans;
    cout << "Введите 3 двухзначных числа: ";
    cin >> x1 >> x2 >> x3;
    if (x1 > 0 && x1 < 100 && x2 > 0 && x2 < 100 && x3 > 0 && x3 < 100)
    {
        int x12 = x1 % 10;
        int x11 = x1 / 10;
        int x21 = x2 / 10;
        int x22 = x2 % 10;
        int x31 = x3 / 10;
        int x32 = x3 % 10;
        if (x11 * x12 <= x21 * x22)
        {
            ans = 1000 * x11 + 100 * x12 + 10 * x21 + x22;
            cout << ans;
        } else if ((x21 * x22 <= x22 * x31) && (x22 * x31 <= x31 * x32)){
            ans = 1000 * x21 + 100 * x22 + 10 * x31 + x32;
            cout << ans;
        }else if ((x11 * x12 <= x12 * x31) && (x12 * x31 <= x31 * x32)){
            ans = 1000 * x11 + 100 * x12 + 10 * x31 + x32;
            cout << ans;
        }else if ((x31 * x32 <= x32 * x21) && (x32 * x21 <= x21 * x22)){
            ans = 1000 * x31 + 100 * x32 + 10 * x21 + x22;
            cout << ans;
        }else if ((x21 * x22 <= x22 * x11) && (x22 * x11 <= x11 * x12)){
            ans = 1000 * x21 + 100 * x22 + 10 * x11 + x12;
            cout << ans;
        }else if ((x31 * x32 <= x32 * x11) && (x32 * x11 <= x11 * x12)){
            ans = 1000 * x31+ 100 * x32 + 10 * x11 + x21;
            cout << ans;
        }else{
            cout << "такое число составить нельзя";
        }
    } else 
    {
        cout << "Некорректно введены данные.\n";
    }
    return 0;
}