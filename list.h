#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <string>

// Узел списка
struct Node {
    std::string data;        // Данные узла
    Node* prev;      // Указатель на предыдущий узел
    Node* next;      // Указатель на следующий узел

    Node(std::string value) : data(value), prev(nullptr), next(nullptr) {}
};

// Класс для работы с двусвязным списком
class DoublyLinkedList {
private:
    Node* head;      // Указатель на первый элемент
    Node* tail;      // Указатель на последний элемент

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Добавление элемента в конец
    void push_back(std::string value);

    // Удаление элемента по значению
    void remove(std::string value);

    // Печать списка вперед
    void print_forward() const;

    // Очистка списка
    void clear();
};

#endif // DOUBLY_LINKED_LIST_H
