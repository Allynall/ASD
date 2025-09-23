#pragma once

template<typename T>
class Matrix {
protected:
	size_t _M;
	size_t _N;
public:
	Matrix() = default;
	Matrix(size_t M, size_t N);

	Matrix<T> operator+(Matrix<T> matr);
	Matrix<T> operator-(Matrix<T> matr);
	Matrix<T> operator*(Matrix<T> matr);
	Matrix<T> operator*(T val);

	void input_matrix();
	void print_matrix();
};
template<typename T>
Matrix<T>::Matrix(size_t M, size_t N) : _M(M), _N(N) {
}

template<typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> matr) {
	std::cout << "+matr" << std::endl;
	Matrix<T> result(_M, _N);
	return result;
}


template<typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> matr) {
	std::cout << "-matr" << std::endl;
	Matrix<T> result(_M, _N);
	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*( Matrix<T> matr) {
	std::cout << "*matr" << std::endl;
	Matrix<T> result(_M, _N);
	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(T val) {
	std::cout << "*val" << std::endl;
	Matrix<T> result(_M, _N);
	return result;
}
template<typename T>
void Matrix<T>::input_matrix() {
	std::cout << "input matrix" << std::endl;
}
template<typename T>
void Matrix<T>::print_matrix() {
	std::cout << "print matrix" << std::endl;
}