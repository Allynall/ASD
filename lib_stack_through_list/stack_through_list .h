#pragma once
#include "../lib_list/list.h"
#include <stdexcept>

template<typename T>
class StackThroughList{
	List<T> _data;
	int _size;
	int _top;
public:
	StackThroughList(); //++
	StackThroughList(const StackThroughList<T>& other); //++

	int get_size(); //++
	int get_top(); //++

	void push(T val); //+
	void pop(); //
	T& top() ;  //++
	inline bool is_empty() const noexcept; //++
	void clear() noexcept; //+
};

template<typename T>
int StackThroughList<T>::get_size() {
	return _size;
}

template<typename T>
int StackThroughList<T>::get_top() {
	return _top;
}
template<class T>
 T& StackThroughList<T>::top() {
	if (is_empty()) {
		throw std::invalid_argument("Stack is empty");
	}
	return _data.head()->value;
}

template<typename T>
StackThroughList<T>::StackThroughList() :  _size(0), _top(-1) {
	_data = List<T>();
}

template<typename T>
StackThroughList<T>::StackThroughList(const StackThroughList<T>& other) : _size(other._size), _top(other._top), _data(other._data) {
}

template<class T>
inline bool StackThroughList<T>::is_empty() const noexcept {
	return _top == -1;
}
template<typename T>
void StackThroughList<T>::clear() noexcept {
	_top = -1;
	_size = 0;
}
template<class T>
void StackThroughList<T>::push(T value) {
	_top = _top + 1;
	_size++;
	_data.push_front(value);

}
template<class T>
void StackThroughList<T>::pop() {
	if (is_empty()) {
		throw std::invalid_argument("Stack is empty");
	}
	_size--;
	_top--;
	_data.pop_front();
}