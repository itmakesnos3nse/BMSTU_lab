/*Сформировать текстовый файл с информацией о названии города, 
средней ночной и средней дневной температурах для опреджеленного месяца. 
Сформировать второй файл, куда щаписать названия городов и среднесуточной
 температурой для пяти самых холодных городов
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct City{
    string Name;
    double DayTemperature;
    double NightTemperature;
    double AverageTemperature;
};
bool compare(const City& a, const City& b) {
    return a.AverageTemperature < b.AverageTemperature;
}


int main(){
    City cities [] ={
    {"City1", 5.0, 15.0, 10.0},
    {"City2", 15.0, 15.0, 15.0},
    {"City3", -5.0, 15.0, 5.0},
    {"City4", -5.0, -15.0, -10.0},
    {"City5", -25.0, -15.0, -10.0},
    {"City6", 35.0, 15.0, 25.0},
    {"City7", -25.0, -5.0, -15.0},
    {"City8", -35.0, -5.0, -20.0},
    {"City9", 15.0, 5.0, 10.0},
    {"City10", 45.0, 15.0, 30.0}
};
    int n = 10;
    fstream f1("lab2_1.txt");
    fstream f2("lab2_2.txt");
    f1.open("C:\\Users\\Vano\\projects\\labs\\lab2_1.txt", ios::out); 
    sort(cities, cities + sizeof(cities) / sizeof(cities[0]), compare);
    if(f1){   
        for(int i = 0; i < n; i++){
        f1 << cities[i].Name << "\n";
        }
    }
    f1.close();
    vector <string> citieslist;
    f1.open("C:\\Users\\Vano\\projects\\labs\\lab2_1.txt");
    string a;
    n = 0;
    if(f1){
        while(!f1.eof()){
            if(n<5){
            f1 >> a;
            cout << a;
            citieslist.push_back(a);
		    n++;
            }else break;
    }
	f1.close();
    }
    f2.open("C:\\Users\\Vano\\projects\\labs\\lab2_2.txt", ios::out); 
    if(f2){   
        for(int i = 0; i < n; i++){
        f2 << citieslist[i] << "\n";
        }
    }
    f2.close();
}

