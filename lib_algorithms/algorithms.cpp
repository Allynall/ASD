#include "algorithms.h"
#include "../lib_stack/stack.h"
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





//Открытие и закрытие скобок
bool check_breckets(std::string str) {
    Stack <char> stack(str.length());
	for (int i = 0; i < str.length(); i++) {

		if ((str[i] == '(') || (str[i] == '[') || (str[i] == '{')) {
			stack.push(str[i]);
		}

		if ((str[i] == char(')')) || (str[i] == char(']')) || (str[i] == char('}'))) {

			if (stack.is_empty()) {
				return false;
			}

			if (stack.top() == char('(') && str[i] != (char(')'))) {
				return false;
			}
			if (stack.top() == char('[') && str[i] != (char(']'))) {
				return false;
			}
			if (stack.top() == char('{') && str[i] != (char('}'))) {
				return false;
			}


			
			stack.pop();
		}

	}
	if (stack.is_empty()) {
		return true;
	}
	return false;
}


bool read_expression(std::string expression) {
	Stack <char> stack(expression.length());
	int count = 0;
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] != ' ') {
			if (expression[i] > 122 || (expression[i] < 39 || expression[i] < 95 && expression[i] > 57) || expression[i] == 46 || expression[i] == 44) {
				return false;
			}
			if (expression[i] == '(' || expression[i] == ')') {
				count++;
			}
		}
	}
	if (count % 2 != 0) {
		return false;
	}
}