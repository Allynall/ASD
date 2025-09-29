#pragma once
#include "..\lib_tvector\tvector.h"

template<typename T>
class MVector : public TVector<T> {
public:
	MVector() : TVector<T>() {}
	MVector(const T*, size_t) : TVector<T>(const T*, size_t) {}
	MVector(const TVector<T>& other) : TVector<T>(other) {}

	MVector<T> operator+(const MVector<T>& other) const;
	MVector<T> operator-(const MVector<T>& other) const;
	MVector<T> operator*(const MVector<T>& other) const;

	MVector<T>& operator*(const T& num);   //++
	MVector<T>& operator/(const T& num); 

	//транспонирование
};

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