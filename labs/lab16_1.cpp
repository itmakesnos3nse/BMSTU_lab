#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//создем константные значения m и n - размеры матрицы. они нужны для того чтобы задать размеры матрицы m x n.
const unsigned int m = 3;
const unsigned int n = 3;

// Функция для ввода значений в динамический массив размера m x n
void inputMatrix(double** matrix, const int m, const int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Введите значение для элемента (" << i << ", " << j << "): ";
            double value;
            cin >> value;
            matrix[i][j] = value;
        }
    }
}

// функция вывода матрицы
void outputMatrix(double **matrix, const int m, const int n){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

// функция для подсчета среднего арифметического модулей элементов матрицы
double ArithmeticMean(double** matrix, const int m, const int n){
    double sum = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            sum += abs(matrix[i][j]);
        }
    }
    double arithmetic_mean = sum / (m * n);
    return arithmetic_mean;
}

// функция для подсчета среднего геометрического модулей элементов матрицы
double GeometricMean(double** matrix, const int m, const int n) {
    double x = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            x *= abs(matrix[i][j]);
        }
    }

    double geometric_mean = pow(x, 1.0 / (m * n));
    return geometric_mean;
}

// функция для создания статического массива, произведения расчетов и вывода.
void stat(double arr[m][n]){
    vector<double> ans;
    // ввод значений
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Введите значение для элемента (" << i << ", " << j << "): ";
            double value;
            cin >> value;
            arr[i][j] = value;
        }   
    }    
    // подсчет среднего арифметического модулей
    double sum = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            sum += abs(arr[i][j]);
        }
    }
    // подсчет среднего геометрического модулей
    double arithmetic_mean = sum / (m * n);
    double x = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            x *= abs(arr[i][j]);
        }
    }

    double geometric_mean = pow(x, 1.0 / (m * n));
    //вычисление подходящих по условию значений и создание массива из них
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((abs(arr[i][j]) >= geometric_mean) && (abs(arr[i][j]) <= arithmetic_mean)){
                ans.push_back(abs(arr[i][j]));
            }
        }
    }
    // вывод массива удовлетворяющих элеметов
    cout << "Элементы удовлетворяющие условию:" << endl;
    for (auto i: ans){
        cout << i << " ";
    }
}

int main() {
    vector<double> ans;
    double** matrix = new double*[m]; // создаем динамический массив (он реализуется как одномерный массив указателей)
    double static_matrix[m][n]; // создаем статический массив
    for (int i = 0; i < m; i++) {
        matrix[i] = new double[n];
    }

    inputMatrix(matrix, m, n);
    cout << "Матрица:" << endl;
    outputMatrix(matrix, m, n);
    double arithmetic = ArithmeticMean(matrix, m, n);
    double geometric = GeometricMean(matrix, m, n);
    cout << "Среднее арифметическое модулей элементов и среднее геометрическое модулей элементов матрицы" << endl;
    cout << arithmetic << " " << geometric << endl;
    // находим элементы которые находятся между средним геометрическим и средним арифметическим
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((abs(matrix[i][j]) >= geometric) && (abs(matrix[i][j]) <= arithmetic)){
                ans.push_back(abs(matrix[i][j]));
            }
        }
    }
    cout << "Элементы удовлетворяющие условию:" << endl;
    for (auto i: ans){
        cout << i << " ";
    }
    cout << "Статистический массив:" << endl; 
    stat(static_matrix);
}
