#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class file_open_error {};
class file_write_error {};
class data_read_error {};
class grades_read_error {};

using namespace std;

struct Student {
    string surname;
    int exams;
    vector<int> grades;
};

double calculateAverageGrade(const Student& student) {
    int sum = 0;
    int count = 0;
    for (int grade : student.grades) {
        if (grade != 2) {
            sum += grade;
            count++;
        }
    }
    return count > 0 ? static_cast<double>(sum) / count : 0.0;
}

int main() {
    try {
        ifstream inputFile("students.txt");
        if (!inputFile.is_open()) {
            throw file_open_error();
        }

        vector<Student> students;
        string line;
        while (getline(inputFile, line)) {
            istringstream iss(line);
            Student student;
            if (!(iss >> student.surname >> student.exams)) {
                throw data_read_error();
            }
            student.grades.resize(student.exams);
            for (int& grade : student.grades) {
                if (!(iss >> grade)) {
                    throw grades_read_error();
                }
            }
            students.push_back(student);
        }
        inputFile.close();

        double totalAverage = 0.0;
        int totalStudents = 0;
        for (const Student& student : students) {
            double average = calculateAverageGrade(student);
            if (average > 0) {
                totalAverage += average;
                totalStudents++;
            }
        }
        totalAverage /= totalStudents;

        ofstream outputFile("results.txt");
        if (!outputFile.is_open()) {
            throw file_open_error();
        }

        for (const Student& student : students) {
            double average = calculateAverageGrade(student);
            if (average > totalAverage) {
                bool hasTwos = false;
                for (int grade : student.grades) {
                    if (grade == 2) {
                        hasTwos = true;
                        break;
                    }
                }
                if (!hasTwos) {
                    outputFile << student.surname << std::endl;
                }
            }
        }
        if (outputFile.tellp() == 0) {
        throw file_write_error();
    } 
        outputFile.close();
    }
    catch(file_open_error()){
        cerr << "Ошибка чтения файла";
    }
    catch(data_read_error()){
        cerr << "Ошибка чтения данных студента";
    }
    catch(grades_read_error()){
        cerr << "Ошбика чтения оценок студента";
    }
    catch(file_write_error()){
        cerr << "Ошбика. Пустой файл";
    }
    

    return 0;
}    