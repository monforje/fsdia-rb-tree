#ifndef RBTREE_H
#define RBTREE_H

#include "src/list.h"
#include "data.h"

enum COLOR { red, black };

class RBtree {
private:
    struct RBnode { 
        Data key;
        COLOR color;
        RBnode* left;
        RBnode* right;
        RBnode* parent;
        DoublyLinkedList list;

        RBnode(const KEY& key, COLOR color) 
            : key(key), color(color), left(nullptr), right(nullptr), parent(nullptr) {}
    };

public:
    //Вставка
    void insert_RBnode() {}; 
    //Удаление максимаьлного слева
    void delete_max_left() {};
    //Поиск ключа
    void search_RBnode() {};
    //Печать дерева
    void print_RBtree() {};
    //Прямой обход дерева
    void direct_bypass_RBtree() {};
};



#endif // RBTREE_H
