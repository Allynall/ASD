#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "../lib_i_table/i_table.h"
#include "../lib_list/list.h"

template <class TValue>
struct HashNode {
    std::string _key;
    TValue _value;

    HashNode();
    HashNode(const std::string& key, const TValue& value);
};

template <class TValue>
class HashTable : public ITable<std::string, TValue> {
    size_t _size = 0;
    List<HashNode<TValue>>* _rows;

public:
    HashTable(size_t s);
    ~HashTable() override;

    void insert(const std::string& key, const TValue& value) override;
    void erase(const std::string& key) override;
    const TValue& found(const std::string& key) const override;
    bool isEmpty() const noexcept override;
    void print() const noexcept override;

private:
    size_t h(const std::string& key) const noexcept;
    Node<HashNode<TValue>>* findNode(const std::string& key, size_t hash) const noexcept;
};

template <class TValue>
HashNode<TValue>::HashNode() : _key(""), _value() {}

template <class TValue>
HashNode<TValue>::HashNode(const std::string& key, const TValue& value)
    : _key(key), _value(value) {
}

template <class TValue>
HashTable<TValue>::HashTable(size_t s) : _size(s) {
    _rows = new List<HashNode<TValue>>[_size];
}

template <class TValue>
HashTable<TValue>::~HashTable() {
    delete[] _rows;
}

template <class TValue>
void HashTable<TValue>::insert(const std::string& key, const TValue& value) {
    size_t hash = h(key);
    if (findNode(key, hash) != nullptr) {
        throw std::logic_error("The key is busy");
    }
    _rows[hash].push_back(HashNode<TValue>(key, value));
}

template <class TValue>
void HashTable<TValue>::erase(const std::string& key) {
    size_t hash = h(key);
    Node<HashNode<TValue>>* found = findNode(key, hash);
    if (found) {
        _rows[hash].erase(found);
        return;
    }
    throw std::logic_error("Key not found");
}

template <class TValue>
const TValue& HashTable<TValue>::found(const std::string& key) const {
    size_t hash = h(key);
    Node<HashNode<TValue>>* found = findNode(key, hash);
    if (found) {
        return found->value._value;
    }
    throw std::logic_error("The key is not found");
}

template <class TValue>
bool HashTable<TValue>::isEmpty() const noexcept {
    for (size_t i = 0; i < _size; i++) {
        if (!_rows[i].is_empty()) {
            return false;
        }
    }
    return true;
}

template <class TValue>
void HashTable<TValue>::print() const noexcept {
    if (isEmpty()) {
        std::cout << "Table is empty" << std::endl;
        return;
    }

    std::cout << "\033[1m";
    std::cout << "| " << std::left << std::setw(10) << "Key"
        << " | " << std::setw(10) << "Value" << " |" << std::endl;
    std::cout << "\033[0m";

    for (size_t i = 0; i < _size; i++) {
        for (auto it = _rows[i].begin(); it != _rows[i].end(); ++it) {
            std::cout << "| " << std::setw(10) << it.getNode()->value._key
                << " | " << std::setw(10) << it.getNode()->value._value << " |" << std::endl;
        }
    }
}

template <class TValue>
size_t HashTable<TValue>::h(const std::string& key) const noexcept {
    size_t hash = 0;
    for (size_t i = 0; i < key.length(); i++) {
        hash += key[i];
    }
    hash %= _size;
    return hash;
}

template <class TValue>
Node<HashNode<TValue>>* HashTable<TValue>::findNode(const std::string& key, size_t hash) const noexcept {
    Node<HashNode<TValue>>* current = _rows[hash].head();
    while (current != nullptr) {
        if (current->value._key == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}