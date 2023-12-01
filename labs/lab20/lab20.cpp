#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Account {
    string name;
    int num;
};

void randomFilling(Account arr[], int len){
    string Name[] = {"Антон", "Илья", "Иван", "Никита", "Игорь", "Григорий", 
    "Алексей", "Роман", "Кирилл", "Дмитрий"};
    string Patronymic[] = {"Игоревич", "Алексеевич", "Александрович", "Иванович", "Петрович", "Владимирович", 
    "Сергеевич", "Вадимович", "Николаевич", "Викторович"};
    string Surname[] = {"Иванов", "Смирнов", "Кузнецов", "Попов", "Васильев", "Петров", "Соколов",
     "Михайлов", "Новиков", "Фёдоров",};
    for(int i = 0; i < len; i++){
        arr[i].name = Name[rand()%10] + " " + Patronymic[rand() % 10] + " " + Surname[rand() % 10];
        arr[i].num = abs(rand() % 10000);
    }

}

void swap(Account &i1, Account &i2){
    Account tmp = i1;
    i1 = i2;
    i2 = tmp;
}

void insertionSort(Account arr[], int len){
    for(int i = 1; i < len; i++){
        for(int j = i; j > 0 && arr[j - 1].num < arr[j].num; j--){
            swap(arr[j-1], arr[j]);
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int len;
    cout << "введите длину списка: ";
    cin >> len;
    Account arr[len];
    randomFilling(arr, len);
    cout << "неотсортированный массив: \n";
    for(int i = 0; i < len; i++){
        cout << "ФИО: " << arr[i].name << "  Номер счета: " << arr[i].num << endl;
    }
    cout << endl;
    insertionSort(arr, len);
    cout << "отсортированный массив: \n";
    for(int i = 0; i < len; i++){
        cout << "ФИО: " << arr[i].name << "  Номер счета: " << arr[i].num << endl;
    }
}