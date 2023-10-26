#include <iostream>
using namespace std;

// функция добавления нового элемента
void insert(int arr[], int n, int x)
{
    int i = 0;
    while (i < n && arr[i] < x)
        i++;
    for (int j = n; j > i; j--)
        arr[j] = arr[j - 1];
    arr[i] = x;
}

// функция вывода элемента
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[20] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = 10;
    int x;
    cout << "Исходный массив: " << endl;
    printArray(arr, n);
    cout << "Введите новый элемент: " << endl;
    cin >> x;
    insert(arr, n, x);
    n++; 
    cout << "Измененный массив: " << endl;
    printArray(arr, n);
    return 0;
}
