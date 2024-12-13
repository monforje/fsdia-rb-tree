#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* prev;
    Node* next;

    Node(std::string value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void push_back(std::string value);
    void remove(std::string value);
    void print_forward() const;
    void clear();
};

#endif