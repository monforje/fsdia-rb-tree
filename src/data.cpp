#include "data.h"

void readFile(const std::string& filename, Data* dataArray, int& count) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }

    std::string line;
    int lineNumber = 0;
    count = 0;

    while (std::getline(inputFile, line)) {
        lineNumber++;
        std::istringstream iss(line);
        int series, number;

        if (!(iss >> series >> number)) {
            std::cerr << "Ошибка формата в строке " << lineNumber << ": " << line << std::endl;
            continue;
        }

        if ((series < 1000 || series > 9925) || (number < 100000 || number > 999999)) {
            std::cerr << "Ошибка: Номер группы должен быть в диапазоне в строке: " << lineNumber << std::endl;
            continue;
        }

        if (count < SIZE) {
            dataArray[count].series = series;
            dataArray[count].number = number;
            count++;
        } else {
            std::cerr << "Размер массива превышен." << std::endl;
            break;
        }
    }

    inputFile.close();
}