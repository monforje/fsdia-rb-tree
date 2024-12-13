#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

// Узел списка
struct Node {
    int data;        // Данные узла
    Node* prev;      // Указатель на предыдущий узел
    Node* next;      // Указатель на следующий узел

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
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
    void push_back(int value);

    // Удаление элемента по значению
    void remove(int value);

    // Печать списка вперед
    void print_forward() const;

    // Очистка списка
    void clear();
};

#endif // DOUBLY_LINKED_LIST_H
