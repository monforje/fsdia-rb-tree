#ifndef DATA_H
#define DATA_H

#include <string>
#include <fstream>

struct KEY {
    int series;
    int number;
};

class ReadFromFile() {
    void file(const std::string& filename) {

    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }

    int line, lineNumber = 0;

    while (std::getline(inputFile, line)) {
        lineNumber++;
        std::istringstream iss(line);
        int series, number;

        if (!(iss >> series >> number)) {
            std::cerr << "Ошибка формата в строке " << lineNumber << ": " << line << std::endl;
            continue;
        }

            if ((series < 1000 || series > 9925) || (number < 100000 || 999999)) {
                std::cerr << "Ошибка: Номер группы должен быть четырёхзначным числом в строке: " << lineNumber << std::endl;
                continue;
            }
        } else {
            std::cerr << "Ошибка чтения строки: " << lineNumber << std::endl;
        }
    

    }

    inputFile.close();
}

#endif