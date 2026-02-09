#pragma once
#include "..\lib_tvector\tvector.h"

template<typename T>
class MVector : public TVector<T> {
	size_t _start_index = 0;
public:
	MVector() : TVector<T>() {} //++
	MVector(const T* arr, size_t size) : TVector<T>(arr, size) {} //++
	MVector(size_t size) : TVector<T>(size), _start_index(0) {}
	MVector(const MVector<T>& other) : TVector<T>(other), _start_index(other._start_index) {}
    MVector(std::initializer_list<T> init_list) : TVector<T>(init_list), _start_index(0) {}


	size_t start_index() const noexcept;
	void set_start_index(size_t index);

	MVector<T> operator+(const MVector<T>& other) const; //++
	MVector<T> operator-(const MVector<T>& other) const; //++
	T operator*(const MVector<T>& other);
	MVector<T> operator*(const T& num);   //++
	MVector<T> operator/(const T& num);  //++

	MVector<T>& operator+=(const MVector<T>& other); //++
	MVector<T>& operator-=(const MVector<T>& other); //++
	MVector<T>& operator*=(const T& num);   //++
	MVector<T>& operator/=(const T& num); //++

};


template<class T>
size_t MVector<T>::start_index() const noexcept { return _start_index; }

template<class T>
void MVector<T>::set_start_index(size_t index) { _start_index = index; }



template<typename T>
MVector<T> MVector<T>::operator*(const T& num) {
	MVector<T> result(*this);
	for (size_t i = 0; i < result._size; i++) {
		result._data[i] = result._data[i] * num;
    }
    return result;
}

template<typename T>
MVector<T> MVector<T>::operator/(const T& num) {
	if (num == T(0)) {
		throw std::invalid_argument("Division by zero");
	}

	MVector<T> result(*this);

	for (size_t i = 0; i < result._size; i++) {
		result._data[i] = result._data[i] / num;
	}

	return result;
}
template<typename T>
MVector<T> MVector<T>::operator+(const MVector<T>& other) const {
	if ((*this)._size != other._size) {
		throw std::invalid_argument("The dimensions of the vectors should be equal");
	}
	MVector<T> result(*this);
	for (int i = 0; i < (*this)._size; i++)
	{
		result._data[i] = result._data[i] + other._data[i];
		
	}

	return result;
}
template<typename T>
MVector<T> MVector<T>::operator-(const MVector<T>& other) const {
	if ((*this)._size != other._size) {
		throw std::invalid_argument("The dimensions of the vectors should be equal");
	}
	MVector<T> result(*this);
	for (int i = 0; i < (*this)._size; i++)
	{
		result._data[i] = result._data[i] - other._data[i];

	}
	return result;
}

template<typename T>
T MVector<T>::operator*(const MVector<T>& other) {
	T result = T(0);
	if ((*this)._size != other._size) {
		throw std::invalid_argument("The dimensions of the vectors should be equal");
	}
	for (int i = 0; i < (*this)._size; i++) {
		result += (*this)._data[i] * other._data[i];

	}
	return result;
}

template<typename T>
MVector<T>& MVector<T>::operator+=(const MVector<T>& other) {
	*this = *this + other;
	return *this;
}
template<typename T>
MVector<T>& MVector<T>::operator-=(const MVector<T>& other) {
	*this = *this - other; 
	return *this;
}
template<typename T>
MVector<T>& MVector<T>::operator*=(const T& num) {
	*this = *this * num;
	return *this;
}
template<typename T>
MVector<T>& MVector<T>::operator/=(const T& num) {
	*this = *this / num; 
	return *this;
}