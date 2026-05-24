#pragma once
#include <iostream>
#include <iomanip>
#include "..\lib_tvector\tvector.h"


template <class T>
class Heap {
    TVector<T> _data;

public:
    Heap();
    Heap(const TVector<T>& data_);
    Heap(const Heap& other);
    ~Heap() = default;

    void insert(const T& value) noexcept;
    T erase_root();

    bool is_empty() const noexcept;
    void print();

private:
    int parent(int i) const noexcept;
    int left(int i) const noexcept;
    int right(int i) const noexcept;

    void swap(T& a, T& b);

    void siftUp(int i);
    void siftDown(int i);
};

template <class T>
Heap<T>::Heap() : _data() {}

template <class T>
Heap<T>::Heap(const TVector<T>& data_) : _data(data_) {
    if (!is_empty()) {
        for (int i = (_data.size()) / 2 - 1; i >= 0; i--) {
            siftDown(i);
        }
    }
}

template <class T>
Heap<T>::Heap(const Heap<T>& other) : _data(other._data) {}

template <class T>
bool Heap<T>::is_empty() const noexcept {
    return _data.is_empty();
}

template <class T>
int Heap<T>::parent(int i) const noexcept {
    return i > 0 ? (i - 1) / 2 : -1;
}

template <class T>
int Heap<T>::left(int i) const noexcept {
    return 2 * i + 1;
}

template <class T>
int Heap<T>::right(int i) const noexcept {
    return 2 * i + 2;
}

template <class T>
void Heap<T>::swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void Heap<T>::siftUp(int i) {
    while (i > 0 && _data[parent(i)] > _data[i]) {
        swap(_data[i], _data[parent(i)]);
        i = parent(i);
    }
}

template <class T>
void Heap<T>::siftDown(int i) {
    int min = i;
    int l = left(i);
    int r = right(i);

    if (l < _data.size() && _data[l] < _data[min]) {
        min = l;
    }
    if (r < _data.size() && _data[r] < _data[min]) {
        min = r;
    }

    if (min != i) {
        swap(_data[i], _data[min]);
        siftDown(min);
    }
}

template <class T>
void Heap<T>::insert(const T& value) noexcept {
    _data.push_back_elem(value);
    siftUp(_data.size() - 1);
}

template <class T>
T Heap<T>::erase_root() {
    if (is_empty()) {
        throw std::out_of_range("Heap is empty");
    }

    T min = _data[0];

    _data[0] = _data[_data.size() - 1];
    _data.pop_back_elem();

    if (!is_empty()) {
        siftDown(0);
    }

    return min;
}

template <class T>
void Heap<T>::print() {
    _data.print_elems();
}