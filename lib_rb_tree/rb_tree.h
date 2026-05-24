#pragma once

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include "../lib_avl_tree/avl_tree.h"

enum Color { Red, Black, BlackBlack };

template <class TKey, class TValue>
struct RBNode : public NodeTr<TKey, TValue> {
    Color color;

    RBNode(const TKey& key, const TValue& value, Color col = Red)
        : NodeTr<TKey, TValue>(key, value), color(col) {}
};

template <class TKey, class TValue>
class RBTree : public AVLTree<TKey, TValue> {
public:
    RBTree();
    ~RBTree();

    void insert(const TKey& key, const TValue& value) override;
    void clear() noexcept override;
    TValue* find(const TKey& key) const noexcept override;
    void print() const;

private:
    void recovery_balance(RBNode<TKey, TValue>* node);
    void recalc_hight(RBNode<TKey, TValue>* node);
    int calc_balance(RBNode<TKey, TValue>* node);
    void recolor(RBNode<TKey, TValue>* node);
    void swap_colors(RBNode<TKey, TValue>* a, RBNode<TKey, TValue>* b);

    void left_rotate(RBNode<TKey, TValue>* node);
    void right_rotate(RBNode<TKey, TValue>* node);

    void RR(RBNode<TKey, TValue>* node);
    void LL(RBNode<TKey, TValue>* node);
    void RL(RBNode<TKey, TValue>* node);
    void LR(RBNode<TKey, TValue>* node);

    void print_rec(RBNode<TKey, TValue>* node, int level) const;
};


template <class TKey, class TValue>
RBTree<TKey, TValue>::RBTree() : AVLTree<TKey, TValue>() {}

template <class TKey, class TValue>
RBTree<TKey, TValue>::~RBTree() {
    clear();
}

template <class TKey, class TValue>
void RBTree<TKey, TValue>::clear() noexcept {
    AVLTree<TKey, TValue>::clear();
}

template <class TKey, class TValue>
TValue* RBTree<TKey, TValue>::find(const TKey& key) const noexcept {
    return AVLTree<TKey, TValue>::find(key);
}

template <class TKey, class TValue>
void RBTree<TKey, TValue>::left_rotate(RBNode<TKey, TValue>* node) {
    AVLTree<TKey, TValue>::left_rotate(static_cast<NodeTr<TKey, TValue>*>(node));
}

template <class TKey, class TValue>
void RBTree<TKey, TValue>::right_rotate(RBNode<TKey, TValue>* node) {
    AVLTree<TKey, TValue>::right_rotate(static_cast<NodeTr<TKey, TValue>*>(node));
}

template <class TKey, class TValue>
void RBTree<TKey, TValue>::LL(RBNode<TKey, TValue>* node) {
    AVLTree<TKey, TValue>::LL(static_cast<NodeTr<TKey, TValue>*>(node));
}

template <class TKey, class TValue>
void RBTree<TKey, TValue>::RR(RBNode<TKey, TValue>* node) {
    AVLTree<TKey, TValue>::RR(static_cast<NodeTr<TKey, TValue>*>(node));
}

template <class TKey, class TValue>
void RBTree<TKey, TValue>::LR(RBNode<TKey, TValue>* node) {
    AVLTree<TKey, TValue>::LR(static_cast<NodeTr<TKey, TValue>*>(node));
}

template <class TKey, class TValue>
void RBTree<TKey, TValue>::RL(RBNode<TKey, TValue>* node) {
    AVLTree<TKey, TValue>::RL(static_cast<NodeTr<TKey, TValue>*>(node));
}

template <class TKey, class TValue>
void RBTree<TKey, TValue>::recolor(RBNode<TKey, TValue>* node) {
    if (node) {
        if (node->color == Red)
            node->color = Black;
        else if (node->color == Black)
            node->color = Red;
    }
}

template <class TKey, class TValue>
void RBTree<TKey, TValue>::swap_colors(RBNode<TKey, TValue>* a, RBNode<TKey, TValue>* b) {
    if (a && b) {
        Color temp = a->color;
        a->color = b->color;
        b->color = temp;
    }
}

template <class TKey, class TValue>
void RBTree<TKey, TValue>::recalc_hight(RBNode<TKey, TValue>* node) {
    if (!node) return;

    int left_hight = 0;
    if (node->left) {
        RBNode<TKey, TValue>* left_child = static_cast<RBNode<TKey, TValue>*>(node->left);
        left_hight = left_child->height;
    }

    int right_hight = 0;
    if (node->right) {
        RBNode<TKey, TValue>* right_child = static_cast<RBNode<TKey, TValue>*>(node->right);
        right_hight = right_child->height;
    }

    node->height = std::max(left_hight, right_hight);

    if (node->color == Black) {
        node->height++;
    }
}

template <class TKey, class TValue>
int RBTree<TKey, TValue>::calc_balance(RBNode<TKey, TValue>* node) {
    if (!node) return 0;

    int left_hight = 0;
    if (node->left) {
        RBNode<TKey, TValue>* left_child = static_cast<RBNode<TKey, TValue>*>(node->left);
        left_hight = left_child->height;
    }

    int right_hight = 0;
    if (node->right) {
        RBNode<TKey, TValue>* right_child = static_cast<RBNode<TKey, TValue>*>(node->right);
        right_hight = right_child->height;
    }

    return left_hight - right_hight;
}

template <class TKey, class TValue>
void RBTree<TKey, TValue>::recovery_balance(RBNode<TKey, TValue>* node) {
    RBNode<TKey, TValue>* C = node;
    RBNode<TKey, TValue>* P = static_cast<RBNode<TKey, TValue>*>(C->parent);

    if (!P) {
        C->color = Black;
        return;
    }

    RBNode<TKey, TValue>* G = static_cast<RBNode<TKey, TValue>*>(P->parent);
    if (!G) return;

    RBNode<TKey, TValue>* U;
    if (G->left == P) {
        U = static_cast<RBNode<TKey, TValue>*>(G->right);
    }
    else {
        U = static_cast<RBNode<TKey, TValue>*>(G->left);
    }

    while (P && P->color == Red && U && U->color == Red) {
        recolor(U);
        recolor(P);

        if (this->_root == G) break;

        recolor(G);
        C = G;
        P = static_cast<RBNode<TKey, TValue>*>(C->parent);
        if (!P) break;
        G = static_cast<RBNode<TKey, TValue>*>(P->parent);
        if (!G) break;

        if (G->left == P) {
            U = static_cast<RBNode<TKey, TValue>*>(G->right);
        }
        else {
            U = static_cast<RBNode<TKey, TValue>*>(G->left);
        }
    }

    if (!P || P->color == Black) return;

    if (G->right == P && P->right == C) {
        RR(G);
        swap_colors(G, P);
    }
    else if (G->right == P && P->left == C) {
        RL(G);
        swap_colors(G, C);
    }
    else if (G->left == P && P->left == C) {
        LL(G);
        swap_colors(G, P);
    }
    else if (G->left == P && P->right == C) {
        LR(G);
        swap_colors(G, C);
    }
}

template <class TKey, class TValue>
void RBTree<TKey, TValue>::insert(const TKey& key, const TValue& value) {
    if (this->find(key) != nullptr) {
        throw std::invalid_argument("Key already exists");
    }

    RBNode<TKey, TValue>* new_node = new RBNode<TKey, TValue>(key, value, Red);

    NodeTr<TKey, TValue>* parent = BSTree<TKey, TValue>::find_parent(key);

    if (!parent) {
        this->_root = new_node;
        new_node->color = Black;
        recalc_hight(new_node);
        return;
    }

    new_node->parent = parent;
    if (key < parent->data.first) {
        parent->left = new_node;
    }
    else {
        parent->right = new_node;
    }

    recovery_balance(new_node);

    RBNode<TKey, TValue>* current = new_node;
    while (current) {
        recalc_hight(current);
        current = static_cast<RBNode<TKey, TValue>*>(current->parent);
    }
}

template <class TKey, class TValue>
void RBTree<TKey, TValue>::print() const {
    if (!this->_root) {
        std::cout << "Tree is empty" << std::endl;
        return;
    }

    print_rec(static_cast<RBNode<TKey, TValue>*>(this->_root), 0);
}

template <class TKey, class TValue>
void RBTree<TKey, TValue>::print_rec(RBNode<TKey, TValue>* node, int level) const {
    if (!node) return;

    print_rec(static_cast<RBNode<TKey, TValue>*>(node->right), level + 1);

    for (int i = 0; i < level; i++) {
        std::cout << "    ";
    }

    if (node->color == Red) {
        std::cout << "\033[31m" << node->data.first << "(R)\033[0m" << std::endl;
    }
    else {
        std::cout << node->data.first << "(B)" << std::endl;
    }

    print_rec(static_cast<RBNode<TKey, TValue>*>(node->left), level + 1);
}