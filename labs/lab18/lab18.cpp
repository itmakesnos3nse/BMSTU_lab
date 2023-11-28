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

// КОНЕЦ ЗАДАНИЯ 4

// НАЧАЛО ЗАДАНИЯ 5

// функция для ввода элементов типа char
void InputArrayChar(char *arr, int length){
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }
}

// функця для вывода элементов массива типа char
void OutputArrayChar(char *arr, int lenght){
    for (int i = 0; i < lenght; i++){
        cout << arr[i] << " ";
    }
}

// функция для свапа элементов типа char
void SwapChar(char *first_pointer, char *second_pointer){
    char a = *second_pointer;
    *second_pointer = *first_pointer;
    *first_pointer = a;
}

// функция для сравнения элементов типа char которые являются цифрами
int CompareChar0to9(void *first_pointer, void *second_pointer){
    int *first_element_int_pointer = (int*)first_pointer;
    int *second_element_int_pointer = (int*)second_pointer;
    return *first_element_int_pointer - *second_element_int_pointer;
}

// функция для сравнения элементов типа char которые являются буквами
int CompareCharAtoZ(void *first_pointer, void*second_pointer){
    char *first_element_char_pointer = (char*)first_pointer;
    char *second_element_char_pointer = (char*)second_pointer;
    return *first_element_char_pointer - *second_element_char_pointer;
}

int FindMinimumIndex_5(void *data_array, int length, int width, CompareFunctionType compare_function_pointer, int first_index, int last_index) {
    char *bytevise_array = (char *)data_array;
    int minimum_index = first_index;
    int minimum_byte_number = minimum_index * width;
    int current_byte_number = 0;
    for (int element_number = first_index; element_number <= last_index; ++element_number) {
        current_byte_number = element_number * width;
        if ((*compare_function_pointer) ( &bytevise_array [current_byte_number],&bytevise_array [minimum_byte_number]) < 0 ) {
             minimum_byte_number = current_byte_number;
        }
    }
    minimum_index = minimum_byte_number / width;
return minimum_index;
}

void Swap_5(void *first_pointer, void *second_pointer, int width) {
    for (int byte_number = 0; byte_number < width; ++byte_number) {
        SwapChar((char *)first_pointer + byte_number, (char *)second_pointer + byte_number);
    }
    return;
}

void SelectionSort_5(void *data_array, int length, int width, CompareFunctionType compare_function_pointer){
    int min_i;
    for(int i = 0; i < length; i++){
        min_i = FindMinimumIndex_5(data_array, length, width, compare_function_pointer, i, length - 1);
        if (min_i != i) {
            Swap_5((char *)data_array + i * width, (char *)data_array + min_i * width, width);
        }
    }
}

// конец задания 5

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
    delete[] arr; // очистка памяти после использования динамического массива
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
    delete[] arr2;

    // конец задания 3
    
    // начало задания 4
    const int N = 2;
    CompareFunctionType compareFunctionPointers[N];
    compareFunctionPointers[0] = &CompareInt0to9; // по возрастанию
    compareFunctionPointers[1] = &CompareInt9to0; // по убыванию
    int lenght3;
    cout << "Задание 4.\n";
    cout << "введите длину массива: ";
    cin >> lenght3;
    int *arr3 = new int[lenght3];
    cout << "введите элементы массива: ";
    InputArray(arr3, lenght3);
    cout << "выберите вид сортировки: по возрастанию(0to9) или по убыванию(9to0):\n";
    string ans;
    cin >> ans;
    if(ans == "0to9"){
        SelectionSort_3(arr3, lenght3, compareFunctionPointers[0]);
        OutputArray(arr3, lenght3);
    }
    else if(ans == "9to0"){
        SelectionSort_3(arr3, lenght3, compareFunctionPointers[1]);
        OutputArray(arr3, lenght3);
    }
    else{
        cout << "неверные входные данные\n";
    }
    delete[] arr3;

    // конец задания 4 

    // начало задания 5
    int lenght5;
    cout << "Введите тип данных(char/int): ";
    string typ;
    cin >> typ;
    if(typ == "int"){
        cout << "Введите длину: ";
        cin >> lenght5;
        int *arr5 = new int[lenght5];
        InputArray(arr5, lenght5);
        SelectionSort_5(arr5, lenght5, sizeof(arr5[0]), CompareChar0to9);
        OutputArray(arr5, lenght5); 
        delete[] arr5;
    } else if(typ == "char"){
        cout << "Введите длину: ";
        cin >> lenght5;
        char *arr5 = new char[lenght5];
        InputArrayChar(arr5, lenght5);
        SelectionSort_5(arr5, lenght5, sizeof(arr5[0]), CompareCharAtoZ);
        OutputArrayChar(arr5, lenght5);
        delete[] arr5;
    } else{
        cout << "Некорректные данные.\n";
    }

}