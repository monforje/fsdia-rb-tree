#include "src/data.h"

int main() {
    Data passports[SIZE];
    int count = 0;

    readFile("data.txt", passports, count);

    std::cout << "Считано записей: " << count << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << "Серия: " << passports[i].series << ", Номер: " << passports[i].number << std::endl;
    }

    return 0;
}