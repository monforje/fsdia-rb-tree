#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// Структура для хранения данных паспорта
struct Pasport {
    int series; // Серия паспорта (4 цифры)
    int number; // Номер паспорта (6 цифр)
};

// Максимальный размер массива для хранения данных
const int SIZE = 20;

// Метод для чтения данных из файла в массив
void readFile(const string& filename, Pasport* arr, int& count);

#endif