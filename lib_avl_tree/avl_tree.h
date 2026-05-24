#pragma once

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include "../lib_bs_tree/bs_tree.h"

template <class TKey, class TValue>
class AVLTree : public BSTree<TKey, TValue> {
public:
    AVLTree();
    ~AVLTree();

    void insert(const TKey& key, const TValue& value) override;
    void erase(const TKey& key) override;
    TValue* find(const TKey& key) const noexcept override;
    void clear() noexcept override;

    void print_DLCR() const noexcept override;
    void print_pairs() const noexcept override;
protected:
    void left_rotate(NodeTr<TKey, TValue>* node);
    void right_rotate(NodeTr<TKey, TValue>* node);

    void LL(NodeTr<TKey, TValue>* node);
    void RR(NodeTr<TKey, TValue>* node);
    void LR(NodeTr<TKey, TValue>* node);
    void RL(NodeTr<TKey, TValue>* node);

    void recovery_balance(NodeTr<TKey, TValue>* node);
    int get_height(NodeTr<TKey, TValue>* node) const noexcept;
    int calc_balance(NodeTr<TKey, TValue>* node) const noexcept;
    void recalc_height(NodeTr<TKey, TValue>* node) noexcept;

};

template <class TKey, class TValue>
int AVLTree<TKey, TValue>::get_height(NodeTr<TKey, TValue>* node) const noexcept {
    if (node == nullptr) return 0;
    return node->height;
}

template <class TKey, class TValue>
int AVLTree<TKey, TValue>::calc_balance(NodeTr<TKey, TValue>* node) const noexcept {
    if (!node) return 0;
    return get_height(node->left) - get_height(node->right);
}

template <class TKey, class TValue>
void AVLTree<TKey, TValue>::recalc_height(NodeTr<TKey, TValue>* node) noexcept {
    if (node)
        node->height = 1 + std::max(get_height(node->left), get_height(node->right));
}

template <class TKey, class TValue>
void AVLTree<TKey, TValue>::left_rotate(NodeTr<TKey, TValue>* node) {
    NodeTr<TKey, TValue>* P = node->right;

    P->parent = node->parent;
    if (node->parent) {
        if (node->parent->left == node)
            node->parent->left = P;
        else
            node->parent->right = P;
    }
    else {
        this->_root = P;
    }

    node->right = P->left;
    if (P->left)
        P->left->parent = node;

    P->left = node;
    node->parent = P;

    recalc_height(node);
    recalc_height(P);
}

template <class TKey, class TValue>
void AVLTree<TKey, TValue>::right_rotate(NodeTr<TKey, TValue>* node) {
    NodeTr<TKey, TValue>* P = node->left;

    P->parent = node->parent;
    if (node->parent) {
        if (node->parent->left == node)
            node->parent->left = P;
        else
            node->parent->right = P;
    }
    else {
        this->_root = P;
    }

    node->left = P->right;
    if (P->right)
        P->right->parent = node;

    P->right = node;
    node->parent = P;

    recalc_height(node);
    recalc_height(P);
}

template <class TKey, class TValue>
void AVLTree<TKey, TValue>::LL(NodeTr<TKey, TValue>* node) {
    right_rotate(node);
}

template <class TKey, class TValue>
void AVLTree<TKey, TValue>::RR(NodeTr<TKey, TValue>* node) {
    left_rotate(node);
}

template <class TKey, class TValue>
void AVLTree<TKey, TValue>::LR(NodeTr<TKey, TValue>* node) {
    left_rotate(node->left);
    right_rotate(node);
}

template <class TKey, class TValue>
void AVLTree<TKey, TValue>::RL(NodeTr<TKey, TValue>* node) {
    right_rotate(node->right);
    left_rotate(node);
}

template <class TKey, class TValue>
void AVLTree<TKey, TValue>::recovery_balance(NodeTr<TKey, TValue>* node) {
    if (!node) return;

    recalc_height(node);
    int bal = calc_balance(node);

    if (bal > 1) {
        if (calc_balance(node->left) >= 0)
            LL(node);     
        else
            LR(node);     
    }
    else if (bal < -1) {
        if (calc_balance(node->right) <= 0)
            RR(node);     
        else
            RL(node);      
    }
}

template <class TKey, class TValue>
AVLTree<TKey, TValue>::AVLTree() : BSTree<TKey, TValue>() {}

template <class TKey, class TValue>
AVLTree<TKey, TValue>::~AVLTree() {
    clear();
}

template <class TKey, class TValue>
void AVLTree<TKey, TValue>::insert(const TKey& key, const TValue& value) {
    BSTree<TKey, TValue>::insert(key, value);

    NodeTr<TKey, TValue>* node = this->find_parent(key);
    if (!node && this->_root && this->_root->data.first == key) {
        node = this->_root;
    }

    while (node) {
        recovery_balance(node);
        node = node->parent;
    }
}

template <class TKey, class TValue>
void AVLTree<TKey, TValue>::erase(const TKey& key) {
    NodeTr<TKey, TValue>* node = this->find_parent(key);
    if (!node && this->_root && this->_root->data.first == key) {
        node = this->_root;
    }

    NodeTr<TKey, TValue>* parent = nullptr;
    if (node) {
        parent = node->parent;
    }

    BSTree<TKey, TValue>::erase(key);

    while (parent) {
        recovery_balance(parent);
        parent = parent->parent;
    }
}

template <class TKey, class TValue>
TValue* AVLTree<TKey, TValue>::find(const TKey& key) const noexcept {
    return BSTree<TKey, TValue>::find(key);
}

template <class TKey, class TValue>
void AVLTree<TKey, TValue>::clear() noexcept {
    BSTree<TKey, TValue>::clear();
}

template <class TKey, class TValue>
void AVLTree<TKey, TValue>::print_DLCR() const noexcept {
    BSTree<TKey, TValue>::print_DLCR();
}

template <class TKey, class TValue>
void AVLTree<TKey, TValue>::print_pairs() const noexcept {
    BSTree<TKey, TValue>::print_pairs();
}