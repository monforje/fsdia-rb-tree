#ifndef RED_BLACK_H
#define RED_BLACK_H

#include <iostream>
#include <fstream>
#include "data.h"
#include "list.h"
using namespace std;

// Узел для дерева поиска
struct KEY {
    Pasport data;
    List::DoublyLinkedList lineNumbers;

    KEY(Pasport data) : data(data) {}
};

struct TreeNode {
    KEY key;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    bool isRed;

    TreeNode(KEY key) : key(key), parent(nullptr), left(nullptr), right(nullptr), isRed(true) {}
};

class RedBlackTree {
private:
    TreeNode* root;
    TreeNode* TNULL;

    void initializeTNULL();
    void balanceInsert(TreeNode* node);
    void balanceDelete(TreeNode* node);
    TreeNode* searchTreeHelper(TreeNode* node, const Pasport& key) const;
    void deleteNodeHelper(TreeNode* node, const Pasport& key);
    void leftRotate(TreeNode* x);
    void rightRotate(TreeNode* x);
    void clearHelper(TreeNode* node);
    void inorderTraversal(TreeNode* node, ostream& os) const;

public:
    RedBlackTree();
    ~RedBlackTree();

    void insert(const Pasport& key, int lineNumber);
    void remove(const Pasport& key);
    bool search(const Pasport& key) const;
    void print(ostream& os = cout) const;
    void clear();
    void exportToDotHelper(TreeNode* node, std::ofstream& file);
    void exportToDotHelper(TreeNode* node, std::ofstream& file) const;
    void exportToDot(const std::string& filename) const;
};

#endif