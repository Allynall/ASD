#pragma once
#include <iostream>
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

    
    //Virtual friend iostream& operator << (iostream& out, const Table&);
    //operator >>
};

template <class TKey, class TValue>
SortedTableM<TKey, TValue>::SortedTableM() : _rows() {}

template <class TKey, class TValue>
void SortedTableM<TKey, TValue>::insert(const TKey& key, const TValue& value) {
    for (size_t i = 0; i < _rows.size(); i++) {
        if (_rows[i].first == key) {
            throw std::logic_error("The key is busy");
        }
    }
    
    size_t j;
    for (j = 0; j < _rows.size(); j++) {
        if (_rows[j].first > key) {
            break;
        }
    }
    std::pair<TKey, TValue> pair1 = std::make_pair(key, value);
    _rows.insert_elem(pair1, j+1);
    
}

template <class TKey, class TValue>
void SortedTableM<TKey, TValue>::erase(const TKey& key) {
    for (size_t i = 0; i < _rows.size(); i++) {
        if (_rows[i].first == key) {
            _rows.erase_elem(i + 1);
            return;
        }
    }
    throw std::logic_error("The key was not found");
}


template <class TKey, class TValue>
const TValue& SortedTableM<TKey, TValue>::found(const TKey& key) const {
    for (int i = 0; i < _rows.size(); i++) {
        if (_rows[i].first == key) {
            return _rows[i].second;
        }
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