#include <iostream>

using namespace std;

// выделение памяти
int ***AllocateLargeMemoryBlockFor3DArray (int height, int width, int depth) {
    int * large_memory_block = new int[ height * width * depth ];
    int ***my_3d_array = new int**[ height ];
        for (int row_index = 0; row_index < height; ++row_index) {
            my_3d_array [ row_index] = new int * [ width ];
            for (int column_index = 0; column_index < width; ++column_index) {
                my_3d_array [row_index][column_index] = &large_memory_block [(row_index *width + column_index ) * depth];
            }
        }       
    return my_3d_array;
}

// удаление памяти
void FreeLargeMemoryBlockFor3DArray (int ***my_3d_array, int height, int width, int depth) {
    int * large_memory_block = &my_3d_array [0][0][0];
    delete [] large_memory_block;
    for (int row_index = 0; row_index < height; ++row_index) {
        delete [] my_3d_array[row_index];
    }
    delete [] my_3d_array;
}


// ввод динамического массива и одновременный вывод в консоль
void Input3DDynamicArray (int ***my_3d_array, int height, int width, int depth) {
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            for(int k = 0; k < depth; k++){
                my_3d_array[i][j][k] = rand() % 100;
            }
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            for(int k = 0; k < depth; k++){
                cout << my_3d_array[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

// ввод статического массива и одновременный вывод в консоль
void Input3DStaticArray (int my_3d_array[], int height, int width, int depth) {
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            for(int k = 0; k < depth; k++){
                my_3d_array[i * height + j * width + k] = rand() % 100;
            }
        }
    }
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            for(int k = 0; k < depth; k++){
                cout << my_3d_array[i * height + j * width + k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

/* 
выделение и освобождение памяти по другому: 
место под массив указателей выделяется отдельно.
*/ 

int ***AllocateSecond(int height, int width, int depth){
    int*** my_3d_array = new int**[height];
    int** first_level_pointers_memory_block = new int* [ height * width ];
    int* data_memory_block = new int[height * width * depth];
    for(int i = 0; i < height; i++){
        my_3d_array[i] = &first_level_pointers_memory_block[width * i];
        for(int j = 0; j < width; j++){
            my_3d_array[i][j] = &data_memory_block[i *width + j* depth];
        }
    }
    return my_3d_array;
}

void FreeMemorySecond(int*** my_3d_array, int height, int width, int depth){
    int *data_memory_block = &my_3d_array [0][0][0];
    int **first_level_pointers_memory_block = &my_3d_array [0][0];
    delete[] data_memory_block;
    delete[] first_level_pointers_memory_block;
    delete[] my_3d_array;
}


int main(){
    srand(static_cast<unsigned>(time(nullptr)));
    int height, width, depth;
    cout << "Введите высоту: ";
    cin >> height;
    cout << "Введите ширину: ";
    cin >> width;
    cout << "Введите глубину: ";
    cin >> depth;
    // int*** arr = AllocateLargeMemoryBlockFor3DArray(height, width, depth);
    int*** arr = AllocateSecond(height, width, depth);
    cout << "Динамическйи массив\n";
    Input3DDynamicArray(arr, height, width, depth);
    cout << "Статический массив\n";
    Input3DStaticArray(&arr[0][0][0], height, width, depth);
    // FreeLargeMemoryBlockFor3DArray(arr, height, width, depth);
    FreeMemorySecond(arr, height, width, depth);
}