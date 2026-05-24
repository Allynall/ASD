#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "../lib_i_table/i_table.h"

template <class TValue>
struct HashData {
    enum status { empty, busy, deleted };

    status _state;
    std::string _key;
    TValue _value;

    HashData() : _state(empty), _key(""), _value() {}
    HashData(const std::string& key, const TValue& value) : _key(key), _value(value), _state(busy) {}
};

template <class TValue>
class HashTableOA : public ITable<std::string, TValue> {
    HashData<TValue>* _rows;
    size_t _size;
    size_t _shift;
    
public:
    HashTableOA(size_t size);
    ~HashTableOA() override;

    void insert(const std::string&, const TValue&) override;
    void erase(const std::string&) override;
    const TValue& found(const std::string&) const override;

    bool isEmpty() const noexcept override;
    void print() const noexcept override;
    
private:
    size_t h(const std::string& key) const noexcept;
    size_t hh(size_t hash) const noexcept;
    bool is_simple(size_t a, size_t b) const noexcept;
};

template <class TValue>
size_t HashTableOA<TValue>::h(const std::string& key) const noexcept {
    size_t hash = 0;
    for (size_t i = 0; i < key.length(); i++) {
        hash += key[i];
    }
    hash %= _size;
    return hash;
}

template <class TValue>
size_t HashTableOA<TValue>::hh(size_t hash) const noexcept {
    return (hash + _shift) % _size;
}

template <class TValue>
bool HashTableOA<TValue>::is_simple(size_t a, size_t b) const noexcept {
    while (b != 0) {
        size_t temp = b;
        b = a % b;
        a = temp;
    }
    return a == 1;
}

template <class TValue>
HashTableOA<TValue>::HashTableOA(size_t size) : _size(size), _shift(1) {
    _rows = new HashData<TValue>[_size];
    
    for (size_t i = std::max(2, (int)(size / 15)); i < size; i++) {
        if (is_simple(i, size)) {
            _shift = i;
            break;
        }
    }
}

template <class TValue>
HashTableOA<TValue>::~HashTableOA() {
    delete[] _rows;
}

template <class TValue>
void HashTableOA<TValue>::insert(const std::string& key, const TValue& value) {
    size_t hash = h(key);
    size_t first_hash = hash;
    
    while (1) {
        if (_rows[hash]._state != HashData<TValue>::busy) {
            _rows[hash] = HashData<TValue>(key, value);
            return;
        }
        if (_rows[hash]._key == key) {
            throw std::logic_error("The key is busy");
        }
        hash = hh(hash);
        if (first_hash == hash) {
            throw std::logic_error("Hash table is full");
        }
    }
}

template <class TValue>
void HashTableOA<TValue>::erase(const std::string& key) {
    if (isEmpty()) {
        throw std::logic_error("Hash table is empty");
    }

    size_t hash = h(key);
    size_t first_hash = hash;
    
    while (1) {
        if (_rows[hash]._state == HashData<TValue>::empty) {
            throw std::logic_error("The key is not found");
        }
        if (_rows[hash]._state == HashData<TValue>::busy && _rows[hash]._key == key) {
            _rows[hash]._state = HashData<TValue>::deleted;
            return;
        }
        hash = hh(hash);
        if (first_hash == hash) {
            break;
        }
    }
    throw std::logic_error("The key is not found");
}

template <class TValue>
const TValue& HashTableOA<TValue>::found(const std::string& key) const {
    if (isEmpty()) {
        throw std::logic_error("Hash table is empty");
    }

    size_t hash = h(key);
    size_t first_hash = hash;

    while (1) {
        if (_rows[hash]._state == HashData<TValue>::busy && _rows[hash]._key == key) {
            return _rows[hash]._value;
        }
        if (_rows[hash]._state == HashData<TValue>::empty) {
            throw std::logic_error("The key is not found");
        }
        hash = hh(hash);
        if (first_hash == hash) {
            throw std::logic_error("The key is not found");
        }
    }
}

template <class TValue>
bool HashTableOA<TValue>::isEmpty() const noexcept {
    for (size_t i = 0; i < _size; i++) {
        if (_rows[i]._state == HashData<TValue>::busy) {
            return false;
        }
    }
    return true;
}

template <class TValue>
void HashTableOA<TValue>::print() const noexcept {
    bool hasElements = false;
    
    for (size_t i = 0; i < _size; i++) {
        if (_rows[i]._state == HashData<TValue>::busy) {
            hasElements = true;
            break;
        }
    }
    
    if (!hasElements) {
        std::cout << "Table is empty" << std::endl;
        return;
    }

    std::cout << "\033[1m";
    std::cout << "| " << std::left << std::setw(10) << "Key"
        << " | " << std::setw(10) << "Value" << " |" << std::endl;
    std::cout << "\033[0m";

    for (size_t i = 0; i < _size; i++) {
        if (_rows[i]._state == HashData<TValue>::busy) {
            std::cout << "| " << std::setw(10) << _rows[i]._key
                << " | " << std::setw(10) << _rows[i]._value << " |" << std::endl;
        }
    }
}