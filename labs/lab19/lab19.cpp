#include <iostream>

using namespace std;

int notrecursiveFibb(int n){
    if(n <= 0){
        return -1;
    }else if (n == 1){
        return 0;
    }else if (n == 2){
        return 1;
    }else{
        int a = 0;
        int b = 1;
        for(int i = 2; i < n; i++){
            int tmp = a;
            a = b;
            b = tmp + b; 
        }
        return b;
    }
}

int recursivreFibb(int n){
    if(n <= 0){
        return -1;
    }else if (n == 1){
        return 0;
    }else if (n == 2){
        return 1;
    }else{
        return recursivreFibb(n-1) + recursivreFibb(n-2);
    }
}

int main() {
    int n;
    cout << "Введите номер последовательности Фиббоначи: ";
    cin >> n;
    cout << "Не рекурсивная функция: ";
    cout << notrecursiveFibb(n) << endl;
    cout << "Рекурсивная функция: ";
    cout << recursivreFibb(n) << endl;
}