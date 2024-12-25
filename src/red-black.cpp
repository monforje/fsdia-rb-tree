#include "red-black.h"

// Инициализация пустого узла
void RedBlackTree::initializeTNULL() {
    TNULL = new TreeNode(KEY(Pasport{0, 0}));
    TNULL->isRed = false;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
}

RedBlackTree::RedBlackTree() {
    initializeTNULL();
    root = TNULL;
}

RedBlackTree::~RedBlackTree() {
    clear();
    delete TNULL;
}

// Левый поворот
void RedBlackTree::leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    x->right = y->left;

    if (y->left != TNULL) {
        y->left->parent = x;
    }

    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

// Правый поворот
void RedBlackTree::rightRotate(TreeNode* x) {
    TreeNode* y = x->left;
    x->left = y->right;

    if (y->right != TNULL) {
        y->right->parent = x;
    }

    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }

    y->right = x;
    x->parent = y;
}

// Балансировка после добавления узла
void RedBlackTree::balanceInsert(TreeNode* node) {
    TreeNode* uncle;
    while (node->parent && node->parent->isRed) {
        if (node->parent == node->parent->parent->left) {
            uncle = node->parent->parent->right;
            if (uncle && uncle->isRed) {
                node->parent->isRed = false;
                uncle->isRed = false;
                node->parent->parent->isRed = true;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->isRed = false;
                node->parent->parent->isRed = true;
                rightRotate(node->parent->parent);
            }
        } else {
            uncle = node->parent->parent->left;
            if (uncle && uncle->isRed) {
                node->parent->isRed = false;
                uncle->isRed = false;
                node->parent->parent->isRed = true;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->isRed = false;
                node->parent->parent->isRed = true;
                leftRotate(node->parent->parent);
            }
        }
    }
    root->isRed = false;
}

// Добавление нового узла
void RedBlackTree::insert(const Pasport& key, int lineNumber) {
    TreeNode* node = new TreeNode(KEY(key));
    node->parent = nullptr;
    node->left = TNULL;
    node->right = TNULL;
    node->isRed = true;

    TreeNode* y = nullptr;
    TreeNode* x = root;

    while (x != TNULL) {
        y = x;
        if (key.series < x->key.data.series || 
           (key.series == x->key.data.series && key.number < x->key.data.number)) {
            x = x->left;
        } else if (key.series == x->key.data.series && key.number == x->key.data.number) {
            x->key.lineNumbers.push_back(lineNumber);
            delete node;
            return;
        } else {
            x = x->right;
        }
    }

    node->parent = y;
    if (y == nullptr) {
        root = node;
    } else if (key.series < y->key.data.series || 
              (key.series == y->key.data.series && key.number < y->key.data.number)) {
        y->left = node;
    } else {
        y->right = node;
    }

    balanceInsert(node);
}
//Поиск узла в дереве
TreeNode* RedBlackTree::searchTreeHelper(TreeNode* node, const Pasport& key) const {
    if (node == TNULL || (key.series == node->key.data.series && key.number == node->key.data.number)) {
        return node;
    }

    if (key.series < node->key.data.series || 
       (key.series == node->key.data.series && key.number < node->key.data.number)) {
        return searchTreeHelper(node->left, key);
    }
    return searchTreeHelper(node->right, key);
}

bool RedBlackTree::search(const Pasport& key) const {
    return searchTreeHelper(root, key) != TNULL;
}
//Удаление узла
void RedBlackTree::deleteNodeHelper(TreeNode* node, const Pasport& key) {
    TreeNode* z = TNULL;
    TreeNode* x, *y;

    // Найти узел для удаления
    while (node != TNULL) {
        if (key.series == node->key.data.series && key.number == node->key.data.number) {
            z = node;
        }

        if (key.series <= node->key.data.series) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    if (z == TNULL) {
        cout << "Ключ не найден в дереве" << endl;
        return;
    }

    y = z;
    bool yOriginalColor = y->isRed;
    if (z->left == TNULL) {
        x = z->right;
        if (z->parent) {
            if (z == z->parent->left) {
                z->parent->left = z->right;
            } else {
                z->parent->right = z->right;
            }
        }
        if (z->right) z->right->parent = z->parent;
    } else if (z->right == TNULL) {
        x = z->left;
        if (z->parent) {
            if (z == z->parent->left) {
                z->parent->left = z->left;
            } else {
                z->parent->right = z->left;
            }
        }
        if (z->left) z->left->parent = z->parent;
    } else {
        TreeNode* minNode = z->right;
        while (minNode->left != TNULL) {
            minNode = minNode->left;
        }

        if (minNode->parent != z) {
            minNode->parent->left = minNode->right;
            if (minNode->right) minNode->right->parent = minNode->parent;
            minNode->right = z->right;
            if (minNode->right) minNode->right->parent = minNode;
        }

        if (z->parent) {
            if (z == z->parent->left) {
                z->parent->left = minNode;
            } else {
                z->parent->right = minNode;
            }
        }
        minNode->parent = z->parent;
        minNode->left = z->left;
        if (minNode->left) minNode->left->parent = minNode;
        minNode->isRed = z->isRed;
    }

    if (!z->parent) {
        root = x;
    }

    if (!yOriginalColor) {
        balanceDelete(x);
    }

    delete z;
}

void RedBlackTree::remove(const Pasport& key) {
    deleteNodeHelper(root, key);
}
//Балансировка после удаления
void RedBlackTree::balanceDelete(TreeNode* x) {
    while (x != root && !x->isRed) {
        if (x == x->parent->left) {
            TreeNode* sibling = x->parent->right;
            if (sibling->isRed) {
                sibling->isRed = false;
                x->parent->isRed = true;
                leftRotate(x->parent);
                sibling = x->parent->right;
            }

            if (!sibling->left->isRed && !sibling->right->isRed) {
                sibling->isRed = true;
                x = x->parent;
            } else {
                if (!sibling->right->isRed) {
                    sibling->left->isRed = false;
                    sibling->isRed = true;
                    rightRotate(sibling);
                    sibling = x->parent->right;
                }

                sibling->isRed = x->parent->isRed;
                x->parent->isRed = false;
                sibling->right->isRed = false;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            TreeNode* sibling = x->parent->left;
            if (sibling->isRed) {
                sibling->isRed = false;
                x->parent->isRed = true;
                rightRotate(x->parent);
                sibling = x->parent->left;
            }

            if (!sibling->left->isRed && !sibling->right->isRed) {
                sibling->isRed = true;
                x = x->parent;
            } else {
                if (!sibling->left->isRed) {
                    sibling->right->isRed = false;
                    sibling->isRed = true;
                    leftRotate(sibling);
                    sibling = x->parent->left;
                }

                sibling->isRed = x->parent->isRed;
                x->parent->isRed = false;
                sibling->left->isRed = false;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->isRed = false;
}
//Прямой обход и очистка дерева
void RedBlackTree::inorderTraversal(TreeNode* node, ostream& os) const {
    if (node != TNULL) {
        inorderTraversal(node->left, os);
        os << "[" << node->key.data.series << " " << node->key.data.number << "] ";
        node->key.lineNumbers.print_forward();
        inorderTraversal(node->right, os);
    }
}

void RedBlackTree::print(ostream& os) const {
    inorderTraversal(root, os);
    os << endl;
}

void RedBlackTree::clearHelper(TreeNode* node) {
    if (node != TNULL) {
        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }
}

void RedBlackTree::clear() {
    clearHelper(root);
    root = TNULL;
}

// Рекурсивный экспорт узлов
void RedBlackTree::exportToDotHelper(TreeNode* node, std::ofstream& file) const {
    if (node == TNULL) return;

    // Текущий узел
    file << "\"" << node->key.data.series << "-" << node->key.data.number << "\"";
    file << " [label=\"" << node->key.data.series << "\\n" << node->key.data.number 
         << "\", style=filled, fillcolor=" << (node->isRed ? "red" : "black")
         << ", fontcolor=white];\n";

    // Левый потомок
    if (node->left != TNULL) {
        file << "\"" << node->key.data.series << "-" << node->key.data.number << "\" -> ";
        file << "\"" << node->left->key.data.series << "-" << node->left->key.data.number << "\";\n";
    } else {
        file << "\"" << node->key.data.series << "-" << node->key.data.number << "\" -> NULL" 
             << node->key.data.series << "L;\n";
        file << "NULL" << node->key.data.series << "L [style=invis];\n";
    }

    // Правый потомок
    if (node->right != TNULL) {
        file << "\"" << node->key.data.series << "-" << node->key.data.number << "\" -> ";
        file << "\"" << node->right->key.data.series << "-" << node->right->key.data.number << "\";\n";
    } else {
        file << "\"" << node->key.data.series << "-" << node->key.data.number << "\" -> NULL" 
             << node->key.data.series << "R;\n";
        file << "NULL" << node->key.data.series << "R [style=invis];\n";
    }

    // Рекурсивно экспортировать поддеревья
    exportToDotHelper(node->left, file);
    exportToDotHelper(node->right, file);
}

// Экспорт в DOT-файл
void RedBlackTree::exportToDot(const std::string& filename) const {
    std::ofstream file(filename);
    file << "digraph RedBlackTree {\n";
    file << "node [shape=circle];\n";

    if (root != TNULL) {
        exportToDotHelper(root, file);
    }

    file << "}\n";
    file.close();
}