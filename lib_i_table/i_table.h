#pragma once
#include <iostream>

template <class TKey, class TValue>
class ITable {
public:
    virtual void insert(const TKey&, const TValue&);
    virtual void erase(const TKey&);
    virtual TValue& found(const TKey&) const noexpect;
    virtual bool is_empty() const noexpect;
    virtual friend iostream& operator << (iostream& out, const Table&); //предположительно так, вывод крч
};