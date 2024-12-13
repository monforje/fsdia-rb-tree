#include "src/list.h"

int main() {
    DoublyLinkedList dll;

    dll.push_back("1");
    dll.push_back("2");
    dll.push_back("3");
    dll.push_back("2");
    dll.push_back("4");

    std::cout << "Initial list: ";
    dll.print_forward();

    dll.remove("2");
    std::cout << "After removing the first 2: ";
    dll.print_forward();

    dll.remove("4");
    std::cout << "After removing 4: ";
    dll.print_forward();

    dll.clear();
    std::cout << "After clearing the list: ";
    dll.print_forward();

    return 0;
}
