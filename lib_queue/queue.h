#pragma once
#include "../lib_tvector/tvector.h"
#include <stdexcept>

template<class T>
class Queue {
	T* _data;
	int _size;
	int _head;
	int _count;

public:
	Queue(); //++
	Queue(int size); //++
	Queue(const Queue<T>& other); //++
	~Queue(); //++

	int get_size(); //++
	int get_head(); //++
	int get_count(); //++

	void push(T val); //++
	void pop(); //++

	T head() const; //++   
	T tail() const; //++

	inline bool is_empty() const noexcept; //++
	inline bool is_full() const noexcept; //++
	void clear() noexcept; //++
};

template<typename T>
Queue<T>::Queue() : _data(nullptr), _size(0), _head(0), _count(0) {}

template<typename T>
Queue<T>::Queue(int size) {
	if (size <= 0) {
		throw std::invalid_argument("Queue size must be positive");
	}
	else {
		_size = size;
		_data = new T[size];
	}
    _head = 0;
	_count = 0;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other) : _size(other._size), _head(other._head), _count(other._count) {
	_data = new T[_size];
	for (int i = 0; i <= _size; ++i) {
		_data[i] = other._data[i];
	}
}
template<typename T>
Queue<T>::~Queue() {
	delete[] _data;
}
template<typename T>
int Queue<T>::get_size() {
	return _size;
}

template<typename T>
int Queue<T>::get_head() {
	return _head;
}

template<typename T>
int Queue<T>::get_count() {
	return _count;
}

template<class T>
void Queue<T>::push(T val) {
	if (is_full()) {
		throw std::invalid_argument("Queue is full");
	}
	_data[_count+_head] = val;
	_count++;
}

template<class T>
void Queue<T>::pop() {
	if (is_empty()) {
		throw std::invalid_argument("Queue is empty");
	}
	_head = (_head + 1) % _size;
	_count--;
}

template<class T>
inline bool Queue<T>::is_full() const noexcept{
	return _count == _size;
}

template<class T>
inline bool Queue<T>::is_empty() const noexcept{
	if (_count == 0) {
		return true;
	}
	return false;
}
template<typename T>
void Queue<T>::clear() noexcept {
	_count = 0;
	_head = 0;
}
template<class T>
T Queue<T>::head() const {
	if (is_empty()) {
		throw std::invalid_argument("Queue is empty");
	}
	return _data[_head];
}
template<class T>
T Queue<T>::tail() const {
	if (is_empty()) {
		throw std::invalid_argument("Queue is empty");
	}
	return _data[_count+_head-1];
}