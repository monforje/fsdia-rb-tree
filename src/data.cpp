#include "data.h"

// Вывод сообщения об ошибке
void logError(const string& message) {
    cerr << "Ошибка: " << message << endl;
}

void readFile(const string& filename, Pasport* arr, int& count) {
    ifstream inputFile(filename);
    if (!inputFile) {
        logError("Не удалось открыть файл: " + filename);
        return;
    }

    string line;
    int lineNumber = 0;
    count = 0;

    while (getline(inputFile, line)) {
        lineNumber++;
        istringstream iss(line);
        int series, number;

        if (!(iss >> series >> number)) {
            logError("Некорректный формат данных в строке " + to_string(lineNumber) + ": " + line);
            continue;
        }

        if ((series < 1000 || series > 9925) || (number < 100000 || number > 999999)) {
            logError("Неверный формат серии или номера паспорта в строке " + to_string(lineNumber));
            continue;
        }

        if (count < SIZE) {
            arr[count].series = series;
            arr[count].number = number;
            count++;
        } else {
            logError("Достигнут предел размера массива.");
            break;
        }
    }

    inputFile.close();
}