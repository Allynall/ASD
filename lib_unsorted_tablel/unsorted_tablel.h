#pragma once
#include <iostream>
#include <iomanip>
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
    void print() const noexcept override;

private:
   typename List<std::pair<TKey, TValue>>::Iterator key_search(const TKey& key, bool& found) const noexcept;

};

template <class TKey, class TValue>
typename List<std::pair<TKey, TValue>>::Iterator UnsortedTableL<TKey, TValue>::key_search(const TKey& key, bool& found) const noexcept {
    for (List<std::pair<TKey, TValue>>::Iterator it = _rows.begin(); it != _rows.end(); ++it) {
        if ((*it).first == key) {
            found = true;
            return it;
        }
    }
    found = false;
    return _rows.head();
}


template <class TKey, class TValue>
UnsortedTableL<TKey, TValue>::UnsortedTableL() : _rows() {}

template <class TKey, class TValue>
void UnsortedTableL<TKey, TValue>::insert(const TKey& key, const TValue& value) {
    bool found = false;
    List<std::pair<TKey, TValue>>::Iterator pos = key_search(key, found);
    if (found) {
        throw std::logic_error("The key is busy");
    }
    std::pair<TKey, TValue> pair1 = std::make_pair(key, value);
    _rows.push_back(pair1);
}
template <class TKey, class TValue>
void UnsortedTableL<TKey, TValue>::erase(const TKey& key) {
    bool found = false;
    List<std::pair<TKey, TValue>>::Iterator pos = key_search(key, found);

    if (!found) {
        throw std::logic_error("The key was not found");
    }
    _rows.erase(pos.getNode());
}


template <class TKey, class TValue>
const TValue& UnsortedTableL<TKey, TValue>::found(const TKey& key) const {
    bool found = false;
    List<std::pair<TKey, TValue>>::Iterator pos = key_search(key, found);

    if (!found) {
        throw std::logic_error("The key was not found");
    }
    return (*pos).second;
}

template <class TKey, class TValue>
bool UnsortedTableL<TKey, TValue>::isEmpty() const noexcept {
    if (_rows.is_empty()) {
        return true;
    }
    return false;
}

template <class TKey, class TValue>
void UnsortedTableL<TKey, TValue>::print() const noexcept {
    std::cout << "\033[1m";
    std::cout << "| " << std::left << std::setw(10) << "Key"
        << " | " << std::setw(10) << "Value" << " |" << std::endl;
    std::cout << "\033[0m";
    for (List<std::pair<TKey, TValue>>::Iterator it = _rows.begin(); it != _rows.end(); ++it) {
        std::cout << "---------------------------" << std::endl;
        std::cout << "| " << std::left << std::setw(10) << (*it).first
            << " | " << std::setw(10) << (*it).second << " |" << std::endl;
    }
    std::cout << "---------------------------" << std::endl;
}