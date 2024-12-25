#ifndef RBTREE_H
#define RBTREE_H

#include "list.h"
#include "data.h"
#include <iostream>
#include <queue>
#include <utility>

enum COLOR { RED, BLACK };

struct KEY {
    Data data;
    DoublyLinkedList list;
};

class RBtree {
private:
    struct RBnode {
        KEY key;
        COLOR color;
        RBnode* left;
        RBnode* right;
        RBnode* parent;

        RBnode(const KEY& key, COLOR color)
            : key(key), color(color), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    RBnode* root;

    void rotateLeft(RBnode*& node);
    void rotateRight(RBnode*& node);
    void fixInsert(RBnode*& node);
    void printHelper(RBnode* root, std::string indent, bool last);
    RBnode* findMin(RBnode* node);

public:
    RBtree();
    void insert(const KEY& key);
    void delete_max_left();
    void search_RBnode(const KEY& key);
    void print_RBtree();
    void direct_bypass_RBtree();
    void printTree();
    void visualizeTree(); // Визуализация дерева
    void generateGraphviz(const std::string& filename);
    void generateGraphvizHelper(RBnode* node, std::ofstream& file);
};

#endif
