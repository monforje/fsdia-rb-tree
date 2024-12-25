#include "src/red-black.h"
#include "src/data.h"
#include <iostream>

int main() {
    // Чтение данных из файла
    const std::string filename = "data.txt";
    Data dataArray[SIZE];
    int count = 0;

    ReadFromFile reader;
    reader.readFile(filename, dataArray, count);

    // Проверка, есть ли данные для обработки
    if (count == 0) {
        std::cerr << "Данные из файла не загружены. Программа завершена." << std::endl;
        return 1;
    }

    // Создание красно-черного дерева
    RBtree tree;

    // Вставка данных в дерево
    for (int i = 0; i < count; ++i) {
        KEY key = {dataArray[i], DoublyLinkedList()};
        tree.insert(key);
    }

    // Печать дерева
    std::cout << "Дерево после заполнения данными:" << std::endl;
    tree.print_RBtree();

    // Пример поиска
    std::cout << "\nПоиск первого ключа из файла:" << std::endl;
    tree.search_RBnode({dataArray[0], DoublyLinkedList()});

    // Удаление максимального слева
    std::cout << "\nУдаление максимального слева:" << std::endl;
    tree.delete_max_left();

    // Печать дерева после удаления
    std::cout << "\nДерево после удаления максимального слева:" << std::endl;
    tree.print_RBtree();

    // Прямой обход дерева
    std::cout << "\nПрямой обход дерева:" << std::endl;
    tree.direct_bypass_RBtree();

    std::cout << "Визуализация дерева:" << std::endl;
    tree.visualizeTree();

    // Визуализация дерева
    tree.generateGraphviz("rb_tree.dot");
    std::cout << "Дерево сгенерировано в файле rb_tree.dot. Используйте Graphviz для визуализации." << std::endl;



    return 0;
}