#pragma once
#include <iostream>
#include <iomanip>
#include "../lib_bs_tree/bs_tree.h"
#include "../lib_i_table/i_table.h"

template <class TKey, class TValue>
class TableBSTree : public ITable<TKey, TValue> {
    BSTree<TKey, TValue> _rows;
public:
    TableBSTree(); //+
    ~TableBSTree() override = default; //+

    void insert(const TKey&, const TValue&) override; //+
    void erase(const TKey&) override; //+
    const TValue& found(const TKey&) const  override; //+

    bool isEmpty() const noexcept override; //+

    void print() const noexcept override;
};

template <class TKey, class TValue>
TableBSTree<TKey, TValue>::TableBSTree() : _rows() {}

template <class TKey, class TValue>
bool TableBSTree<TKey, TValue>::isEmpty() const noexcept {
    return _rows.is_empty();
}

template <class TKey, class TValue>
void TableBSTree<TKey, TValue>::insert(const TKey& key, const TValue& value) {
    _rows.insert(key, value);
}

template <class TKey, class TValue>
void TableBSTree<TKey, TValue>::erase(const TKey& key) {
        _rows.erase(key);
}

template <class TKey, class TValue>
const TValue& TableBSTree<TKey, TValue>::found(const TKey& key) const {
    TValue* result = _rows.find(key);
    if (result == nullptr) {
        throw std::logic_error("The key was not found");
    }
    return *result;
}

template <class TKey, class TValue>
void TableBSTree<TKey, TValue>::print() const noexcept {
    if (isEmpty()) {
        std::cout << "Table is empty" << std::endl;
        return;
    }

    std::cout << "\033[1m";
    std::cout << "| " << std::left << std::setw(10) << "Key"
        << " | " << std::setw(10) << "Value" << " |" << std::endl;
    std::cout << "\033[0m";

    _rows.print_pairs();
    std::cout << std::endl;
}