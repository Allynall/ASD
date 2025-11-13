#pragma once

template <class T>
struct Node {
	T value;
	Node <T>* next;
	Node <T>* prev;

	Node(T value_, Node <T>* next_ = nullptr, Node <T>* prev_ = nullptr);
	Node(const Node<T>& other); 
	~Node() = default;
};

template<typename T>
Node<T>::Node(T value_, Node<T>* next_, Node<T>* prev_) : value(value_), next(next_), prev(prev_) {
}


template<typename T>
Node<T>::Node(const Node<T>& other) {
	value = other.value;
	next = other.next;
	prev = other.prev;
}