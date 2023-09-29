#include <iostream>
#include <cmath>
#include <list>
#include <iterator>

using namespace std;

int FirstElwhile (int x, int i = 2) {
    while (x % i != 0){
        i += 1;
    } 
    return i;
}

int Firstelfor (int x, int i = 2) {
    for (int i1 = 2; i1 <= x; ++i1) {
        if (x % i1 == 0) {
            return i1;
            exit;
        }
    }
    return 0;
}


int main() {
    int x;
    list<int> nums1;
    list<int> nums2;
    cout << "Введите число: ";
    cin >> x;
    if (x >= 2){
        cout << "1) через while: " << FirstElwhile(x) << endl;
        cout << "1) через for: " << Firstelfor(x) << endl;
    }   
    return 0;
}