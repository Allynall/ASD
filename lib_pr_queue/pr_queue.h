#pragma once
#include <iostream>
#include <iomanip>
#include "..\lib_heap\heap.h"
#include "..\lib_tvector\tvector.h"


template <class TValue>
struct NodePr {
	int priority;      
	int number;        
	TValue value;

	NodePr() : priority(0), number(0), value(TValue()) {}

    NodePr(int priority_, int number_, const TValue& value_)
        : priority(priority_), number(number_), value(value_) {
    }

    bool operator<(const NodePr& other) const {
        if (priority != other.priority) {
            return priority < other.priority;
        }
        else {
            return number < other.number;
        }
    }
	bool operator>(const NodePr& other) const {
		if (priority != other.priority) {
            return priority > other.priority;
		}
		else {
            return number > other.number;
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const NodePr& node) {
		os << "(" << node.priority << ", " << node.value << ")";
		return os;
	}
   
};

template <class TValue>
class PrQueue {
    Heap<NodePr<TValue>> _data;
    int _nextNumber;

public:
    PrQueue();
    PrQueue(const PrQueue<TValue>& other);
    ~PrQueue() = default;

    void push(int priority, const TValue& value);
    NodePr<TValue> pop();

    bool is_empty() const noexcept;
    void print();
};

template <class TValue>
PrQueue<TValue>::PrQueue() : _data(), _nextNumber(0) {}

template <class TValue>
PrQueue<TValue>::PrQueue(const PrQueue<TValue>& other) : _data(other._data), _nextNumber(other._nextNumber) {}

template <class TValue>
void PrQueue<TValue>::push(int priority, const TValue& value) {
    NodePr<TValue> node(priority, _nextNumber, value);
    _data.insert(node);
    _nextNumber++;
}

template <class TValue>
NodePr<TValue> PrQueue<TValue>::pop() {
    if (is_empty()) {
        throw std::out_of_range("PrQueue is empty");
    }
    return _data.erase_root();
}

template <class TValue>
bool PrQueue<TValue>::is_empty() const noexcept {
    return _data.is_empty();
}


template <class TValue>
void PrQueue<TValue>::print() {
    PrQueue<TValue> temp = *this;
    while (!temp.is_empty()) {
        NodePr<int> item = temp.pop();  
        std::cout << "(" << item.priority << "," << item.value << ") ";
    }
    //_data.print();
}