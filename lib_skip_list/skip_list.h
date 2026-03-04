#include <iostream>
#include "../lib_list/list.h"

template <class TKey, class TValue>
struct Node {
	std::pair<TKey, TValue> _data;
	Node** _next;
public:
	Node(std::pair<TKey, TValue> value, size_t level) {
		_data = value;
		_next = new Node * [level + 1](); 
		for (size_t i = 0; i <= level; i++) {
			_next[i] = nullptr;
		}
	}
	Node(const Node <std::pair<TKey, TValue>>& other);
	~Node() {
		delete[] _next;
	}
};

template <class TKey, class TValue>
class SkipList {
	size_t _max_lvl;
	size_t _lvl;
	Node<std::pair<TKey, TValue>>* _head;
public:
	SkipList(size_t max_lvl);

	size_t  coin() const noexcept; //++

	void insert(const TKey&, const TValue&);
	void print() const noexcept;

};

template <class TKey, class TValue>
SkipList<TKey, TValue>::SkipList(size_t max_lvl) {
	_max_lvl = max_lvl;
	_lvl = 0;

	_head = new Node<std::pair<TKey, TValue>>(std::pair<TKey, TValue>(), _max_lvl);
}

template <class TKey, class TValue>
size_t SkipList<TKey, TValue>::coin() const noexcept {
	size_t lvl = 0;
	size_t random = rand() % 100;
	while (random >= 50 && lvl < _max_lvl) {
		random = rand() % 100;
		lvl++;
	}
	return lvl;
}

template <class TKey, class TValue>
void SkipList<TKey, TValue>::insert(const TKey&, const TValue&) {

	
}