#pragma once
#include <iostream>

template <class TKey, class TValue>
class UnsortedTableM : ITable<TKey, TValue> {
    TVector <std::pair<TKey, TValue>> _rows;
public:
    UnsortedTableM();
    ~UnsortedTableM();

    void insert(TValue, TKey); //_rows.pushbackЕ
    void erase(TKey); //_rows.erase(Е)
    TValue found(TKey) // _row.find(Е) - по значению

        bool isEmpty()
        //operator <<
        //operator >>
};
