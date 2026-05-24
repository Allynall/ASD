#pragma once

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "../lib_tree/tree.h"

template <class TKey, class TValue>
class BSTree {
protected:
    NodeTr<TKey, TValue>* _root;

public:
    BSTree();
    virtual ~BSTree();

    virtual TValue* find(const TKey& key) const noexcept;
    virtual void insert(const TKey& key, const TValue& Val);
    virtual void erase(const TKey& key);

    bool is_empty() const noexcept;
    virtual void clear() noexcept;

    virtual void print_DLCR() const noexcept;
    virtual void print_pairs() const noexcept;

    NodeTr<TKey, TValue>* root() const noexcept;

protected:
    virtual void clear_rec(NodeTr<TKey, TValue>* node) noexcept;
    virtual NodeTr<TKey, TValue>* erase_rec(NodeTr<TKey, TValue>* node, const TKey& key);
    virtual NodeTr<TKey, TValue>* find_parent(const TKey& key) const noexcept;
    virtual NodeTr<TKey, TValue>* find_max_left(NodeTr<TKey, TValue>* node) const noexcept;

private:
    void print_DLCR_rec(NodeTr<TKey, TValue>* node) const;
    void print_pairs_rec(NodeTr<TKey, TValue>* node) const noexcept;
};

template <class TKey, class TValue>
BSTree<TKey, TValue>::BSTree() : _root(nullptr) {
}

template <class TKey, class TValue>
BSTree<TKey, TValue>::~BSTree() {
    clear();
}

template <class TKey, class TValue>
bool BSTree<TKey, TValue>::is_empty() const noexcept {
    return _root == nullptr;
}

template <class TKey, class TValue>
void BSTree<TKey, TValue>::clear_rec(NodeTr<TKey, TValue>* node) noexcept {
    if (!node) return;
    clear_rec(node->left);
    clear_rec(node->right);
    delete node;
}

template <class TKey, class TValue>
void BSTree<TKey, TValue>::clear() noexcept {
    clear_rec(_root);
    _root = nullptr;
}

template <class TKey, class TValue>
NodeTr<TKey, TValue>* BSTree<TKey, TValue>::find_parent(const TKey& key) const noexcept {
    if (!_root || _root->data.first == key) {
        return nullptr;
    }

    NodeTr<TKey, TValue>* parent = _root;
    while (parent) {
        if (key < parent->data.first) {
            if (!parent->left || parent->left->data.first == key)
                return parent;
            parent = parent->left;
        }
        else if (key > parent->data.first) {
            if (!parent->right || parent->right->data.first == key)
                return parent;
            parent = parent->right;
        }
        else {
            return nullptr;
        }
    }
    return nullptr;
}

template <class TKey, class TValue>
TValue* BSTree<TKey, TValue>::find(const TKey& key) const noexcept {
    if (!_root) return nullptr;

    if (_root->data.first == key) {
        return &_root->data.second;
    }

    NodeTr<TKey, TValue>* parent = find_parent(key);
    if (!parent) return nullptr;

    if (parent->left && parent->left->data.first == key) {
        return &parent->left->data.second;
    }
    else if (parent->right && parent->right->data.first == key) {
        return &parent->right->data.second;
    }
    return nullptr;
}

template <class TKey, class TValue>
void BSTree<TKey, TValue>::insert(const TKey& key, const TValue& val) {
    if (find(key) != nullptr) {
        throw std::invalid_argument("Key already exists");
    }

    NodeTr<TKey, TValue>* parent = find_parent(key);
    if (!parent) {
        if (is_empty()) {
            _root = new NodeTr<TKey, TValue>(key, val);
        }
        return;
    }

    if (key < parent->data.first && !parent->left) {
        parent->left = new NodeTr<TKey, TValue>(key, val);
    }
    else if (key > parent->data.first && !parent->right) {
        parent->right = new NodeTr<TKey, TValue>(key, val);
    }
}

template <class TKey, class TValue>
NodeTr<TKey, TValue>* BSTree<TKey, TValue>::find_max_left(NodeTr<TKey, TValue>* node) const noexcept {
    if (!node || !node->left) return nullptr;

    NodeTr<TKey, TValue>* current = node->left;
    while (current->right) {
        current = current->right;
    }
    return current;
}

template <class TKey, class TValue>
NodeTr<TKey, TValue>* BSTree<TKey, TValue>::erase_rec(NodeTr<TKey, TValue>* node, const TKey& key) {
    if (!node) {
        throw std::invalid_argument("Key not found");
    }

    if (key < node->data.first) {
        node->left = erase_rec(node->left, key);
    }
    else if (key > node->data.first) {
        node->right = erase_rec(node->right, key);
    }
    else {
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        }
        else if (!node->left) {
            NodeTr<TKey, TValue>* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            NodeTr<TKey, TValue>* temp = node->left;
            delete node;
            return temp;
        }
        else {
            NodeTr<TKey, TValue>* max_left = find_max_left(node);
            node->data = max_left->data;
            node->left = erase_rec(node->left, max_left->data.first);
        }
    }
    return node;
}

template <class TKey, class TValue>
void BSTree<TKey, TValue>::erase(const TKey& key) {
    if (is_empty()) {
        throw std::invalid_argument("Tree is empty");
    }
    _root = erase_rec(_root, key);
}

template <class TKey, class TValue>
void BSTree<TKey, TValue>::print_DLCR_rec(NodeTr<TKey, TValue>* node) const {
    if (!node) return;
    print_DLCR_rec(node->left);
    std::cout << "(" << node->data.second << ") ";
    print_DLCR_rec(node->right);
}

template <class TKey, class TValue>
void BSTree<TKey, TValue>::print_DLCR() const noexcept {
    if (is_empty()) {
        std::cout << "Tree is empty" << std::endl;
        return;
    }
    print_DLCR_rec(_root);
    std::cout << std::endl;
}

template <class TKey, class TValue>
NodeTr<TKey, TValue>* BSTree<TKey, TValue>::root() const noexcept {
    return _root;
}

template <class TKey, class TValue>
void BSTree<TKey, TValue>::print_pairs_rec(NodeTr<TKey, TValue>* node) const noexcept {
    if (!node) return;
    print_pairs_rec(node->left);
    std::cout << "| " << std::setw(10) << node->data.first
        << " | " << std::setw(10) << node->data.second << " |" << std::endl;
    print_pairs_rec(node->right);
}

template <class TKey, class TValue>
void BSTree<TKey, TValue>::print_pairs() const noexcept {
    if (is_empty()) {
        std::cout << "Tree is empty" << std::endl;
        return;
    }
    print_pairs_rec(_root);
}