#pragma once
#include <iostream>
#include "../lib_tvector/tvector.h"
#include "../lib_i_table/i_table.h"
#include "../lib_list/list.h"

template <class TKey, class TValue>
class UnsortedTableL : public ITable<TKey, TValue> {
    List <std::pair<TKey, TValue>> _rows;
public:
    UnsortedTableL(); //++
    ~UnsortedTableL() override = default; //++

    void insert(const TKey&, const TValue&) override; //++ 
    void erase(const TKey&) override; //++
    const TValue& found(const TKey&) const  override; //

    bool isEmpty() const noexcept override; //++

    //Virtual friend iostream& operator << (iostream& out, const Table&);
    //operator >>
};

template <class TKey, class TValue>
UnsortedTableL<TKey, TValue>::UnsortedTableL() : _rows() {}

template <class TKey, class TValue>
void UnsortedTableL<TKey, TValue>::insert(const TKey& key, const TValue& value) {
    for (List<std::pair<TKey, TValue>>::Iterator it = _rows.begin(); it != _rows.end(); ++it) {
        if ((*it).first == key) {
            throw std::logic_error("The key is busy");
        }
    }
    std::pair<TKey, TValue> pair1 = std::make_pair(key, value);
    _rows.push_back(pair1);
}
template <class TKey, class TValue>
void UnsortedTableL<TKey, TValue>::erase(const TKey& key) {
    for (List<std::pair<TKey, TValue>>::Iterator it = _rows.begin(); it != _rows.end(); ++it) {
        if ((*it).first == key) {
            _rows.erase(it.getNode());
            return;
        }
    }
    throw std::logic_error("The key was not found");
}


template <class TKey, class TValue>
const TValue& UnsortedTableL<TKey, TValue>::found(const TKey& key) const {
    for (List<std::pair<TKey, TValue>>::Iterator it = _rows.begin(); it != _rows.end(); ++it) {
        if ((*it).first == key) {
            return (*it).second;
        }
    }
    throw std::logic_error("The key was not found");
}

template <class TKey, class TValue>
bool UnsortedTableL<TKey, TValue>::isEmpty() const noexcept {
    if (_rows.is_empty()) {
        return true;
    }
    return false;
}