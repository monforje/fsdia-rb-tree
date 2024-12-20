#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// Структура для хранения данных
struct Data {
    int series;
    int number;
};

// Константа для максимального размера массива
const int SIZE = 100;

// Класс для чтения данных из файла
class ReadFromFile {
public:
    // Метод для чтения данных из файла
    void readFile(const std::string& filename, Data* dataArray, int& count);
};

#endif