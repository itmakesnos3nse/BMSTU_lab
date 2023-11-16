// lab18
#include <iostream>
#include <string>

using namespace std;


// воод элементов массива
void InputArray(int *arr, int lenght){
    for(int i = 0; i < lenght; i++){
        cin >> arr[i];
    }
}

// вывод элементов массива
void OutputArray(int *arr, int lenght){
    for(int i = 0; i < lenght; i++){
        cout << arr[i] << " ";
    }
}

// поиск индекса минимального элемента массива
int FindMinimumIndex_1(int *arr, int i, int length){
    int min, min_index;
    min = arr[i];
    min_index = i;
    for(int j = i + 1; j < length; j++){
        if(arr[j] < min){
            min = arr[j];
            min_index = j;
        }
    }
    return min_index;
}

// обмен элемнтов массива
void Swap(int &first_element, int&second_element){
    int a = second_element;
    second_element = first_element;
    first_element = a;
}

// соритировка выбором
void SelectionSort(int *arr, int lenght){
    int min_i;
    for (int i = 0; i < lenght; i++){
        min_i = FindMinimumIndex_1(arr, i, lenght);
        int &first_element = arr[i];
        int &second_element = arr[min_i];
        Swap(first_element, second_element);
    }
}

// КОНЕЦ 1 ЗАДАНИЯ

// НАЧАЛО 2 ЗАДАНИЯ

// функция сравнения
int Compare(void *first_pointer, void *second_pointer) {
    int *first_element_int_pointer = (int *)first_pointer;
    int *second_element_int_pointer = (int *)second_pointer;
    return *first_element_int_pointer - *second_element_int_pointer;

}
typedef int(*CompareFunctionType)(void*, void*);
CompareFunctionType compare_function_pointer = &Compare;

// КОНЕЦ 2 ЗАДАНИЯ

// НАЧАЛО 3 ЗАДАНИЯ

// поиск минимального индекса
int FindMinimumIndex_2(int *arr, int i, int length, CompareFunctionType compare_function_pointer){
    int min, min_index;
    min = arr[i];
    min_index = i;
    for(int j = i + 1; j < length; j++){
        if(compare_function_pointer(&arr[j], &min) < 0){
            min = arr[j];
            min_index = j;
        }
    }
    return min_index;
}


void SelectionSort_2(int *arr, int lenght, CompareFunctionType compare_function_pointer){
    int min_i;
    for (int i = 0; i < lenght; i++){
        min_i = FindMinimumIndex_2(arr, i, lenght, compare_function_pointer);
        int &first_element = arr[i];
        int &second_element = arr[min_i];
        Swap(first_element, second_element);
    }
}

// КОНЕЦ ЗАДАНИЯ 3

// НАЧАЛО ЗАДАНИЯ 4

// сравнение для сортировки по возрастанию
int CompareInt0to9 (void *first_pointer, void *second_pointer){
    int *first_element_int_pointer = (int *)first_pointer;
    int *second_element_int_pointer = (int *)second_pointer;
    return *first_element_int_pointer - *second_element_int_pointer;
}

// сравнение для сортировки по убыванию
int CompareInt9to0 (void *first_pointer, void *second_pointer){
    int *first_element_int_pointer = (int *)first_pointer;
    int *second_element_int_pointer = (int *)second_pointer;
    return -(*first_element_int_pointer - *second_element_int_pointer);

}

int FindMinimumIndex_3(int *arr, int i, int length, CompareFunctionType compare_function_pointer){
    int min, min_index;
    min = arr[i];
    min_index = i;
    for(int j = i + 1; j < length; j++){
        if(compare_function_pointer(&arr[j], &min) < 0){
            min = arr[j];
            min_index = j;
        }
    }
    return min_index;
}


void SelectionSort_3(int *arr, int lenght, CompareFunctionType compare_function_pointer){
    int min_i;
    for (int i = 0; i < lenght; i++){
        min_i = FindMinimumIndex_3(arr, i, lenght, compare_function_pointer);
        int &first_element = arr[i];
        int &second_element = arr[min_i];
        Swap(first_element, second_element);
    }
}






int main(){
    int lenght;
    cout << "Задание 1.\n";
    cout << "введите длину массива: ";
    cin >> lenght;
    cout << "введите элементы массива: ";
    int *arr = new int[lenght];
    InputArray(arr, lenght);
    SelectionSort(arr, lenght);
    OutputArray(arr, lenght);
    cout << "\n\n";
    // конец задания 1

    // начало задания 2
    int first_pointer, second_pointer;
    cout << "Задание 2.\n";
    cout << "введите 1й элемент: ";
    cin >> first_pointer;
    cout << "введите 2й элемент: ";
    cin >> second_pointer;
    if (Compare(&first_pointer, &second_pointer) < 0){
        cout << "a < b\n" << Compare(&first_pointer, &second_pointer) << "\n";
    } else if (Compare(&first_pointer, &second_pointer) == 0){
        cout << "a = b\n" << Compare(&first_pointer, &second_pointer) << "\n";
    } else if(Compare(&first_pointer, &second_pointer) > 0){
        cout << "a > b\n" << Compare(&first_pointer, &second_pointer) << "\n";
    }
    cout << "\n\n";
    //конец задания 2

    // начало задания 3
    int lenght2;
    cout << "Задание 3.\n";
    cout << "введите длину массива: ";
    cin >> lenght2;
    cout << "введите элементы массива: ";
    int *arr2 = new int[lenght2];
    InputArray(arr2, lenght2);
    SelectionSort_2(arr2, lenght2, &Compare);
    OutputArray(arr2, lenght2);
    cout << "\n\n";
    // конец задания 3
    
    // начало задания 4
    const int N = 2;
    CompareFunctionType compareFunctionPointers[N];
    // Объявить 2 функции
    compareFunctionPointers[0] = &CompareInt0to9; // по возрастанию
    compareFunctionPointers[1] = &CompareInt9to0; // по убыванию
    int lenght3;
    cout << "Задание 4.\n";
    cout << "введите длину массива: ";
    cin >> lenght3;
    int *arr3 = new int[lenght3];
    cout << "введите элементы массива: ";
    InputArray(arr3, lenght3);
    cout << "выберите вид сортировки: по возрастанию или по убыванию:\n";
    string ans;
    cin >> ans;
    if(ans == "по возрастанию"){
        SelectionSort_3(arr3, lenght3, compareFunctionPointers[0]);
    }
    else if(ans == "по убыванию"){
        SelectionSort_3(arr3, lenght3, compareFunctionPointers[1]);
    }
    else{
        cout << "неверные входные данные\n";
    }
    OutputArray(arr3, lenght3);
    // конец задания 4 (доделать)

    // начало задания 5





}