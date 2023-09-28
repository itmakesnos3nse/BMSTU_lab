#include <iostream>
#include <cmath>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    
    cout << "Введите координаты вершин треугольника (x1, y1): " << endl;
    cin >> x1 >> y1;
    cout << "Введите координаты вершин треугольника (x2, y2): " << endl;
    cin >> x2 >> y2;
    cout << "Введите координаты вершин треугольника (x3, y3): " << endl;
    cin >> x3 >> y3;

    if (x1 == x2 && y1 == y2 && x2 == x3 && y2 == y3) {
        cout << "Некорректные данные (введена одна точка)" << endl;
    } else if ((x1 == x2 && y1 == y2)|| (x2 == x3 && y2 == y3) || (x1 == x3 && y1 == y3))
    {
        cout << "Некорректные данные (введено две точки)" << endl;
    }else
     {
        //длины сторон
        double side1 = distance(x1, y1, x2, y2);
        double side2 = distance(x2, y2, x3, y3);
        double side3 = distance(x3, y3, x1, y1);

        //прямоуголный
        bool isRightTriangle = false;
        if (side1 == sqrt(side2*side2 + side3*side3) ||
            side2 == sqrt(side1*side1 + side3*side3) ||
            side3 == sqrt(side1*side1 + side2*side2)) {
            isRightTriangle = true;
        }

        // равнобедренный
        bool isIsoscelesTriangle = ((side1 == side2) || (side2 == side3) || (side3 == side1));

        // вырожденный
        bool isDegenerateTriangle = ((side1 + side2 == side3) || (side1 + side3 == side2) || (side2 + side3 == side1));

        // равносторонний
        bool isEquilateralTriangle = ((side1 == side2) && (side2 == side3));

        if (isRightTriangle == 1)
        {
            cout << "Прямоугольный";
            exit;
        }else if (isDegenerateTriangle == 1)
        {
            cout << "Вырожденный";
            exit;
        }else if (isIsoscelesTriangle == 1)
        {
            cout << "Равнобедренный";
            exit;
        }else if (isEquilateralTriangle == 1)
        {
            cout << "Равносторонний";
            exit;
        }
        
    }

    return 0;
}
