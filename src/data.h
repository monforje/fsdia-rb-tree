#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

struct Data {
    int series;
    int number;
};

const int SIZE = 100;

class ReadFromFile {
public:
    void readFile(const std::string& filename, Data* dataArray, int& count);
};

#endif