#include "algorithms.h"
#include <iostream>

int random_position(Matrix<int> matrix) {
	int pos = rand() % (matrix.get_M());
	return pos;
}

int search_local_minimum_in_matrix(Matrix<int> matrix) {

	if (matrix.get_M() != matrix.get_N()) {
		throw std::invalid_argument("The matrix must be square");
	}
	int pos_matrix_M = random_position(matrix);
	int pos_matrix_N = random_position(matrix);
	int min = matrix[pos_matrix_M][pos_matrix_N];
	int steps = 0;
	while (steps < matrix.get_M() * 2 + 5) {
		int flag = 0;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if ((i == 0 || j == 0) && (i != j)) {

					if (((pos_matrix_M + i) >= 0) && ((pos_matrix_M + i) < matrix.get_M()) && ((pos_matrix_N + j) >= 0) && ((pos_matrix_N + j) < matrix.get_N())) {

						if (matrix[pos_matrix_M + i][pos_matrix_N + j] <= min) {
							pos_matrix_M += i;
							pos_matrix_N += j;
							flag = 1;
							min = matrix[pos_matrix_M][pos_matrix_N];
						}
					}
				}
			}
		}
		if (flag == 0) {
			return min;
		}
		steps++;
	}
}