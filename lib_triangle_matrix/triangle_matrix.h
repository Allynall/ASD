#pragma once
#include "../lib_matrix/matrix.h"

template<typename T>
class TriangleMatrix : public Matrix<T> {
public:
	TriangleMatrix() = default;
	TriangleMatrix(size_t M, size_t N);
	TriangleMatrix(const TriangleMatrix<T>& other); //++

	TriangleMatrix<T> operator+(const TriangleMatrix<T>& matr); //++
	TriangleMatrix<T> operator-(const TriangleMatrix<T>& matr); //++
	TriangleMatrix<T> operator*(const TriangleMatrix<T>& matr); //++ 
	TriangleMatrix<T> operator*(const T& val); //++

	TriangleMatrix<T> operator+=(const TriangleMatrix<T>& matr); //++
	TriangleMatrix<T> operator-=(const TriangleMatrix<T>& matr); //++
	TriangleMatrix<T> operator*=(const TriangleMatrix<T>& matr); //+
	TriangleMatrix<T> operator*=(const T& val); //++
	bool operator==(const TriangleMatrix<T>& other) const; //++
	bool operator!=(const TriangleMatrix<T>& other) const; //++

	void input_triangle_matrix(); //+
	void print_triangle_matrix(); //++

	template<typename T>
	friend std::ostream& operator<<(std::ostream& os, const TriangleMatrix<T>& matrix); //++

	template<typename T>
	friend std::istream& operator>>(std::istream& is, TriangleMatrix<T>& matrix); //+


};
template<typename T>
TriangleMatrix<T>::TriangleMatrix(size_t M, size_t N) : Matrix<T>(0, 0) {
	if (M != N) {
		throw std::invalid_argument("Triangle matrix must be square");
	}

	_M = M;  
	_N = N; 

	this->resize(M);

	for (size_t i = 0; i < M; i++) {
		MVector<T> row(N - i);
		row.set_start_index(i);
		(*this)[i] = row;
	}
}

template<typename T>
TriangleMatrix<T>::TriangleMatrix(const TriangleMatrix<T>& other)
	: Matrix<T>(other) {
}

template<typename T>
TriangleMatrix<T> TriangleMatrix<T>::operator+(const TriangleMatrix<T>& other) { //от матрицы
	TriangleMatrix<T> result(_M, _N);
	for (size_t i = 0; i < _M; i++) {
		result[i] = (*this)[i] + other[i];
	}
	return result;
}

template<typename T>
TriangleMatrix<T> TriangleMatrix<T>::operator-(const TriangleMatrix<T>& other) { //от матрицы
	TriangleMatrix<T> result(_M, _N);
	for (size_t i = 0; i < _M; i++) {
		result[i] = (*this)[i] - other[i];
	}
	return result;
}

template<typename T>
TriangleMatrix<T> TriangleMatrix<T>::operator*(const TriangleMatrix<T>& matr) {
	if (this->_N != matr._M) {
		throw std::invalid_argument("Number of columns in first matrix must equal number of rows in second");
	}

	TriangleMatrix<T> result(this->_M, matr._N);

	for (size_t i = 0; i < this->_M; i++) {
		for (size_t j = i; j < matr._N; j++) {
			T sum = 0;
			for (size_t k = i; k <= j && k < this->_N; k++) {
					sum += (*this)[i][k - i] * matr[k][j - k];
				}
			
			result[i][j - i] = sum;
		}
	}

	return result;
}


template<typename T>
TriangleMatrix<T> TriangleMatrix<T>::operator*(const T& val) { //от матрицы
	TriangleMatrix<T> result(_M, _N);
	for (int i = 0; i < _M; i++) {
		result[i] = (*this)[i] * val;
	}
	return result;
}

template<typename T>
TriangleMatrix<T> TriangleMatrix<T>::operator+=(const TriangleMatrix<T>& other) {
	*this = *this + other;
	return *this;
}
template<typename T>
TriangleMatrix<T> TriangleMatrix<T>::operator-=(const TriangleMatrix<T>& other) {
	*this = *this - other;
	return *this;
}
template<typename T>
TriangleMatrix<T> TriangleMatrix<T>::operator*=(const TriangleMatrix<T>& matr) {
	*this = *this * matr;
	return *this;
}

template<typename T>
TriangleMatrix<T> TriangleMatrix<T>::operator*=(const T& val) {
	*this = *this * val;
	return *this;
}

template<typename T>
bool TriangleMatrix<T>::operator==(const TriangleMatrix<T>& other) const  { //от матрицы
	if (_M != other._M) {
		return false;
	}
	for (size_t i = 0; i < _M; i++) {
		if ((*this)[i] != other[i]) {
			return false;
		}
	}
	return true;
}

template<typename T>
bool TriangleMatrix<T>::operator!=(const TriangleMatrix<T>& other) const { //от матрицы
	return !(*this == other);
}

template<typename T>
void TriangleMatrix<T>::input_triangle_matrix() {
	std::cout << "Input upper triangle matrix " << this->_M << "x" << this->_N << ":" << std::endl;
	std::cout << "Enter only elements on and above diagonal:" << std::endl;

	for (size_t i = 0; i < this->_M; i++) {
		std::cout << "Row " << i + 1 << " (columns " << i + 1 << "-" << this->_N << "): ";

		for (size_t k = 0; k < (*this)[i].size(); k++) {
			T value;
			std::cin >> value;
			(*this)[i][k] = value;
		}
	}
}


template<typename T>
void TriangleMatrix<T>::print_triangle_matrix() {
	std::cout << "Upper triangle matrix " << this->_M << "x" << this->_N << ":" << std::endl;

	if (this->_M == 0 || this->_N == 0) {
		std::cout << "Empty matrix" << std::endl;
		return;
	}

	for (size_t i = 0; i < this->_M; i++) {
		std::cout << "[ ";

		for (size_t j = 0; j < i && j < this->_N; j++) {
			std::cout << "0 ";
		}
		(*this)[i].print_elems();

		std::cout << "]" << std::endl;
	}
	std::cout << std::endl;
}
template<typename T>
std::ostream& operator<<(std::ostream& os, const TriangleMatrix<T>& matrix) {
	size_t size = matrix.get_M();
	os << size << std::endl;

	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < matrix[i].size(); j++) {
			os << matrix[i][j];
			if (j < matrix[i].size() - 1) os << " ";
		}
		if (i < size - 1) os << std::endl;
	}
	return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, TriangleMatrix<T>& matrix) {
	size_t size;
	is >> size;

	if (size <= 0) {
		throw std::invalid_argument("Matrix size must be positive");
	}

	matrix = TriangleMatrix<T>(size);

	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < matrix[i].size(); j++) {
			is >> matrix[i][j];
		}
	}
	return is;
}