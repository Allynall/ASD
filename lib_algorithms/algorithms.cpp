#include "algorithms.h"
#include "../lib_stack/stack.h"
#include "../lib_dsu/dsu.h"
#include "../lib_list/list.h"
#include "../lib_triangle_matrix/triangle_matrix.h"
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





//ќткрытие и закрытие скобок
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


//bool read_expression(std::string expression) {
//	Stack <char> stack(expression.length());
//	int count = 0;
//	for (int i = 0; i < expression.length(); i++) {
//		if (expression[i] != ' ') {
//			if (expression[i] > 122 || (expression[i] < 39 || expression[i] < 95 && expression[i] > 57) || expression[i] == 46 || expression[i] == 44) {
//				return false;
//			}
//			if (expression[i] == '(' || expression[i] == ')') {
//				count++;
//			}
//		}
//	}
//	if (count % 2 != 0) {
//		return false;
//	}
//}

template <class T>
bool is_looped_one_test(List<T>(*list)) {
	List<T>::Iterator it_1 = (*list).begin();
	List<T>::Iterator it_2 = (*list).begin();
	while (it_1 != (*list).end() && it_2 != (*list).end())
	{
		++it_1;
		++it_2;
		if (it_2 == nullptr) {
			return false;
		}

		++it_2;
		if (it_1 == it_2) {
			return true;
		}
	}
	return false;
}

template <class T>
void expand_pointers(Node<T>**current, Node<T>**next, Node<T>**prev) {
	*next = (*current)->next;
	(*current)->next = *prev;
	*prev = *current;
	*current = *next;
}

template <class T>
bool is_looped_second_test(List<T>(*list)) {
	Node<T>* current = (*list).head();
	Node<T>* next = current->next;
	Node<T>* prev = nullptr;

	Node<T>* head = (*list).head();

	bool result = false;

	while (next != nullptr) {
		expand_pointers(&current, &next, &prev);
		
		if (current == head) {
			result = true;
		}
		
	}
	current = prev;
	prev = nullptr;

	while (current != nullptr) {
		expand_pointers(&current, &next, &prev);
	}

	return result;

}

template <class T>
Node<T>* is_looped_third_test(List<T>(*list)) {

	List<T>::Iterator it_1 = (*list).begin();
	List<T>::Iterator it_2 = (*list).begin();
	while (it_1 != (*list).end() && it_2 != (*list).end())
	{
		++it_1;
		++it_2;
		if (it_2 == nullptr) {
			return nullptr;
		}

		++it_2;
		if (it_1 == it_2) {
			break;
		}
	}


	it_2 = (*list).begin();
	while (it_2 != it_1) {
		++it_2;
		++it_1;
	}
	return it_1.getNode();
}

int count_islands(int** mass, int x, int y) {
	DSU dsu_island(x * y);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (mass[i][j] == 1) {
				int current_index = i * y + j;
					if (j != y - 1 && mass[i][j + 1] == 1) {
						int right_index = i * y + (j + 1);
						dsu_island.unionn(current_index, right_index);
				
					}
				    if (i != x - 1 && mass[i + 1][j] == 1) {
						int bottom_index = (i + 1) * y + j;
						dsu_island.unionn(current_index, bottom_index);
					}
				
			}

		}
	}
	int count = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (mass[i][j] == 1) {
				int index = i * y + j;
				if (dsu_island.find(index) == index) {
					count++;
				}
			}
		}
	}

	return count;
}
void write_parameters(size_t *N, size_t *M, size_t *x, size_t *y) {
	std::cout << "¬ведите M (размер матрицы M): ";
	std::cin >> *N;
	std::cout << "¬ведите N (размер матрицы N): ";
	std::cin >> *M;
    //добавить проверку
		std::cout << "¬ведите x (точка входа): ";
		std::cin >> *x;
		std::cout << "¬ведите y (точка выхода): ";
		std::cin >> *y;
}

void fill_field(Matrix<size_t> *field, size_t M, size_t N) {
	for (size_t i = 0; i < M; i++) {
		for (size_t j = 0; j < N; j++) {
			(*field)[i][j] = 1;
		}
	}
}

void print_field(size_t M, size_t N) {
	size_t n = 0;
	for (int i = 0; i < M; i++) {
		std::cout << std::endl;
		std::cout << "|";
		for (int j = 0; j < N; j++) {
			n++;
			std::cout << n << "|";

		}
	}
}

void random_combinations(DSU *dsu, size_t M, size_t N) {
	size_t flag = 0;
	for (int i = 0; i < M*N-1; i++) {
		flag = rand() % 2;
		if (flag == 1) {
			(*dsu).unionn(i, i + 1);
		}
	}
}
void Maze() {
	size_t N, M, x, y;
	write_parameters(&N, &M, &x, &y);

	Matrix<size_t> field(M,  N);
	fill_field(&field, M, N);
	print_field(M, N);

	DSU dsu(M * N);
	random_combinations(&dsu, M, N);
}