#pragma once
#include "../lib_node/node.h"

template <class T>
class List {
	Node<T>* _head, * _tail;
	size_t _count;
public:
	List(); //++
	List(const List<T>&); //++
	~List(); //++

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
	void erase(size_t pos);
	void erase(Node <T>* node); //++

	template <T>
	friend std::ostream& operator<<(std::ostream& os, const List<T>& list); //++

	class Iterator {
		Node<T>* _current;
	public:
		Iterator() : _current(nullptr) {}
		Iterator(Node<T>* node) : _current(node) {}

		Iterator& Iterator::operator=(const Iterator& other) noexcept{
			_current = other._current;
			return *this;
		}

		Iterator& operator++() {
			//возможно проверка
			_current = _current->next;
			return *this;
		}; //it++
		Iterator operator++(int) {
			Iterator temp = *this;
			(*this)++;
			return temp;
		}// ++it


		bool operator!=(const Iterator& other) {
			return (_current != other._current);
		}
		T operator*() {
			return (current->value);
		}

	};
	Iterator begin() {
		return Iterator(_head);
	} //++
	Iterator end() {
		return Iterator(_tail);
	}//++

};




template <class T>
List<T>::List() {
	_count = 0;
	_head = nullptr;
	_tail = nullptr;
}

template <class T>
List<T>::List(const List<T>& other)  {
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
List<T>::~List() {
	clear();
}

template <class T>
void List<T>::clear() {
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
size_t List<T>::count()  {
	return _count;
}
template <class T>
Node<T>* List<T>::head() const {
	return _head;
}
template <class T>
Node<T>* List<T>::tail() {
	return _tail;
}

template <class T>
bool List<T>::is_empty() {
	return _head == nullptr;
}

template <class T>
void List<T>::push_front(const T& val) noexcept {
	Node <T>* node = new Node <T>(val);
	if (is_empty()) {
		_count += 1;
		_head = node;
		_tail = node;
		return;
	}
	node->next = _head;
	_head = node;
	_count += 1;
};

template <class T>
void List<T>::push_back(const T& val) noexcept {
	Node <T>* node = new Node <T>(val);
	if (is_empty()) {
		_count += 1;
		_head = node;
		_tail = node;
		return;
	}
	_tail->next = node;
	_tail = node;
	_count += 1;
};

template <class T>
void List<T>::insert(Node <T>* node, const T& val) {
	Node <T>* new_node = new Node <T>(val);
	if (is_empty() || node == nullptr) {
		throw std::invalid_argument("Position is wrong");
	}
	new_node->next = node->next;
	node->next = new_node;

	if (node == _tail) {   //new_node-> next = nullptr 
		_tail = new_node;
	}
	_count += 1;
};
template <class T>
void List<T>::insert(size_t pos, const T& val) {
	if (pos == 0) {
		push_front(val);
	}
	//if (pos == count-1)
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
void List<T>::pop_front() {
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
	_count--;
};

template <class T>
void List<T>::pop_back() {
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
	while (cur->next != _tail) {
		cur = cur->next;
	}
	delete _tail;
	_tail = cur;
	cur->next = nullptr;
	_count--;
};

template <class T>
void List<T>::erase(Node <T>* node) {
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
	Node <T>* cur = _head;
	while (cur ->next != node && cur ->next != nullptr) {
		cur = cur->next;
	}

	cur->next = node->next;

	if (cur == nullptr) {
		throw std::invalid_argument("Position is wrong");
	}

	node->next = nullptr;
	delete node;
	_count -= 1;
};

template <class T>
void List<T>::erase(size_t pos) {
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

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& list) {
	Node<T>* cur = list.head();
	os << "[";
	while (cur != nullptr) {
		os << cur->value;
		if (cur->next != nullptr) {
			os << " ";
		}
		cur = cur->next;
	}
	os << "]";
	return os;
}