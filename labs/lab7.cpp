#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float x;
    cout << "Введите x: ";
    cin >> x;
    if (x <= -2){
        cout << "Y1 = 0" << "\n";
    } 
    if (-2 < x)
    {
        if (x < -1)
        {
           cout << "Y1 = -1" << "\n";
        }
    } 
    if (-1 < x)
    {
        if (x < 1)
        {
            cout << "Y1 = 1" << "\n";
        }
        
    } 
    if (1 <= x)
    {
        if (x < 2)
        {
            cout << "Y1 = -1" << "\n";
        }
    }
    if (x >= 2)
    {
        cout << "Y1 = 0" << "\n";
    }
    if ((x <= -2) or (x >= 2))
    {
        cout << "Y2 = 0" << "\n";
    } else if (((-2 < x) and (x <= -1)) or ((1 <= x) and (x < 2)))
    {
        cout << "Y2 = -1" << "\n";
    } else if ((-1 < x) and (x < 1))
    {
        cout << "Y2 = 1" << "\n";
    }
    return 0;    
}