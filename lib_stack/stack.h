#pragma once
#include "../lib_tvector/tvector.h"
#include <stdexcept>

template<typename T>
class Stack {
	T* _data;
	int _size;
	int _top;
public:
	Stack(); //++
	Stack(int size); //++
	Stack(const Stack<T>& other); //++
	~Stack();

	int get_size(); //++
	int get_top(); //++

	void push(T val); //++
	void pop(); //++
	T top() const; //кто сейчас лежит на вершине  //++
	inline bool is_empty() const noexcept; //++
	inline bool is_full() const noexcept; //++
	void clear() noexcept;
};

template<typename T>
int Stack<T>::get_size() {
	return _size;
}

template<typename T>
int Stack<T>::get_top() {
	return _top;
}

template<class T>
T Stack<T>::top() const {
	if (is_empty()) {
		throw std::invalid_argument("Stack is empty");
	}
	//T*
	return _data[_top];
}


template<typename T>
Stack<T>::Stack() : _data(nullptr), _size(0), _top(-1) {}

template<typename T>
Stack<T>::Stack(const Stack<T>& other) : _size(other._size), _top(other._top) {
	_data = new T[_size];
	for (int i = 0; i <= _top; ++i) {
		_data[i] = other._data[i];
	}
}
template<typename T>
Stack<T>::~Stack() {
 //   _top = -1;
	//_size = 0;
	delete _data;
}
template<typename T>
Stack<T>::Stack(int size) {
	if (size <= 0) {
		throw std::invalid_argument("Stack size must be positive");
	}
	else {
		_size = size;
		_data = new T[size];
	}
	_top = -1;
}
template<class T>
inline bool Stack<T>::is_full() const noexcept {
	return _top == _size - 1;
}

template<class T>
inline bool Stack<T>::is_empty() const noexcept {
	return _top == -1;
}


template<typename T>
void Stack<T>::clear() noexcept {
	_top = -1;
}

template<class T>
void Stack<T>::push(T value) {
	if (is_full()) {
		throw std::logic_error("Stack is full");
	}
	_top = _top + 1;
	_data[_top] = value;
	
}
template<class T>
void Stack<T>::pop() {
	if (is_empty()) {
		throw std::invalid_argument("Stack is empty");
	}
	--_top;
}