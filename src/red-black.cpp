#include <iostream>
#include "src/list.h"
#include "src/data.h"

struct KEY {
    Data data;
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

