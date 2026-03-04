#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include "../lib_tvector/tvector.h"
#include "../lib_i_table/i_table.h"

template <class TKey, class TValue>
class SortedTableM : public ITable<TKey, TValue> {
    TVector <std::pair<TKey, TValue>> _rows;
public:
    SortedTableM(); //++
    ~SortedTableM() override = default; //++

    void insert(const TKey&, const TValue&) override; //++ 
    void erase(const TKey&) override; //++
    const TValue& found(const TKey&) const  override; //++

    bool isEmpty() const noexcept override; //++

    void print() const noexcept override;
};

template <class TKey, class TValue>
SortedTableM<TKey, TValue>::SortedTableM() : _rows() {}

template <class TKey, class TValue>
size_t binary_search(const TVector<std::pair<TKey, TValue>>&rows, const TKey& key, bool& found) {
    size_t left = 0;
    size_t right = rows.size();

    while (left < right) {
        size_t mid = left + (right - left) / 2;

        if (rows[mid].first == key) {
            found = true;
            return mid;
        }
        else if (rows[mid].first < key) {
            left = mid + 1;
        }
        else if (rows[mid].first > key) {
            right = mid;
        }
    }
    found = false;
    return left;
}

template <class TKey, class TValue>
void SortedTableM<TKey, TValue>::insert(const TKey& key, const TValue& value) {
    bool found = false;
    size_t pos = binary_search(_rows, key, found);
    if (found == true) {
        throw std::logic_error("The key is busy");
    }
    std::pair<TKey, TValue> pair1 = std::make_pair(key, value);
    _rows.insert_elem(pair1, pos+1);
    
}

template <class TKey, class TValue>
void SortedTableM<TKey, TValue>::erase(const TKey& key) {
    bool found = false;
    size_t pos = binary_search(_rows, key, found);
    if (found == true) {
        _rows.erase_elem(pos + 1);
        return;
    } 
    throw std::logic_error("The key was not found");
}


template <class TKey, class TValue>
const TValue& SortedTableM<TKey, TValue>::found(const TKey& key) const {
    bool found = false;
    size_t pos = binary_search(_rows, key, found);
    if (found == true) {
        return _rows[pos].second;
    }
    throw std::logic_error("The key was not found");
}

template <class TKey, class TValue>
bool SortedTableM<TKey, TValue>::isEmpty() const noexcept {
    if (_rows.is_empty()) {
        return true;
    }
    return false;
}

template <class TKey, class TValue>
void SortedTableM<TKey, TValue>::print() const noexcept {
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