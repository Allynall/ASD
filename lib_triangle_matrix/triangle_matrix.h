#pragma once
#include "../lib_matrix/matrix.h"

template<typename T>
class TriangleMatrix : public Matrix<T> {
public:
	TriangleMatrix() = default;
	TriangleMatrix(size_t M, size_t N);

	TriangleMatrix<T> operator+(TriangleMatrix<T> matr);
	TriangleMatrix<T> operator-(TriangleMatrix<T> matr);
	TriangleMatrix<T> operator*(TriangleMatrix<T> matr);
	TriangleMatrix<T> operator*(T val);

	void input_triangle_matrix();
	void print_triangle_matrix();
};
template<typename T>
TriangleMatrix<T>::TriangleMatrix(size_t M, size_t N) : Matrix<T>(M, N) {
}

template<typename T>
TriangleMatrix<T> TriangleMatrix<T>::operator+(TriangleMatrix<T> matr) {
	std::cout << "+matr triangle" << std::endl;
	TriangleMatrix<T> result(_M, _N);
	return result;
}

template<typename T>
TriangleMatrix<T> TriangleMatrix<T>::operator-(TriangleMatrix<T> matr) {
	std::cout << "-matr triangle" << std::endl;
	TriangleMatrix<T> result(_M, _N);
	return result;
}

template<typename T>
TriangleMatrix<T> TriangleMatrix<T>::operator*(TriangleMatrix<T> matr) {
	std::cout << "*matr triangle" << std::endl;
	TriangleMatrix<T> result(_M, _N);
	return result;
}

template<typename T>
TriangleMatrix<T> TriangleMatrix<T>::operator*(T val) {
	std::cout << "*val triangle" << std::endl;
	TriangleMatrix<T> result(_M, _N);
	return result;
}
template<typename T>
void TriangleMatrix<T>::input_triangle_matrix() {
	std::cout << "input triangle matrix" << std::endl;
}
template<typename T>
void TriangleMatrix<T>::print_triangle_matrix() {
	std::cout << "print triangle matrix" << std::endl;
}