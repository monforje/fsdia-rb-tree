#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;
//Двусвязный список
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    //Вставка
    void push_back(int value);
    //Удаление
    void remove(int value);
    //Печать
    void print_forward() const;
    //Очистка
    void clear();
};

#endif