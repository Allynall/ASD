#pragma once
#include "../lib_list/list.h"
#include <stdexcept>

template<class T>
class QueueThroughList {
	List<T> _data;
	int _size;
	int _head;
	int _count;

public:
	QueueThroughList(); //++
	QueueThroughList(const QueueThroughList<T>& other); //++

	int get_size(); //++
	int get_head(); //++
	int get_count(); //++

	void push(T val); //++
	void pop(); //++

	T& head(); // ++
	T& tail(); //++

	inline bool is_empty() const noexcept; //++
	void clear() noexcept; //++
};

template<typename T>
QueueThroughList<T>::QueueThroughList() : _data(List<T>()), _size(0), _head(0), _count(0) {}



template<typename T>
QueueThroughList<T>::QueueThroughList(const QueueThroughList<T>& other) : _size(other._size), _head(other._head), _count(other._count) {
	_data = other._data;
}

template<class T>
inline bool QueueThroughList<T>::is_empty() const noexcept {
	if (_count == 0) {
		return true;
	}
	return false;
}

template<class T>
void QueueThroughList<T>::push(T val) {
	_data.push_back(val);
	_count++;
	_size++;
}
template<class T>
void QueueThroughList<T>::pop() {
	if (is_empty()) {
		throw std::invalid_argument("Queue is empty");
	}
	_data.pop_front();
	_count--;
	_size--;
}
template<typename T>
void QueueThroughList<T>::clear() noexcept {
	_count = 0;
	_head = 0;
	_size = 0;
}
template<class T>
T& QueueThroughList<T>::head()  {
	if (is_empty()) {
		throw std::invalid_argument("Queue is empty");
	}
	return _data.head() -> value;
}
template<class T>
T& QueueThroughList<T>::tail()  {
	if (is_empty()) {
		throw std::invalid_argument("Queue is empty");
	}
	return (_data.tail()->value);
}

template<typename T>
int QueueThroughList<T>::get_size() {
	return _size;
}

template<typename T>
int QueueThroughList<T>::get_head() {
	return _head;
}

template<typename T>
int QueueThroughList<T>::get_count() {
	return _count;
}
