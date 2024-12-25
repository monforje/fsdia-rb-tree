#include "red-black.h"

RBtree::RBtree() : root(nullptr) {}

void RBtree::rotateLeft(RBnode*& node) {
    RBnode* rightChild = node->right;
    node->right = rightChild->left;

    if (rightChild->left) {
        rightChild->left->parent = node;
    }

    rightChild->parent = node->parent;

    if (!node->parent) {
        root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    } else {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;
}

void RBtree::rotateRight(RBnode*& node) {
    RBnode* leftChild = node->left;
    node->left = leftChild->right;

    if (leftChild->right) {
        leftChild->right->parent = node;
    }

    leftChild->parent = node->parent;

    if (!node->parent) {
        root = leftChild;
    } else if (node == node->parent->right) {
        node->parent->right = leftChild;
    } else {
        node->parent->left = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;
}

void RBtree::fixInsert(RBnode*& node) {
    while (node != root && node->parent->color == RED) {
        RBnode* grandparent = node->parent->parent;

        if (node->parent == grandparent->left) {
            RBnode* uncle = grandparent->right;

            if (uncle && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    rotateLeft(node);
                }

                node->parent->color = BLACK;
                grandparent->color = RED;
                rotateRight(grandparent);
            }
        } else {
            RBnode* uncle = grandparent->left;

            if (uncle && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rotateRight(node);
                }

                node->parent->color = BLACK;
                grandparent->color = RED;
                rotateLeft(grandparent);
            }
        }
    }
    root->color = BLACK;
}

RBtree::RBnode* RBtree::findMin(RBnode* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

void RBtree::insert(const KEY& key) {
    RBnode* newNode = new RBnode(key, RED);
    RBnode* parent = nullptr;
    RBnode* current = root;

    while (current) {
        parent = current;
        if (key.data.series < current->key.data.series) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;

    if (!parent) {
        root = newNode;
    } else if (key.data.series < parent->key.data.series) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    fixInsert(newNode);
}

void RBtree::delete_max_left() {
    if (!root) return;

    RBnode* maxLeft = findMin(root->right);
    if (maxLeft) {
        if (maxLeft->parent && maxLeft->parent->left == maxLeft) {
            maxLeft->parent->left = maxLeft->right;
        } else if (maxLeft->parent) {
            maxLeft->parent->right = maxLeft->right;
        }
        if (maxLeft->right) {
            maxLeft->right->parent = maxLeft->parent;
        }
        delete maxLeft;
    } else {
        std::cout << "Максимального слева нет." << std::endl;
    }
}

void RBtree::search_RBnode(const KEY& key) {
    RBnode* current = root;
    while (current) {
        if (key.data.series == current->key.data.series) {
            std::cout << "Найден ключ: (" << key.data.series << ", " << key.data.number << ")" << std::endl;
            return;
        }
        current = (key.data.series < current->key.data.series) ? current->left : current->right;
    }
    std::cout << "Ключ не найден." << std::endl;
}

void RBtree::print_RBtree() {
    printTree();
}

void RBtree::direct_bypass_RBtree() {
    std::cout << "Прямой обход дерева:" << std::endl;
    std::queue<RBnode*> q;
    if (root) q.push(root);

    while (!q.empty()) {
        RBnode* current = q.front();
        q.pop();
        std::cout << "(" << current->key.data.series << ", " << current->key.data.number << ") "
                  << ((current->color == RED) ? "RED" : "BLACK") << std::endl;
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

void RBtree::printTree() {
    if (root) {
        printHelper(root, "", true);
    } else {
        std::cout << "Дерево пусто." << std::endl;
    }
}

void RBtree::printHelper(RBnode* root, std::string indent, bool last) {
    if (root) {
        std::cout << indent;
        if (last) {
            std::cout << "R----";
            indent += "   ";
        } else {
            std::cout << "L----";
            indent += "|  ";
        }

        std::string color = (root->color == RED) ? "RED" : "BLACK";
        std::cout << "(" << root->key.data.series << ", " << root->key.data.number << ") " << color << std::endl;
        printHelper(root->left, indent, false);
        printHelper(root->right, indent, true);
    }
}

void RBtree::visualizeTree() {
    if (!root) {
        std::cout << "Дерево пусто." << std::endl;
        return;
    }
    std::queue<std::pair<RBnode*, int>> nodes;
    int currentLevel = 0;

    nodes.push({root, 0});
    while (!nodes.empty()) {
        auto [node, level] = nodes.front();
        nodes.pop();

        if (level > currentLevel) {
            currentLevel = level;
            std::cout << std::endl;
        }

        if (node) {
            std::cout << "(" << node->key.data.series << ", " << node->key.data.number << ")"
                      << (node->color == RED ? "[RED] " : "[BLACK] ");
            nodes.push({node->left, level + 1});
            nodes.push({node->right, level + 1});
        } else {
            std::cout << "(null) ";
        }
    }
    std::cout << std::endl;
}

void RBtree::generateGraphviz(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл для записи: " << filename << std::endl;
        return;
    }

    file << "digraph RBTree {\n";
    file << "    node [shape=circle];\n";

    if (root) {
        generateGraphvizHelper(root, file);
    }

    file << "}\n";
    file.close();

    std::cout << "Файл Graphviz сохранен как: " << filename << std::endl;
}

void RBtree::generateGraphvizHelper(RBnode* node, std::ofstream& file) {
    if (node) {
        file << "    \"" << node->key.data.series << "\" "
             << "[label=\"" << node->key.data.series 
             << "\\n" << node->key.data.number << "\", "
             << (node->color == RED ? "style=filled, fillcolor=red" : "style=filled, fillcolor=black, fontcolor=white") 
             << "];\n";

        if (node->left) {
            file << "    \"" << node->key.data.series << "\" -> \"" << node->left->key.data.series << "\";\n";
            generateGraphvizHelper(node->left, file);
        } else {
            file << "    \"" << node->key.data.series << "L\" [label=\"NIL\", style=dotted];\n";
            file << "    \"" << node->key.data.series << "\" -> \"" << node->key.data.series << "L\";\n";
        }

        if (node->right) {
            file << "    \"" << node->key.data.series << "\" -> \"" << node->right->key.data.series << "\";\n";
            generateGraphvizHelper(node->right, file);
        } else {
            file << "    \"" << node->key.data.series << "R\" [label=\"NIL\", style=dotted];\n";
            file << "    \"" << node->key.data.series << "\" -> \"" << node->key.data.series << "R\";\n";
        }
    }
}
