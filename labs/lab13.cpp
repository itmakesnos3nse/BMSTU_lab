#include <iostream>
#include <vector>

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
    int x, i = 2;
    vector<int> nums1;
    vector<int> nums2;
    cout << "Введите число: ";
    cin >> x;
    if (x >= 2){
        cout << "1) через while: " << FirstElwhile(x) << endl;
        cout << "1) через for: " << Firstelfor(x) << endl;
        i = 2;
        while (i <= x)
        {
            if (x % i == 0)
            {
                nums1.push_back(i);
            }
            ++i;
        }
        cout << "2) через while: ";
        for (int elem : nums1)
        {
            cout << elem << " ";
        } 
        cout << endl;
        for (int i = 2; i <= x; ++i) 
        {
            if (x % i == 0)
            {
                nums2.push_back(i);
            }
        }
        cout << "2) через for: ";
        for (int elem : nums2)
        {
            cout << elem << " ";
        } 
        cout << endl;
        bool answh = true;
        bool ansfr = true;
        for (int i = 2; i <= x/2; ++i){
            if (x % i == 0){
                ansfr = false;
                break;
            }
        }
        if (ansfr){
            cout << "3) через for: простое\n";
        } else{
            cout << "3) через for: не простое\n";
        }
        i = 2;
        while (i < x)
        {
            if (x % i == 0){
                answh = false;
                break;
            }
            ++i;
        }
        if (answh){
            cout << "3) через while: простое\n";
        } else{
            cout << "3) через while: не простое\n";
        }
    }   
    return 0;
}