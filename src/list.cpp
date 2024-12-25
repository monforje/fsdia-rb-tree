#include "list.h"

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}
//Деструктор
DoublyLinkedList::~DoublyLinkedList() {
    clear();
}
//Вставка
void DoublyLinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
//Удаление
void DoublyLinkedList::remove(int value) {
    Node* current = head;

    while (current) {
        if (current->data == value) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }

            delete current;
            return;
        }
        current = current->next;
    }
}
//Печать
void DoublyLinkedList::print_forward() const {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
//Очистка
void DoublyLinkedList::clear() {
    while (head) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    tail = nullptr;
}