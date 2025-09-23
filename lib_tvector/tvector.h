#pragma once
#include <cstddef> // size_t
#include <stdlib.h> 
#include <time.h> 
#include <stdexcept>

#define STEP_OF_CAPACITY 15

template<typename T> class TVector;

template<typename T>
int find_first(const TVector<T>& vec, const T& value);

template<typename T>
int find_last(const TVector<T>& vec, const T& value);

template<typename T>
int* find_elems(const TVector<T>& vec, const T& value);

template<typename T>
void swap(T* a, T* b);

template<typename T>
void randomize(const TVector<T>& vec);

template<typename T>
void hoara_sort_rec(const TVector<T>& vec, int left, int right);

template<typename T>
void hoara_sort(const TVector<T>& vec);

enum State { empty, busy, deleted };

template<class T>
class TVector {
    T* _data;
    size_t _capacity;
    size_t _size;
    size_t _deleted;
    State* _states;
public:
    TVector(); //!изменено
    TVector(size_t);
    TVector(const T*, size_t);
    TVector(std::initializer_list<T>);
    TVector(const TVector<T>&);

    ~TVector();

    size_t capacity() const noexcept;
    size_t size() const noexcept;

    inline bool is_empty() const noexcept;

    inline T& front() noexcept;
    inline T& back() noexcept;

    inline T* begin() noexcept;
    inline T* end() noexcept;


    inline const T* data() const noexcept; // геттер
    inline const State* states() const noexcept;
    /* ... */

    void push_front_elem(const T&);
    void push_back_elem(const T&);
    void insert_elem(const T&, size_t);
    void push_front_elems(T* values, size_t count);
    void push_back_elems(T* values, size_t count);
    void insert_elems(size_t pos, T* values, size_t count);

    void pop_front_elem();
    void pop_back_elem();
    void erase_elem(size_t);
    void pop_front_elems(size_t count);
    void pop_back_elems(size_t count);
    void erase_elems(size_t pos, size_t count);

    template <typename... Args>
    void emplace(size_t pos, Args&&... args);

    void clear() noexcept; //только элементы
    void reserve(size_t new_capacity);
    void assign(size_t count, const T& value);
    T& at(size_t pos); //!!!автоматиз.
    void shrink_to_fit();
    void resize(size_t new_size, const T& value);
    void resize(size_t new_size);

    TVector<T>& operator=(const TVector<T>& other) noexcept; //!!!добавлен noexcept
    bool operator==(const TVector<T>& other) const noexcept; //!!!добавлен noexcept
    bool operator!=(const TVector<T>& other) const noexcept; //!!!добавлен noexcept
    T& operator[](size_t pos) noexcept; //!!!добавлен noexcept

    void print_elems();
    void print_states();

    friend int find_first<T>(const TVector<T>&, const T&);
    friend int find_last<T>(const TVector<T>&, const T&);
    friend int* find_elems<T>(const TVector<T>&, const T&);

    friend void swap<T>(T* a, T* b);
    friend void randomize<T>(const TVector<T>& vec);

    friend void hoara_sort_rec<T>(const TVector<T>& vec, int left, int right);
    friend void hoara_sort<T>(const TVector<T>& vec);

private:
    inline bool is_full() const noexcept;
    void allocate_memory(size_t); //выделение
    void reallocate_memory(size_t); //переопределение
    void reallocate_memory_for_delete();
    void free_memory() noexcept; //освобождееник
};

template<class T>
TVector<T>::TVector() {
    _capacity = STEP_OF_CAPACITY;
    _data = new T[_capacity];
    _size = 0;
    _deleted = 0;
    _states = new State[_capacity];
    for (size_t i = 0; i < _capacity; i++) {
        _states[i] = empty;
    }
}

template<class T>
TVector<T>::TVector(size_t size) {
    _capacity = (size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    _size = size;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < _capacity; i++) {
        _states[i] = empty;
    }

}

template<class T>
TVector<T>::TVector(const T* arr, size_t size) {
    _capacity = 0; //_capacity = (size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    _data = nullptr; //_data = new T[_capacity];
    _size = size;
    _deleted = 0;
    _states = nullptr;

    if (_size > 0) {
        _capacity = (size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
        _data = new T[_capacity];
        _states = new State[_capacity];
        for (size_t i = 0; i < _capacity; ++i) {
            _data[i] = arr[i];
        }
        for (size_t i = 0; i < _size; i++) {
            _states[i] = busy;
        }
        for (size_t i = _size; i < _capacity; i++) {
            _states[i] = empty;
        }
    }
}
template<class T>
TVector<T>::TVector(std::initializer_list<T> data) {
    _capacity = 0; //_capacity = (size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    _data = nullptr; //_data = new T[_capacity];
    _size = data.size();
    _deleted = 0;
    _states = nullptr;

    if (_size > 0) {
        _capacity = (_size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
        _data = new T[_capacity];
        _states = new State[_capacity];
        for (size_t i = 0; i < _capacity; ++i) {
            _data[i] = *(data.begin()+i);
        }
        for (size_t i = 0; i < _size; i++) {
            _states[i] = busy;
        }
        for (size_t i = _size; i < _capacity; i++) {
            _states[i] = empty;
        }
    }
}
template<class T>
TVector<T>::TVector(const TVector<T>& other) {

    _capacity = 0;
    _data = nullptr;
    _size = other._size;
    _deleted = other._deleted;
    _states = nullptr;

    if (_size > 0) {
        _capacity = (_size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
        _data = new T[_capacity];
        _states = new State[_capacity];
        for (size_t i = 0; i < _capacity; i++) {
            _data[i] = other._data[i];
            _states[i] = other._states[i];
        }
    }
}

template<class T>
TVector<T>::~TVector() {
    if (_data != nullptr) {
        delete[] _data;
        _data = nullptr;
    }
    if (_states != nullptr) {
        delete[] _states;
        _states = nullptr;
    }
    _capacity = 0;
    _size = 0;
}


template<class T>
inline const T* TVector<T>::data() const noexcept { return _data; }

template<class T>
inline const State* TVector<T>::states() const noexcept { return _states; }

template<class T>
size_t TVector<T>::capacity() const noexcept { return _capacity; }

template<class T>
size_t TVector<T>::size() const noexcept { return _size; }

template<class T>
inline T& TVector<T>::front() noexcept {
    for (int i = 0; i < _capacity; i++) {
        if (_states[i] == busy) {
            return _data[i];
        }
    }
    
}

template<class T>
inline T& TVector<T>::back() noexcept {
    for (size_t i = _size; i > 0; --i) {
        if (_states[i - 1] == busy) {
            return _data[i - 1];
        }
    }
}

template<class T>
inline T* TVector<T>::begin() noexcept {
    return _data;
}

template<class T>
inline T* TVector<T>::end() noexcept {
    return _data + _size;
}

template<class T>
inline bool TVector<T>::is_empty() const noexcept {
    if (_size == 0) {
        return 1;
    }
    else if (_size > 0) {
        for (size_t i = 0; i < _capacity; i++) {
            if (_states[i] == busy) {
                return 0;
            }
        }
    }
    return 1;
}

//вставка 
template<class T>
void TVector<T>::push_front_elem(const T& value) {
    if (_size >= _capacity) {
        reallocate_memory(_capacity + 15);
    }
    for (size_t i = _size + _deleted; i > 0; --i) {
        _data[i] = _data[i - 1];
        _states[i] = _states[i - 1];
    }

    _data[0] = value;
    _states[0] = busy;

    _size++;
}

template<class T>
void TVector<T>::push_back_elem(const T& value) {
    if (_size >= _capacity) {
        reallocate_memory(_capacity + 15);
    }

    _data[_size + _deleted] = value;
    _states[_size + _deleted] = busy;
    _size++;
}

template<class T>
void TVector<T>::insert_elem(const T& value, size_t pos) {
    if (pos - 1 > _size) {
        throw std::out_of_range("Insert position out of range");
    }

    if (_size >= _capacity) {
        reallocate_memory(_capacity + 15);
    }

    for (size_t i = _size + _deleted; i > pos - 1; i--) {
        _data[i] = _data[i - 1];
        _states[i] = _states[i - 1];
    }

    _data[pos - 1] = value;
    _states[pos - 1] = busy;

    _size++;
}
template<class T>
void TVector<T>::push_front_elems(T* values, size_t count) {
    _size += count;
    if (_size >= _capacity) {
        reallocate_memory(_capacity + 15);
    }
    for (int i = _size + _deleted - 1; i >= count; i--) {
        _data[i] = _data[i - count];
        _states[i] = _states[i - count];
    }
    for (int i = 0; i < count; i++) {
        _data[i] = values[i];
        _states[i] = busy;
    }
}
template<class T>
void TVector<T>::push_back_elems(T* values, size_t count) {
    if (_size + count >= _capacity) {
        reallocate_memory(_capacity + STEP_OF_CAPACITY);
    }
    for (size_t i = _size + _deleted; i < _size + _deleted + count; i++) {
        _data[i] = values[i - _size + _deleted];
        _states[i] = busy;
    }
    _size += count;
}
template<class T>
void TVector<T>::insert_elems(size_t pos, T* values, size_t count) {
    pos = pos - 1;
    if (pos > _size) {
        throw std::out_of_range("Insert position out of range");
    }
    _size += count;
    if (_size >= _capacity) {
        reallocate_memory(_capacity + STEP_OF_CAPACITY);
    }
    for (int i = 0; i <= _size + _deleted - count - pos; i++) {
        _data[_size - i - 1] = _data[_size - count - i - 1];
        _states[_size - i - 1] = _states[_size - count - i - 1];
    }
    for (int i = pos; i < pos + count; i++) {
        _data[i] = values[i - pos];
        _states[i] = busy;
    }
}

//удаление
template<class T>
void TVector<T>::pop_front_elem() {
    if (_size == 0) {
        throw std::out_of_range("Cannot pop from empty vector");
    }

    for (size_t i = 0; i < _size + _deleted; i++) {
        if (_states[i] == busy) {
            _states[i] = deleted;
            break;
        }
    }
    _deleted += 1;

    if (_deleted > _capacity * 0.15) {
        reallocate_memory_for_delete();
    }
    _size--;
}

template<class T>
void TVector<T>::pop_back_elem() {
    if (_size == 0) {
        throw std::out_of_range("Cannot pop from empty vector");
    }

    for (size_t i = _size + _deleted - 1; i >= 0; i--) {
        if (_states[i] == busy) {
            _states[i] = empty;
            break;
        }
    }
    _deleted += 1;
    _size--;

    if (_deleted > _capacity * 0.15) {
        reallocate_memory_for_delete();
    }
}

template<class T>
void TVector<T>::erase_elem(size_t pos) {
    //pos = pos-1
    if (_size == 0) {
        throw std::out_of_range("Cannot pop from empty vector");
    }

    if (pos > _size) {
        throw std::out_of_range("Insert position out of range");
    }

    int busy_count = 0;
    for (size_t i = 0; i < _size + _deleted; i++) {
        if (_states[i] == busy) {
            busy_count++;
            if (busy_count == pos) {
                _states[i] = deleted;
                _size--;
                break;
            }
        }
    }
    _deleted += 1;
    if (_deleted * 100 > _capacity * 15) {
        reallocate_memory_for_delete();
    }
}

template<class T>
void TVector<T>::pop_front_elems(size_t count) {
    if (_size == 0) {
        throw std::out_of_range("Cannot pop from empty vector");
    }

    if (count > _size) {
        throw std::invalid_argument("Count cannot be bigger than size");
    }

    for (size_t i = 0; i < count; i++) {
        if (_states[i] == busy) {
            _states[i] = deleted;
        }
    }
    _deleted += count;
    _size = _size - count;

    if (_deleted > _capacity * 0.15) {
        reallocate_memory_for_delete();
    }
}

template<class T>
void TVector<T>::pop_back_elems(size_t count) {
    if (_size == 0) {
        throw std::out_of_range("Cannot pop from empty vector");
    }

    if (count > _size) {
        throw std::invalid_argument("Count cannot be bigger than size");
    }

    for (int i = _size + _deleted - 1; i > _size + _deleted - count - 1; i--) {
        if (_states[i] == busy) {
            _states[i] = empty;
        }
    }
    _deleted += count;
    _size = _size - count;

    if (_deleted > _capacity * 0.15) {
        reallocate_memory_for_delete();
    }
}

template<class T>
void TVector<T>::erase_elems(size_t pos, size_t count) {
    //pos = pos-1
    if (_size == 0) {
        throw std::out_of_range("Cannot pop from empty vector");
    }

    if (count > _size) {
        throw std::invalid_argument("Count cannot be bigger than size");
    }

    if (pos > _size || pos < 0) {
        throw std::out_of_range("Insert position out of range");
    }

    for (int i = pos - 1; i < pos + count - 1; i++) {
        if (_states[i] == busy) {
            _states[i] = deleted;
        }
    }
    _deleted += count;
    _size = _size - count;

    if (_deleted > _capacity * 0.15) {
        reallocate_memory_for_delete();
    }
}

//замена
template <typename T>
template <typename... Args>
void TVector<T>::emplace(size_t pos, Args&&... args) {

    if (pos - 1 >= _size) {
        throw std::out_of_range("Position out of range");
    }

    int busy_count = 0;
    for (size_t i = 0; i < _size + _deleted; i++) {
        if (_states[i] == busy) {
            busy_count++;
            if (busy_count == pos) {
                new (&_data[i]) T(std::forward<Args>(args)...);
                _states[i] = busy;
                break;
            }
        }
    }
}



template <typename T>
void TVector<T>::clear() noexcept {
    _size = 0;
    _deleted = 0;
    _capacity = STEP_OF_CAPACITY;

    delete[] _data;
    delete[] _states;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < _capacity; i++) {
        _states[i] = empty;
    }

    /*_data = nullptr;
    _states = nullptr;
    _capacity = 0; */
}

template<class T>
void TVector<T>::reserve(size_t new_capacity) {
    if (new_capacity <= _capacity) {
        return;
    }
    T* new_vec = new T[new_capacity];
    State* new_states = new State[new_capacity];
    for (int i = 0, j = 0; i < _capacity; i++) {
        if (_states[i] == busy) {
            new_vec[j] = _data[i];
            new_states[j] = busy;
            j++;
        }
    }
    for (int i = _size; i < new_capacity; i++) {
        new_states[i] = empty;
    }
    delete[] _data;
    delete[] _states;
    _data = new_vec;
    _states = new_states;
    _capacity = new_capacity;
}

template <typename T>
void TVector<T>::assign(size_t count, const T& value) { //под вопросом, сделано по документации
    clear();
    reserve(count);
    for (size_t i = 0; i < count; i++) {
        push_back_elem(value);
    }
}

template <typename T>
T& TVector<T>::at(size_t pos) { //!!! стало автоматиз(позиции для пользователя)
    int busy_count = 0;
    if (pos >= _size && pos <= 0) {
        throw std::out_of_range("Index out of range"); //return -1
    }
    for (size_t i = 0; i < _size + _deleted; i++) {
        if (_states[i] == busy) {
            busy_count++;
            if (busy_count == pos) {
                return _data[pos - 1];
                break;
            }
        }
    }
}

template <typename T>
void TVector<T>::shrink_to_fit() { //для возврата доп памяти в систему
    if (_size == 0) {
        delete[] _data;
        delete[] _states;
        _data = nullptr;
        _states = nullptr;
        _capacity = 0;
        return;
    }

    T* new_data = new T[_size];
    State* new_states = new State[_size];

    size_t new_index = 0;
    for (size_t i = 0; i < _capacity; i++) {
        if (_states[i] == busy) {
            new_data[new_index] = _data[i];
            new_states[new_index] = busy;
            new_index++;
        }
    }

    delete[] _data;
    delete[] _states;
    _data = new_data;
    _states = new_states;
    _capacity = _size;
    _deleted = 0;
}

template <typename T>
void TVector<T>::resize(size_t new_size) {
    if (new_size < _size) {
        for (size_t i = new_size; i < _size; i++) {
            if (_states[i] == busy) {
                _states[i] = empty;
            }
        }
        _size = new_size;
    }
    else if (new_size > _size) {
        reserve(new_size);
        for (size_t i = _size; i < new_size; i++) {
            new (_data + i) T();
            _states[i] = busy;
        }
        _size = new_size;
    }
}

template <typename T>
void TVector<T>::resize(size_t new_size, const T& value) {
    if (new_size < _size) {
        for (size_t i = new_size; i < _size; i++) {
            if (_states[i] == busy) {
                _states[i] = empty;
            }
        }
        _size = new_size;
    }
    else if (new_size > _size) {
        reserve(new_size);
        for (size_t i = _size; i < new_size; i++) {
            new (_data + i) T(value);
            _states[i] = busy;
        }
        _size = new_size;
    }
}

template <typename T>
TVector<T>& TVector<T>::operator=(const TVector<T>& other) noexcept {
    if (this != &other) {
        clear();
        reserve(other._capacity);
        for (size_t i = 0; i < other._size + other._deleted; i++) {
            if (other._states[i] == busy) {
                new (_data + i) T(other._data[i]);
                _states[i] = busy;
            }
        }
        _size = other._size;
        _deleted = other._deleted;
    }
    return *this;
}

template <typename T>
bool TVector<T>::operator==(const TVector<T>& other) const noexcept { //!!!исправлено //!!!добавлен noexcept
    if (this == &other) return true;
    if (_size != other._size) return false;

    int other_count = -1;

    for (int i = 0; i < _size + _deleted; i++) {
        if (_states[i] == busy) {
            for (int j = 0; j < other._size + other._deleted; j++) {
                other_count += 1;
                if (other._states[other_count] == busy) {
                    if (_data[i] != other._data[other_count]) {
                        return false;
                    }
                    break;
                }

            }
        }
    }
    return true;
}

template <typename T>
bool TVector<T>::operator!=(const TVector<T>& other) const noexcept { //!!!добавлен noexcept
    return !(*this == other);
}

template <typename T>
T& TVector<T>::operator[](size_t pos) noexcept { //!!!добавлен noexcept
    int busy_elems = 0;
    for (size_t i = 0; i < _size + _deleted; i++) {
        if (_states[i] == busy) {
            if (pos == busy_elems) {
                return _data[i];
            }
            busy_elems += 1;
        }
    }
    return _data[pos];
}

template<class T>
void TVector<T>::print_elems() {
    int entrance = 0;
    for (size_t i = 0; entrance < _size; i++) {
        if (_states[i] == busy) {
            std::cout << _data[i] << " ";
            entrance++;
        }
    }
    std::cout << std::endl;
    /*for (size_t i = 0; i < _capacity; i++) {
        std::cout << _data[i] << " ";
    }
    std::cout << std::endl;*/
}

template<class T>
void TVector<T>::print_states() {
    for (size_t i = 0; i < _capacity; i++) {
        std::cout << _states[i] << " ";
    }
    std::cout << std::endl;
}

template<class T>
inline bool TVector<T>::is_full() const noexcept { return _size >= _capacity; }

template<class T>
void TVector<T>::allocate_memory(size_t new_capacity) {
    T* new_data = new T(new_capacity);
    State* new_states = new State[new_capacity];

    for (size_t i = 0; i < new_capacity; ++i) {
        new_states[i] = empty;
    }

    _data = new_data;
    _states = new_states;
    _capacity = new_capacity;
}

template<class T>
void TVector<T>::reallocate_memory_for_delete() {
    T* new_data = new T[_size + STEP_OF_CAPACITY];
    State* new_states = new State[_size + STEP_OF_CAPACITY];


    size_t new_index = 0;
    for (size_t i = 0; i < _capacity; ++i) {
        if (_states[i] == busy) {
            new_data[new_index] = _data[i];
            new_states[new_index] = busy;
            new_index++;
        }
    }

    delete[] _data;
    delete[] _states;


    _data = new_data;
    _states = new_states;

    _capacity = _size + STEP_OF_CAPACITY;
    _deleted = 0;

    for (size_t i = _size; i < _capacity; ++i) {
        _states[i] = empty;
    }
}

template<class T>
void TVector<T>::reallocate_memory(size_t new_capacity) {
    if (new_capacity <= _capacity) return;

    T* new_data = new T[new_capacity];
    State* new_states = new State[new_capacity]();

    size_t new_index = 0;
    for (size_t i = 0; i < _capacity; ++i) {
        if (_states[i] == busy) {
            new_data[new_index] = std::move(_data[i]);
            new_states[new_index] = busy;
            new_index++;
        }
    }

    delete[] _data;
    delete[] _states;

    _data = new_data;
    _states = new_states;
    _capacity = new_capacity;
    _deleted = 0;
}
template<class T>
void TVector<T>::free_memory() noexcept {

    delete[](_data);
    delete[] _states;

    _data = nullptr;
    _states = nullptr;
    _size = 0;
    _capacity = 0;
    _deleted = 0;
}


template <typename T>
int find_first(const TVector<T>& vec, const T& value) {
    int visible_idx = 0;

    if (vec.size() == 0) {
        throw std::invalid_argument("Cannot find from empty vector");
    }
    for (size_t i = 0; i < vec._size + vec._deleted; ++i) {
        if (vec._states[i] == busy) {
            if (vec._data[i] == value) {
                return visible_idx;
            }
            visible_idx++;
        }
    }
    return -1;
}


template <typename T>
int find_last(const TVector<T>& vec, const T& value) {
    int last_found = -1;
    int visible_idx = -1;

    if (vec.size() == 0) {
        throw std::invalid_argument("Cannot find from empty vector");
    }

    for (size_t i = 0; i < vec._size + vec._deleted; ++i) {
        if (vec._states[i] == busy) {
            visible_idx++;
            if (vec._data[i] == value) {
                last_found = visible_idx;
            }
        }
    }

    return last_found;
}


template<typename T>
int* find_elems(const TVector<T>& vec, const T& value) {
    int size = 0;

    if (vec.size() == 0) {
        throw std::invalid_argument("Cannot find from empty vector");
    }

    for (int i = 0; i < vec._capacity; i++) {
        if (vec._states[i] == busy && vec._data[i] == value) {
            size++;
        }
    }


    if (size == 0) {
        int* result = new int[1];
        result[0] = -1;
        return result;
    }

    int* result = new int[size];
    int index = 0;

    for (int i = 0, j = 0; i < vec._capacity; i++) {
        if (vec._states[i] == busy) {
            if (vec._data[i] == value) {
                result[j] = index; j++;
            }
            index++;
        }
    }

    return result;
}

template <typename T>
void randomize(const TVector<T>& vec) {
    srand(time(NULL));

    for (int i = vec._size + vec._deleted; i > 0; i--) {
        if (vec._states[i] == busy) {
            int j = rand() % (i + 1);
            swap(&vec._data[i], &vec._data[j]);
            swap(&vec._states[i], &vec._states[j]);
        }
    }
}

template <typename T>
void swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T>
void hoara_sort_rec(const TVector<T>& vec, int left, int right) {
    if (left < right) {
        int l = left, r = right;
        int base_pos = (left + right) / 2;
        T base_value = vec._data[base_pos];

        while (l <= r) {
            while (vec._data[l] < base_value) {
                l++;
            }
            while (vec._data[r] > base_value) {
                r--;
            }
            if (l <= r) {
                if (l < r) {
                    swap(&vec._data[l], &vec._data[r]);
                    swap(&vec._states[l], &vec._states[r]);
                }
                l++;
                r--;
            }
        }
        hoara_sort_rec(vec, left, r);
        hoara_sort_rec(vec, l, right);
    }
}

template <typename T>
void hoara_sort(const TVector<T>& vec) {
    hoara_sort_rec(vec, 0, vec._size + vec._deleted);
}