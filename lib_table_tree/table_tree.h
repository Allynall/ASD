#pragma once
#include <iostream>
#include <iomanip>
#include "../lib_tree/tree.h"
#include "../lib_i_table/i_table.h"

template <class TKey, class TValue>
class TableTree : public ITable<TKey, TValue> {
    Tree<TKey, TValue> _rows;
public:
    TableTree(); //+
    ~TableTree() override = default; //+

    void insert(const TKey&, const TValue&) override; //+
    void erase(const TKey&) override; //+
    const TValue& found(const TKey&) const  override; //+

    bool isEmpty() const noexcept override; //+

    void print() const noexcept override;
};

template <class TKey, class TValue>
TableTree<TKey, TValue>::TableTree() : _rows() {}

template <class TKey, class TValue>
bool TableTree<TKey, TValue>::isEmpty() const noexcept {
    return _rows.is_empty();
}

template <class TKey, class TValue>
void TableTree<TKey, TValue>::insert(const TKey& key, const TValue& value) {
    try {
        _rows.insert(key, value);
    }
    catch (const std::logic_error& e) {
        throw std::logic_error("The key is busy");
    }
}

template <class TKey, class TValue>
void TableTree<TKey, TValue>::erase(const TKey& key) {
    try {
        _rows.erase(key);
    }
    catch (const std::logic_error& e) {
        throw std::logic_error("The key was not found");
    }
}

template <class TKey, class TValue>
const TValue& TableTree<TKey, TValue>::found(const TKey& key) const {
    TValue* result = _rows.find(key);
    if (result == nullptr) {
        throw std::logic_error("The key was not found");
    }
    return *result;
}

template <class TKey, class TValue>
void TableTree<TKey, TValue>::print() const noexcept {
    if (isEmpty()) {
        std::cout << "Table is empty" << std::endl;
        return;
    }

    std::cout << "\033[1m";
    std::cout << "| " << std::left << std::setw(10) << "Key"
        << " | " << std::setw(10) << "Value" << " |" << std::endl;
    std::cout << "\033[0m";

    _rows.print_w();
    std::cout << std::endl;
}