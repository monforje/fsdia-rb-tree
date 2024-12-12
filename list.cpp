#include <iostream>
using namespace std;

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
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        clear();
    }

    // Добавление элемента в конец
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail) { // Если список пуст
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Удаление элемента по значению
    void remove(int value) {
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

    // Печать списка вперед
    void print_forward() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Очистка списка
    void clear() {
        while (head) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        tail = nullptr;
    }
};

int main() {

    DoublyLinkedList dll;

    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.push_back(2);
    dll.push_back(4);

    cout << "Исходный список: ";
    dll.print_forward();

    dll.remove(2);
    cout << "После удаления первого 2: ";
    dll.print_forward();

    dll.remove(4);
    cout << "После удаления 4: ";
    dll.print_forward();

    return 0;
}
