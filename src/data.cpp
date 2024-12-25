#include "data.h"

void readFile(const string& filename, Pasport* arr, int& count) {
    //Валидация
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    string line;
    int lineNumber = 0;
    count = 0;
    //Считывание со строк
    while (getline(inputFile, line)) {
        lineNumber++;
        istringstream iss(line);
        int series, number;

        if (!(iss >> series >> number)) {
            cerr << "Ошибка формата в строке " << lineNumber << ": " << line << endl;
            continue;
        }
        //Проверка на формат паспорта
        if ((series < 1000 || series > 9925) || (number < 100000 || number > 999999)) {
            cerr << "Ошибка: Номер группы должен быть в диапазоне в строке: " << lineNumber << endl;
            continue;
        }
        //Проверка на количество данных
        if (count < SIZE) {
            arr[count].series = series;
            arr[count].number = number;
            count++;
        } else {
            cerr << "Размер массива превышен." << endl;
            break;
        }
    }

    inputFile.close();
}