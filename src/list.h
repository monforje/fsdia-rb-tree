#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

namespace List {

// Узел для списка
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

    void push_back(int value);
    void remove(int value);
    void print_forward() const;
    void clear();
};

} // namespace List

#endif