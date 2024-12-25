#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
//Паспорт
struct Pasport {
    int series;
    int number;
};
//Размер массива = 20
const int SIZE = 20;
//Метод для чтения файла
void readFile(const string& filename, Pasport* arr, int& count);

#endif