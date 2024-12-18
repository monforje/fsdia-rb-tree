#include <iostream>
#include "src/list.h"

struct KEY {
    int data;
    DoublyLinkedList list;
};

enum COLOR { red, black };

class RBtree {
private:
    struct RBnode { 
        KEY key;
        COLOR color;
        RBnode* left;
        RBnode* right;
        RBnode* parent;
    };
};
