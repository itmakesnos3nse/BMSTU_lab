/*Сформировать текстовый файл с информацией о названии города, 
средней ночной и средней дневной температурах для опреджеленного месяца. 
Сформировать второй файл, куда щаписать названия городов и среднесуточной
 температурой для пяти самых холодных городов
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

struct City{
    string Name;
    double DayTemperature;
    double NightTemperature;
};

bool compare(const pair<string, float> & a, const pair<string, float> & b){ // сравнение по значению 
    return a.second < b.second;
}

int main(){
    City cities [] ={
    {"Moscow", 5.0, 15.0},
    {"London", 15.0, 15.0},
    {"Paris", -5.0, 15.0},
    {"Tokyo", -5.0, -15.0},
    {"Vien", -25.0, -15.0},
    {"Sydney", 35.0, 15.0},
    {"Beijing", -25.0, -5.0},
    {"Dubai", -35.0, -5.0},
    {"Paris", 15.0, 5.0},
    {"Berlin", 45.0, 15.0}    
};
    int n = 10;
    fstream f1;
    fstream f2;
    f1.open("C:\\Users\\Vano\\projects\\labs\\lab2_1.txt", ios::out); 
    // sort(cities, cities + sizeof(cities) / sizeof(cities[0]), compare);
    if(f1){   
        f1 << "Название города" << "\t" << "Дневная температура" << "\t" << "Ночная температура" << "\n";
        for(int i = 0; i < n; i++){
        f1 << "\t" << cities[i].Name << "\t\t\t\t\t" << cities[i].DayTemperature << "\t\t\t\t" << cities[i].NightTemperature <<  "\n";
        }
    }
    f1.close();
    map<string, float> average;
    string line;
    float sum;
    f1.open("C:\\Users\\Vano\\projects\\labs\\lab2_1.txt");
    getline(f1, line); // пропускаю заголовок
    while(getline(f1, line)){ // пока не достигнут конец файла кладу очередную строку в переменную (s)
        cout << line << endl; 
        istringstream iss(line);
        string city;
        float day_temp, night_temp;
        iss >> city >> day_temp >> night_temp;
        float avg_temp = (day_temp + night_temp) / 2.0;
        average[city] = avg_temp;

    }
    f1.close();
    for (const auto& entry : average) {
        cout << "Город: " << entry.first << ", Среднесуточная температура: " << entry.second << endl;
    }   
    vector<pair<string, float>> pairs(average.begin(), average.end());
    sort(pairs.begin(), pairs.end(), compare);
    f2.open("lab2_2.txt", ios::out);
    if(f2){
        f2 << "Самые холодные города" << "\n";
        f2 << "Название города" << "\t\t" << "Среднесуточная температура" << "\n";
        for(int i = 0; i < 5; i++){
        f2 << pairs[i].first << "\t\t\t\t\t" << pairs[i].second << "\n";
        }
    }
    
}    