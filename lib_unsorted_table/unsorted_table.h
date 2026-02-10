#pragma once
#include <iostream>
#include "../lib_tvector/tvector.h"
#include "../lib_i_table/i_table.h"

template <class TKey, class TValue>
class UnsortedTableM : public ITable<TKey, TValue> {
    TVector <std::pair<TKey, TValue>> _rows;
public:
    UnsortedTableM(); //+
    ~UnsortedTableM() override = default; //+

    void insert(const TValue&, const TKey&) override; //_rows.pushback…
    void erase(const TKey&) override; //_rows.erase(…)
    //TValue& found(const TKey&) const noexcept override; // _row.find(…) - ïî çíà÷åíèþ

    bool isEmpty() const noexcept override;
    //operator <<
    //operator >>
};

template <class TKey, class TValue>
UnsortedTableM<TKey, TValue>::UnsortedTableM(): _rows() {}

template <class TKey, class TValue>
void UnsortedTableM<TKey, TValue>::insert(const TValue& value, const TKey& key) {

}

template <class TKey, class TValue>
void UnsortedTableM<TKey, TValue>::erase(const TKey&) {

}


//template <class TKey, class TValue>
//TValue& UnsortedTableM<TKey, TValue>::found(const TKey&) const noexcept {
//    return 1;
//}

template <class TKey, class TValue>
bool UnsortedTableM<TKey, TValue>::isEmpty() const noexcept {
    return true;
}