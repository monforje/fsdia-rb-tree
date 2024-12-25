#include <iostream>
#include "src/data.h"
#include "src/list.h"
#include "src/red-black.h"

using namespace std;

void displayMenu() {
    cout << "==== Меню ====" << endl;
    cout << "1. Загрузить данные из файла" << endl;
    cout << "2. Добавить элемент" << endl;
    cout << "3. Удалить элемент" << endl;
    cout << "4. Найти элемент" << endl;
    cout << "5. Печать дерева" << endl;
    cout << "6. Очистить дерево" << endl;
    cout << "7. Экспортировать дерево в Graphviz (DOT-файл)" << endl;
    cout << "0. Выйти" << endl;
    cout << "Введите ваш выбор: ";
}

int main() {
    RedBlackTree tree;
    string filename;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Введите имя файла: ";
                string filename = "src/data.txt";

                Pasport passports[SIZE];
                int count = 0;

                readFile(filename, passports, count);
                for (int i = 0; i < count; i++) {
                    tree.insert(passports[i], i + 1);
                }

                cout << "Данные загружены в дерево." << endl;
                break;
            }
            case 2: {
                Pasport passport;
                int lineNumber;

                cout << "Введите серию паспорта (4 цифры): ";
                cin >> passport.series;
                cout << "Введите номер паспорта (6 цифр): ";
                cin >> passport.number;
                cout << "Введите номер строки: ";
                cin >> lineNumber;

                tree.insert(passport, lineNumber);
                cout << "Элемент добавлен." << endl;
                break;
            }
            case 3: {
                Pasport passport;

                cout << "Введите серию паспорта (4 цифры): ";
                cin >> passport.series;
                cout << "Введите номер паспорта (6 цифр): ";
                cin >> passport.number;

                tree.remove(passport);
                cout << "Элемент удалён (если он существовал)." << endl;
                break;
            }
            case 4: {
                Pasport passport;

                cout << "Введите серию паспорта (4 цифры): ";
                cin >> passport.series;
                cout << "Введите номер паспорта (6 цифр): ";
                cin >> passport.number;

                if (tree.search(passport)) {
                    cout << "Элемент найден." << endl;
                } else {
                    cout << "Элемент не найден." << endl;
                }
                break;
            }
            case 5: {
                cout << "Текущее дерево (прямой обход):" << endl;
                tree.print();
                break;
            }
            case 6: {
                tree.clear();
                cout << "Дерево очищено." << endl;
                break;
            }
            case 7: {
                string outputFilename;
                cout << "Введите имя файла для экспорта (например, tree.dot): ";
                cin >> outputFilename;

                tree.exportToDot(outputFilename);
                cout << "Дерево экспортировано в " << outputFilename << endl;
                cout << "Для визуализации используйте Graphviz:" << endl;
                cout << "dot -Tpng " << outputFilename << " -o tree.png" << endl;
                break;
            }
            case 0: {
                cout << "Выход из программы." << endl;
                break;
            }
            default: {
                cout << "Некорректный выбор. Попробуйте снова." << endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}