#include <iostream>
#include <cmath>
using namespace std;

int FirstElwhile (int x, int i = 2) {
    while (x % i != 0){
        i += 1;
    } 
    return i;
}

int Firstelfor (int x, int q, int i = 2) {
    for (int i1 = 2; i1 < x; ++i1) {
        if (x % i1 == 0) {
            q = i1;
            exit;
        }
    }
    return q;
}


int main() {
    int x;
    cout << "Введите число: ";
    cin >> x;
    if (x >= 2){
        cout << "1) через while: " << FirstElwhile(x) << endl;
        cout << "1) через for: " << FirstElwhile(x) << endl;
    }
    return 0;
}