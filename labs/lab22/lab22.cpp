/*Создать файл, состоящий из структур с информацией о книгах библиотеки.
Структура содержит следующие поля: название книги, автор, год издания.
Выполнить ввод в файл исходных данных. Предусмотреть добавление новых структур в конец файла.
Обеспечить просмотр содержимого файла. Обеспечить выдачу информации о книгах автора по запросу. 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct library_data
{
    string book;
    string author;
    int year;
};

int main(){
    
    library_data library [] = {
    {"Война и мир", "Л.Н. Толстой", 1869},
    {"Анна Каренина", "Л.Н. Толстой", 1877},
    {"Отцы и дети", "Л.Н. Толстого", 1862},
    {"Евгений Онегин", "А.С. Пушкин", 1833},
    {"Горе от ума", "А.С. Грибоедов", 1825},
    {"Обломов", "И.А. Гончаров",  1859},
    {"Маленькие трагеди", "А.С. Пушкин", 1830},
    {"Бесы", "Ф.М. Достоевский", 1872},
    {"Братья", "Ф.М. Достоевский", 1880},
    {"Мертвые души", "Н.В. Гоголь", 1842}    
    };  
    int n = 10;
    // запись исходных данных 
    FILE* file= fopen("lab3.bin", "wb");
    fwrite(library, sizeof *library, n, file);
    fclose(file);
    //чтение данных из файла
    library_data library2[n];
    FILE* file2 = fopen("lab3.bin", "rb");
    const size_t ret_code = fread(library2, sizeof library2[0], n, file2);
    if (ret_code == n){
        for (int i = 0; i < n; i++){
            cout << library[i].book << " " << library[i].author << " " << library[i].year << endl;
        }
        cout << "введите фамилию, имя отчество автора(кратко): ";
        string in_name;
        cin >> in_name;
        for (int i = 0; i < n; i++){
            if (library[i].author == in_name){
                cout << library[i].book << " " << library[i].author << " " << library[i].year << endl;
            }
        }
    }
    fclose(file2);
}