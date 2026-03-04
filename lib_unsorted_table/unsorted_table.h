#pragma once
#include <iostream>
#include <iomanip>
#include "../lib_tvector/tvector.h"
#include "../lib_i_table/i_table.h"

template <class TKey, class TValue>
class UnsortedTableM : public ITable<TKey, TValue> {
    TVector <std::pair<TKey, TValue>> _rows;
public:
    UnsortedTableM(); //++
    ~UnsortedTableM() override = default; //++

    void insert(const TKey&, const TValue&) override; //++ 
    void erase(const TKey&) override; //++
    const TValue& found(const TKey&) const  override; //++

    bool isEmpty() const noexcept override; //++

    void print() const noexcept override;
};

template <class TKey, class TValue>
UnsortedTableM<TKey, TValue>::UnsortedTableM(): _rows() {}

template <class TKey, class TValue>
void UnsortedTableM<TKey, TValue>::insert(const TKey& key, const TValue& value) {
    for (size_t i = 0; i < _rows.size(); i++) {
        if (_rows[i].first == key) {
            throw std::logic_error("The key is busy");
        }
    }
    std::pair<TKey, TValue> pair1 = std::make_pair(key, value);
    _rows.push_back_elem(pair1);
}

template <class TKey, class TValue>
void UnsortedTableM<TKey, TValue>::erase(const TKey& key) {
    for (size_t i = 0; i < _rows.size(); i++) {
        if (_rows[i].first == key) {
            _rows.erase_elem(i+1);
            return;
        }
    }
    throw std::logic_error("The key was not found");
}


template <class TKey, class TValue>
const TValue& UnsortedTableM<TKey, TValue>::found(const TKey& key) const {
    for (int i = 0; i < _rows.size(); i++) {
        if (_rows[i].first == key) {
            return _rows[i].second;
        }
    }
    throw std::logic_error("The key was not found");
}

template <class TKey, class TValue>
bool UnsortedTableM<TKey, TValue>::isEmpty() const noexcept {
    if (_rows.is_empty()) {
        return true;
    }
    return false;
}

template <class TKey, class TValue>
void UnsortedTableM<TKey, TValue>::print() const noexcept {
    std::cout << "\033[1m";
    std::cout << "| " << std::left << std::setw(10) << "Key"
        << " | " << std::setw(10) << "Value" << " |" << std::endl;
    std::cout << "\033[0m";
    for (size_t i = 0; i < _rows.size(); i++) {
        std::cout << "---------------------------" << std::endl;
        std::cout << "| " << std::left << std::setw(10) << _rows[i].first
            << " | " << std::setw(10) << _rows[i].second << " |" << std::endl;
    }
    std::cout << "---------------------------" << std::endl;
}