#pragma once
#include <iostream>

template <class TKey, class TValue>
class ITable {
public:
    virtual ~ITable() {}

    virtual void insert(const TKey&, const TValue&) = 0;
    virtual void erase(const TKey&) = 0;
    virtual const TValue& found(const TKey&) const = 0;
    virtual bool isEmpty() const noexcept = 0;

    //virtual friend iostream& operator << (iostream& out, const Table&); //предположительно так, вывод крч
};