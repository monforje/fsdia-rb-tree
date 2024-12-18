#ifndef RBTREE_H
#define RBTREE_H

#include "src/list.h"
#include "data.h"

struct KEY {
    int series;
    int number;
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
        DoublyLinkedList list;

        RBnode(const KEY& key, COLOR color) 
            : key(key), color(color), left(nullptr), right(nullptr), parent(nullptr) {}
    };
};

#endif // RBTREE_H
