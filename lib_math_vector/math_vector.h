#pragma once
#include "..\lib_tvector\tvector.h"

template<typename T>
class MVector : public TVector<T> {
public:
	MVector() : TVector<T>() {} //++
	MVector(const T*, size_t) : TVector<T>(const T*) {} //++
	MVector(const TVector<T>& other) : TVector<T>(other) {} //++
	MVector(size_t size); //++

	MVector<T>& operator+(const MVector<T>& other); //++
	MVector<T>& operator-(const MVector<T> other); //++
	T operator*(const MVector<T>& other);

	MVector<T>& operator*(const T& num);   //++
	MVector<T>& operator/(const T& num);  //++

};
template<typename T>
MVector<T>::MVector(size_t size) {
	_capacity = (size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
	_size = size;
	_data = new T[_capacity];
	_states = new State[_capacity];
	for (size_t i = 0; i < _capacity; i++) {
		_states[i] = empty;
	}

}
template<typename T>
MVector<T>& MVector<T>::operator*(const T& num) {
	for (size_t i = 0; i < (*this)._capacity; i++) {
		if ((*this)._states[i] == busy) {
			(*this)._data[i] = (*this)._data[i] * num;
        }
    }

    return *this;
}

template<typename T>
MVector<T>& MVector<T>::operator/(const T& num) {
	for (size_t i = 0; i < (*this)._capacity; i++) {
		if ((*this)._states[i] == busy) {
			(*this)._data[i] = (*this)._data[i] / num;
		}
	}

	return *this;
}
template<typename T>
MVector<T>& MVector<T>::operator+(const MVector<T>& other) {
	if ((*this)._size != other._size) {
		throw std::invalid_argument("The dimensions of the vectors should be equal");
	}
	for (int i = 0; i < (*this)._capacity; i++) 
		if ((*this)._states[i] == busy) {
		for (int j = i; j < other._capacity; j++)
		{
			if (other._states[j] == busy) {
				(*this)._data[i] = (*this)._data[i] + other._data[j];
				break;
			}
		}
	}

	return *this;
}
template<typename T>
MVector<T>& MVector<T>::operator-(const MVector<T> other) {
	if ((*this)._size != other._size) {
		throw std::invalid_argument("The dimensions of the vectors should be equal");
	}
	for (int i = 0; i < other._capacity; i++) {
		if (other._states[i] == busy) {
			other._data[i] = -(other._data[i]);
		}
	}
	return (*this) + other;
	/*for (int i = 0; i < (*this)._capacity; i++)
		if ((*this)._states[i] == busy) {
			for (int j = i; j < other._capacity; j++)
			{
				if (other._states[j] == busy) {
					(*this)._data[i] = (*this)._data[i] - other._data[j];
					break;
				}
			}
		}

	return *this;*/
}
template<typename T>
T MVector<T>::operator*(const MVector<T>& other) {
	T result = T(0);
	if ((*this)._size != other._size) {
		throw std::invalid_argument("The dimensions of the vectors should be equal");
	}
	for (int i = 0; i < (*this)._capacity; i++)
		if (((*this)._states[i] == busy)) {
			for (int j = i; j < other._capacity; j++)
			{
				if (other._states[j] == busy) {
					result += (*this)._data[i] * other._data[j];
					break;
				}
			}
		}

	return result;
}