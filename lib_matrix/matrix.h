#pragma once
#include "..\lib_math_vector\math_vector.h"

template<typename T>
class Matrix : public MVector<MVector<T>>{
protected:
	size_t _M; //строки
	size_t _N; //столбцы
public:
	Matrix(); //++
	Matrix(size_t M, size_t N); //++
	Matrix(Matrix<T>& other); //++

	size_t get_M() const; //++
	size_t get_N() const; //++

	Matrix<T> operator+(Matrix<T> other); //++
	Matrix<T> operator-(Matrix<T> other); //++
	Matrix<T> operator*(Matrix<T> matr); //++
	MVector<T> operator*(MVector<T> vec); //++
	Matrix<T> operator*(T val); //++

	void transport(); //++

	void input_matrix(); //+
	void print_matrix(); //+
};

template<typename T>
Matrix<T>::Matrix() {
	_M = 0;
	_N = 0;
	this->resize(_M);
}

template<typename T>
Matrix<T>::Matrix(size_t M, size_t N) {
	_M = M;
	_N = N;
	this->resize(_M);
	for (size_t i = 0; i < _M; i++) {
		(*this)[i].resize(_N);
	}

}

template<typename T>
Matrix<T>::Matrix(Matrix<T>& other) : _M(other._M), _N(other._N) {
	this->resize(_M);
	for (size_t i = 0; i < _M; i++) {
		(*this)[i] = other[i];
	}
}

template<typename T>
size_t Matrix<T>::get_M() const{
	return _M;
}
template<typename T>
size_t Matrix<T>::get_N() const {
	return _N;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> other) {
	if (((*this).get_M() != other.get_M()) || ((*this).get_N() != other.get_N())) {
		throw std::invalid_argument("The dimensions of the matrix should be equal");
	}
	Matrix<T> result(_M, _N);
	for (int i = 0; i < _M; i++) {
		result[i] = (*this)[i] + other[i];
	}
	return result;
}


template<typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> other) {
	if (((*this).get_M() != other.get_M()) || ((*this).get_N() != other.get_N())) {
		throw std::invalid_argument("The dimensions of the matrix should be equal");
	}
	Matrix<T> result(_M, _N);
	for (int i = 0; i < _M; i++) {
		result[i] = (*this)[i] - other[i];
	}
	return result;
}

template<typename T>
MVector<T> Matrix<T>::operator*(MVector<T> vec) {
	MVector<T> result(_M);
	for (size_t i = 0; i < _M; i++) {
		result[i] = ((*this)[i] * vec);
	}
	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*( Matrix<T> matr) {
	if ((*this).get_N() != matr.get_M()) {
		throw std::invalid_argument("Написать ");
	}
	Matrix result(_M, matr.get_N());
	matr.transport();
	for (size_t i = 0; i < _M; i++) {
		for (size_t j = 0; j < matr.get_M(); j++) {
			result[i][j] = ((*this)[i] * matr[j]);
		}
	}
	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(T val) {
	Matrix<T> result(_M, _N);
	for (int i = 0; i < _M; i++) {
		result[i] = (*this)[i] * val;
	}
	return result;
}
template<typename T>
void Matrix<T>::transport() {
	Matrix result(_N, _M);
	for (size_t i = 0; i < _N; i++) {
		for (size_t j = 0; j < _M; j++) {
			result[i][j] = (*this)[j][i];
		}
	}

	*this = result;
}
template<typename T>
void Matrix<T>::input_matrix() {
	std::cout << "input matrix" << std::endl;
	std::cout << "Enter matrix " << _M << "x" << _N << ":" << std::endl;
	for (size_t i = 0; i < _M; i++) {
		std::cout << "Row " << i + 1 << ": ";
		for (size_t j = 0; j < _N; ++j) {
			std::cin >> (*this)[i][j];	
		}
	}
}
template<typename T>
void Matrix<T>::print_matrix() {
	std::cout << "print matrix" << std::endl;
	if (_M == 0 || _N == 0) {
		std::cout << "Empty matrix" << std::endl;
		return;
	}

	std::cout << "Matrix " << _M << "x" << _N << ":" << std::endl;
	for (size_t i = 0; i < _M; i++) {
		std::cout << "[ ";
			(*this)[i].print_elems();
		std::cout << "]" << std::endl;
	}
	std::cout << std::endl;
}