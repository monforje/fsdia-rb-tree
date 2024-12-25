#include "list.h"

using namespace List; // Используем пространство имен List

// Конструктор
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Деструктор
DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

// Вставка в конец
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

// Удаление элемента
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

// Печать списка в прямом направлении
void DoublyLinkedList::print_forward() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Очистка списка
void DoublyLinkedList::clear() {
    while (head) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    tail = nullptr;
}