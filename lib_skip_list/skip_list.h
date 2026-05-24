#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../lib_list/list.h"
#include "../lib_tvector/tvector.h"

template <class TKey, class TValue>
struct NodeL {
    std::pair<TKey, TValue> _data;
    NodeL** _next;

    NodeL(std::pair<TKey, TValue> value, size_t level)
        : _data(value)
    {
        _next = new NodeL * [level + 1]();
        for (size_t i = 0; i <= level; i++) {
            _next[i] = nullptr;
        }
    }

    ~NodeL() {
        delete[] _next;
    }
};

template <class TKey, class TValue>
class SkipList {
    size_t _max_lvl;
    size_t _lvl;
    NodeL<TKey, TValue>* _head;

public:
    SkipList(size_t max_lvl);
    ~SkipList();

    size_t coin() const noexcept;
    void insert(const TKey& key, const TValue& value);
    void print() const noexcept;
    NodeL<TKey, TValue>* find_nearest(const TKey& key) const noexcept;
};


template <class TKey, class TValue>
SkipList<TKey, TValue>::SkipList(size_t max_lvl) {
    if (max_lvl == -1) {
        _max_lvl = 10;
    }
    if (max_lvl == 0) {
        throw std::logic_error("The maximum level cannot be less than 1");
    }
    _max_lvl = max_lvl;
    _lvl = 0;
    srand(time(0));

    std::pair<TKey, TValue> emptyPair;
    _head = new NodeL<TKey, TValue>(emptyPair, _max_lvl);
}

template <class TKey, class TValue>
SkipList<TKey, TValue>::~SkipList() {
    if (!_head) return;

    NodeL<TKey, TValue>* current = _head->_next[0];
    while (current != nullptr) {
        NodeL<TKey, TValue>* next = current->_next[0];
        delete current;
        current = next;
    }
    delete _head;
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
NodeL<TKey, TValue>* SkipList<TKey, TValue>::find_nearest(const TKey& key) const noexcept {
    if (!_head) return nullptr;

    NodeL<TKey, TValue>* current = _head;
    for (int i = _lvl; i >= 0; i--) {
        while (current->_next[i] != nullptr &&
            current->_next[i]->_data.first < key) {
            current = current->_next[i];
        }
    }

    current = current->_next[0];
    return current;
} 

template <class TKey, class TValue>
void SkipList<TKey, TValue>::insert(const TKey& key, const TValue& value) {
    NodeL<TKey, TValue>** update = new NodeL<TKey, TValue>* [_max_lvl + 1];

    NodeL<TKey, TValue>* current = _head;

    for (int i = _lvl; i >= 0; i--) {
        while (current->_next[i] != nullptr &&
            current->_next[i]->_data.first < key) {
            current = current->_next[i];
        }
        update[i] = current;
    }

    current = current->_next[0];

    if (current != nullptr && current->_data.first == key) {
        throw std::logic_error("The key is busy");
    }

    size_t new_lvl = coin();

    if (new_lvl > _lvl) {
        for (size_t i = _lvl + 1; i <= new_lvl; i++) {
            update[i] = _head;
        }
        _lvl = new_lvl;
    }

    NodeL<TKey, TValue>* new_node =
        new NodeL<TKey, TValue>(std::make_pair(key, value), new_lvl);

    for (size_t i = 0; i <= new_lvl; i++) {
        new_node->_next[i] = update[i]->_next[i];
        update[i]->_next[i] = new_node;
    }

    delete[] update;  
}

template <class TKey, class TValue>
void SkipList<TKey, TValue>::print() const noexcept {
    if (_head->_next[0] == nullptr) {
        std::cout << "List is empty\n";
        return;
    }

    TVector<TKey> keys;
    NodeL<TKey, TValue>* bottom = _head->_next[0];
    while (bottom != nullptr) {
        keys.push_back_elem(bottom->_data.first);
        bottom = bottom->_next[0];
    }

    for (int i = _lvl; i >= 0; i--) {
        std::cout << "LVL" << i << ": ";

        NodeL<TKey, TValue>* current = _head->_next[i];
        NodeL<TKey, TValue>* prev = nullptr;
        size_t key_idx = 0;

        while (key_idx < keys.size()) {
            if (current && current->_data.first == keys[key_idx]) {
                
                if (prev) {
                    std::cout << "-->";
                }
                else {
                    std::cout << "   ";
                }
                std::cout << "[" << current->_data.first << "]";
                prev = current;
                current = current->_next[i];
            }
            else {
               
                if (prev) {
                    std::cout << "----";
                }
                else {
                    std::cout << "    ";
                }
                std::cout << "---";
            }
            key_idx++;
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}