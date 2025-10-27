#pragma once

template <class T>
struct Node {
	T value;
	Node <T>* next;

	Node(T value_, Node <T>* next_ = nullptr);
	Node(const Node<T>& other); 
	~Node() = default;
};

template<typename T>
Node<T>::Node(T value_, Node<T>* next_) : value(value_), next(next_) {
}


template<typename T>
Node<T>::Node(const Node<T>& other) {
	value = other.value;
	next = other.next;
}