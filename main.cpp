#include "src/data.h"

int main() {
    Pasport passports[SIZE];
    int count = 0;

    readFile("src/data.txt", passports, count);

    cout << "Считано записей: " << count << endl;
    for (int i = 0; i < count; i++) {
        cout << "Серия: " << passports[i].series << ", Номер: " << passports[i].number << endl;
    }

    return 0;
}