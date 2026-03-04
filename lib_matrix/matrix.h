#pragma once
#include "..\lib_math_vector\math_vector.h"

template<typename T>
class Matrix : public MVector<MVector<T>> {
protected:
	size_t _M; 
	size_t _N; 
public:
	Matrix(); //++
	Matrix(size_t M, size_t N); //++
	Matrix(const Matrix<T>& other); //++
	Matrix(const MVector<MVector<T>>& vec);

	size_t get_M() const; //++
	size_t get_N() const; //++

	Matrix<T> operator+(const Matrix<T>& other) const; //++
	Matrix<T> operator-(const Matrix<T>& other) const; //++
	Matrix<T> operator*(const Matrix<T>& matr); //++
	MVector<T> operator*(const MVector<T>& vec); //++
	Matrix<T> operator*(const T& val); //++

	Matrix<T>& operator=(const Matrix<T>& other);

	Matrix<T>& operator+=(const Matrix<T> other); //++
	Matrix<T>& operator-=(const Matrix<T> other); //++
	Matrix<T>& operator*=(const Matrix<T> matr); //++
	Matrix<T>& operator*=(const T val); //++
	bool operator==(const Matrix<T>& other)  const noexcept; //++
	bool operator!=(const Matrix<T>& other)  const noexcept; //++

	void transport(); //++

	void input_matrix(); //++
	void print_matrix(); //++

	template<typename T>
	friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix); //++

	template<typename T>
	friend std::istream& operator>>(std::istream& is, Matrix<T>& matrix); //+
};

template<typename T>
Matrix<T>::Matrix() : MVector<MVector<T>>(0), _M(0), _N(0) {}

template<typename T>
Matrix<T>::Matrix(size_t M, size_t N) : MVector<MVector<T>>(M), _M(M), _N(N) {
	if (M < 0 || N < 0) {
		throw std::invalid_argument("The values must be positive");
	}
	for (size_t i = 0; i < _M; i++) {
		_data[i] = MVector<T>(_N);
	}

}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other) : MVector<MVector<T>>(other), _M(other._M), _N(other._N) {}


template <typename T>
Matrix <T>::Matrix(const MVector<MVector<T>>& vec) : MVector<MVector<T>>(vec), _M(vec.size()), _N(_M > 0 ? vec[0].size() : 0) {}

template<typename T>
size_t Matrix<T>::get_M() const {
	return _M;
}
template<typename T>
size_t Matrix<T>::get_N() const {
	return _N;
}
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
	if (this != &other) {
		MVector<MVector<T>>::operator=(other);
		_M = other._M;
		_N = other._N;
	}
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
	if (((*this).get_M() != other.get_M()) || ((*this).get_N() != other.get_N())) {
		throw std::invalid_argument("The dimensions of the matrix should be equal");
	}
	return this->MVector<MVector<T>>::operator+(other);
}


template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const {
	if (((*this).get_M() != other.get_M()) || ((*this).get_N() != other.get_N())) {
		throw std::invalid_argument("The dimensions of the matrix should be equal");
	}
	return this->MVector<MVector<T>>::operator-(other);
}

template<typename T>
MVector<T> Matrix<T>::operator*(const MVector<T>& vec) {
	if (_N != vec.size()) {
		throw std::invalid_argument("Vector size must equal of matrix columns");
	}
	MVector<T> result(_M);
	for (size_t i = 0; i < _M; i++) {
		result[i] = ((*this)[i] * vec);
	}
	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& matr) {
	if ((*this).get_N() != matr.get_M()) {
		throw std::invalid_argument("Number of columns in first matrix must equal number of rows in second");
	}
	Matrix result(_M, matr.get_N());
	Matrix<T> matr_transposed = matr;
	matr_transposed.transport();
	for (size_t i = 0; i < _M; i++) {
		for (size_t j = 0; j < matr_transposed.get_M(); j++) {
			result[i][j] = ((*this)[i] * matr_transposed[j]);
		}
	}
	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& val) {
	Matrix<T> result(_M, _N);
	for (int i = 0; i < _M; i++) {
		result[i] = (*this)[i] * val;
	}
	return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T> other) {
	*this = *this + other;
	return *this;
}
template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T> other) {
	*this = *this - other;
	return *this;
}
template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T> matr) {
	*this = *this * matr;
	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const T val) {
	*this = *this * val;
	return *this;
}

template<typename T>
bool Matrix<T>::operator==(const Matrix<T>& other)  const noexcept {
	if (_M != other._M || _N != other._N) {
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
bool Matrix<T>::operator!=(const Matrix<T>& other)  const noexcept {
	return !(*this == other);
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

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
	if (matrix._M == 0 || matrix._N == 0) {
		os << "Empty matrix" << std::endl;
		return os;
	}

	os << "Matrix " << matrix._M << "x" << matrix._N << ":" << std::endl;
	for (size_t i = 0; i < matrix._M; i++) {
		os << "[ ";
		for (size_t j = 0; j < matrix._N; j++) {
			os << matrix[i][j];
			if (j < matrix._N - 1) {
				os << " ";
			}
		}
		os << "]" << std::endl;
	}
	os << std::endl;
	return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, Matrix<T>& matrix) {
	std::cout << "Enter matrix " << _M << "x" << _N << ":" << std::endl;
	for (size_t i = 0; i < matrix._M; i++) {
		std::cout << "Row " << i + 1 << ": ";
		for (size_t j = 0; j < matrix._N; ++j) {
			is >> matrix[i][j];
		}
	}

	return is;
}