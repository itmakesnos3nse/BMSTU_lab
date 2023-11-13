// решение с использованием векторов
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// функция подсчета среднего арифметического модулей элементов
double ArithmeticMean(const vector<vector<double>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    double sum = 0.0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            sum += abs(matrix[i][j]);
        }
    }
    double arithmetic_mean = sum / (m * n);
    return arithmetic_mean;
}

// функция подсчета среднего геометрического элементов
double GeometricMean(const vector<vector<double>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    double x = 1.0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            x *= abs(matrix[i][j]);
        }
    }

    double geometric_mean = pow(x, 1.0 / (m * n));
    return geometric_mean;
}

// функция вывода массива
void printArray(const vector<double> ans, int n)
{
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main() {
    vector<double> ans;
    int m, n;
    cout << "Введите количество строк <= 10 и количество столбцов <= 12: ";
    cin >> m;
    cin >> n;
    if (m > 10 || n > 12 || n < 1 || m < 1){
        cout << "Введены некорректные числа.";
        exit;
    }
    // заполнение матрицы
    int x;
    vector<vector<double>> matrix(m, vector<double>(n));
    cout  << "Введите элементы матрицы: ";
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> x;
            matrix[i][j] = x;
        }
    }
    // вывод матрицы
     for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    ans.push_back(ArithmeticMean(matrix));
    ans.push_back(GeometricMean(matrix));
    printArray(ans, 2);
}
