#pragma once
#include "../lib_node/node.h"

template <class T>
class DoublyLinkedList {
	Node<T>* _head, * _tail;
	size_t _count;
public:
	DoublyLinkedList(); //++
	DoublyLinkedList(const DoublyLinkedList<T>&);  //++
	~DoublyLinkedList(); //++

	bool is_empty(); //++
	void clear(); //++

	size_t count(); //++
	Node <T>* head() const; //++
	Node <T>* tail(); //++

	void push_front(const T& value) noexcept; //++
	void push_back(const T& value) noexcept; //++
	void insert(size_t pos, const T& value); //++
	void insert(Node <T>* node, const T& value); //++

	void pop_front(); //++
	void pop_back(); //++
	void erase(size_t pos); //++
	void erase(Node <T>* node); //++

};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	_count = 0;
	_head = nullptr;
	_tail = nullptr;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) {
	_head = nullptr;
	_tail = nullptr;
	_count = 0;

	Node<T>* cur = other._head;
	while (cur != nullptr) {
		push_back(cur->value);
		cur = cur->next;
	}
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	clear();
}

template <class T>
bool DoublyLinkedList<T>::is_empty() {
	return _head == nullptr;
}

template <class T>
void DoublyLinkedList<T>::clear() {
	while (_head != nullptr) {
		Node<T>* temp = _head;
		_head = _head->next;
		temp->next = nullptr;
		delete temp;
	}
	_tail = nullptr;
	_count = 0;
}

template <class T>
size_t DoublyLinkedList<T>::count() {
	return _count;
}
template <class T>
Node<T>* DoublyLinkedList<T>::head() const {
	return _head;
}
template <class T>
Node<T>* DoublyLinkedList<T>::tail() {
	return _tail;
}

template <class T>
void DoublyLinkedList<T>::push_front(const T& val) noexcept {
	Node <T>* node = new Node <T>(val);
	if (is_empty()) {
		_count += 1;
		_head = node;
		_tail = node;
		return;
	}
	node->next = _head;
	_head->prev = node;
	_head = node;
	_count += 1;
};

template <class T>
void DoublyLinkedList<T>::push_back(const T& val) noexcept {
	Node <T>* node = new Node <T>(val);
	if (is_empty()) {
		_count += 1;
		_head = node;
		_tail = node;
		return;
	}
	_tail->next = node;
	node->prev = _tail;
	_tail = node;
	_count += 1;
};

template <class T>
void DoublyLinkedList<T>::insert(Node <T>* node, const T& val) {
	if (node == _tail) {
		push_back(val);
	}

	Node <T>* new_node = new Node <T>(val);
	if (is_empty() || node == nullptr) {
		throw std::invalid_argument("Position is wrong");
	}
	new_node->prev = node;           
	new_node->next = node->next;
	node->next = new_node;


	_count += 1;
};

template <class T>
void DoublyLinkedList<T>::insert(size_t pos, const T& val) {
	if (pos == 0) {
		push_front(val);
	}
	if (pos == _count) {
		push_back(val);
		return;
	}
	Node <T>* cur = _head;
	size_t cur_pos = 0;
	while (cur != nullptr) {
		if (cur_pos == pos - 1) {
			break;
		}
		cur_pos++;
		cur = cur->next;
	}
	if (cur == nullptr) {
		throw std::invalid_argument("Position is wrong");
	}
	insert(cur, val);
};

template <class T>
void DoublyLinkedList<T>::pop_front() {
	if (is_empty()) {
		throw std::invalid_argument("List is empty");
	}
	if (_tail == _head) {
		delete _head;
		_head = nullptr;
		_tail = nullptr;
		return;
	}
	_head = _head->next;
	_head->prev = nullptr;
	_count--;
};

template <class T>
void DoublyLinkedList<T>::pop_back() {
	if (is_empty()) {
		throw std::invalid_argument("List is empty");
	}
	if (_tail == _head) {
		delete _head;
		_head = nullptr;
		_tail = nullptr;
		return;
	}
	Node<T>* temp = _tail;  
	_tail = _tail->prev;      
	_tail->next = nullptr;    
	delete temp;              

	_count--;
};

template <class T>
void DoublyLinkedList<T>::erase(Node <T>* node) {
	if (is_empty()) {
		throw std::invalid_argument("List is empty");
	}

	if (_tail == _head) {
		delete _head;
		_head = nullptr;
		_tail = nullptr;
		return;
	}
	if (node == _head) {
		pop_front();
		return;
	}
	node->prev->next = node->next;  
	node->next->prev = node->prev;  

	node->next = nullptr;  
	node->prev = nullptr; 
	delete node;

	_count -= 1;
};

template <class T>
void DoublyLinkedList<T>::erase(size_t pos) {
	if (is_empty()) {
		throw std::invalid_argument("List is empty");
	}

	if (_tail == _head) {
		delete _head;
		_head = nullptr;
		_tail = nullptr;
		return;
	}
	Node <T>* cur = _head;
	size_t cur_pos = 0;
	while (cur_pos < pos && cur != nullptr) {
		cur_pos++;
		cur = cur->next;
	}

	if (cur == nullptr) {
		throw std::invalid_argument("Position is wrong");
	}

	erase(cur);
};