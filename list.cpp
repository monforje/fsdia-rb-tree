#include "list.h"

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if (!tail) { // Если список пуст
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoublyLinkedList::remove(int value) {
    Node* current = head;

    while (current) {
        if (current->data == value) {
            if (current->prev) {
                current->prev->next = current->next;
            } else { // Удаляемый элемент - голова
                head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            } else { // Удаляемый элемент - хвост
                tail = current->prev;
            }

            delete current;
            return; // Завершаем после удаления первого совпадения
        }
        current = current->next;
    }
}

void DoublyLinkedList::print_forward() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::clear() {
    while (head) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    tail = nullptr;
}