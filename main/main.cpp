// Copyright 2024 Marina Usova

//#define EASY_EXAMPLE
//#ifdef EASY_EXAMPLE
//
#include <iostream>
#include <conio.h>
//#include <iomanip>
//#include "../lib_sphere/sphere.h"
#include "../lib_triangle_matrix/triangle_matrix.h"
//
//enum Status { Coincidence, Touch, Intersecting, NotIntersecting };
//
//Status CheckingCoincidence(Circle first, Circle second) {
//    if (first == second) {
//        return Coincidence;
//    }
//    return NotIntersecting;
//}
//Status CheckingCoincidence(Sphere first, Sphere second) {
//    if (first == second) {
//        return Coincidence;
//    }
//    return Intersecting;
//}
//Status CheckingTouch(Circle first, Circle second) {
//    if ((first.get_point().DistanceBetweenPoints(second.get_point())) == (first.get_radius() + second.get_radius())) {
//        return Touch;
//    }
//    else if ((first.get_point().DistanceBetweenPoints(second.get_point())) == (first.get_radius() - second.get_radius())) {
//        return Touch;
//    }
//    return NotIntersecting;
//}
//Status CheckingTouch(Sphere first, Sphere second) {
//    if ((first.get_point3D().DistanceBetweenPoints(second.get_point3D())) == (first.get_radius() + second.get_radius())) {
//        return Touch;
//    }
//    else if ((first.get_point3D().DistanceBetweenPoints(second.get_point3D())) == (first.get_radius() - second.get_radius())) {
//        return Touch;
//    }
//    return Intersecting;
//}
//
//Status CheckingIntersecting(Circle first, Circle second) {
//    if ((first.get_radius() - second.get_radius()) < (first.get_point().DistanceBetweenPoints(second.get_point()))
//        && (first.get_point().DistanceBetweenPoints(second.get_point())) < (first.get_radius() + second.get_radius())) {
//        return Intersecting;
//    }
//    return NotIntersecting;
//}
//Status CheckingNoIntersecting(Sphere first, Sphere second) {
//    if ((first.get_point3D().DistanceBetweenPoints(second.get_point3D())) > (first.get_radius() + second.get_radius())) {
//        return NotIntersecting;
//    }
//    return Intersecting;
//}
//Status CheckingStatus(Circle first, Circle second) {
//    Status status = CheckingCoincidence(first, second);
//    if (status == NotIntersecting) {
//        status = CheckingTouch(first, second);
//        if (status == NotIntersecting) {
//            status = CheckingIntersecting(first, second);
//        }
//        else {
//            return status;
//        }
//    }
//    return status;
//}
//Status CheckingStatus(Sphere first, Sphere second) {
//    Status status = CheckingCoincidence(first, second);
//    if (status == Intersecting) {
//        status = CheckingTouch(first, second);
//        if (status == Intersecting) {
//            status = CheckingIntersecting(first, second);
//        }
//        else {
//            return status;
//        }
//    }
//    return status;
//}
//
//int main() {
//    Point a1(0, 0);
//    Point a2(10, 0);
//    Point a3(5, 0);
//    Point a4(4, 0);
//
//    Circle b1(a1, 4);
//    Circle b2(a1, 4);
//    Circle b3(a2, 6);
//    Circle b4(a1, 8);
//    Circle b5(a3, 3);
//    Circle b6(a1, 5);
//    Circle b7(a4, 3);
//    Circle b8(a2, 3);
//    Circle b9(a1, 2);
//
//    Status CCoincidence = CheckingStatus(b1, b2);
//    Status CExternalTouch = CheckingStatus(b1, b3);
//    Status CInnerTouch = CheckingStatus(b4, b5);
//    Status CIntersecting = CheckingStatus(b6, b7);
//    Status CNotIntersecting = CheckingStatus(b8, b9);
//
//    std::cout << "Circle Coincidence: " << CCoincidence << std::endl;
//    std::cout << "Circle External Touch: " << CExternalTouch << std::endl;
//    std::cout << "Circle Inner Touch: " << CInnerTouch << std::endl;
//    std::cout << "Circle Intersecting: " << CIntersecting << std::endl;
//    std::cout << "Circle NotIntersecting: " << CNotIntersecting << std::endl;
//
//    Point3D d1(0, 0, 0);
//    Point3D d2(12, 0, 0);
//    Point3D d3(4, 0, 0);
//    Point3D d4(5, 0, 0);
//    Point3D d5(10, 0, 0);
//
//    Sphere e1(d1, 4);
//    Sphere e2(d1, 4);
//    Sphere e3(d1, 5);
//    Sphere e4(d2, 7);
//    Sphere e5(d1, 10);
//    Sphere e6(d3, 6);
//    Sphere e7(d1, 6);
//    Sphere e8(d4, 4);
//    Sphere e9(d1, 3);
//    Sphere e10(d5, 4);
//
//    Status SCoincidence = CheckingStatus(e1, e2);
//    Status SExternalTouch = CheckingStatus(e3, e4);
//    Status SInnerTouch = CheckingStatus(e5, e6);
//    Status SIntersecting = CheckingStatus(e7, e8);
//    Status SNotIntersecting1 = CheckingStatus(e9, e10);
//
//    std::cout << "Sphere Coincidence: " << SCoincidence << std::endl;
//    std::cout << "Sphere External Touch: " << SExternalTouch << std::endl;
//    std::cout << "Sphere Inner Touch: " << SInnerTouch << std::endl;
//    std::cout << "Sphere Intersecting: " << SIntersecting << std::endl;
//    std::cout << "Sphere Not Intersecting: " << SNotIntersecting1 << std::endl;
//    return 0;
//}

//#endif  
void matrix_size(size_t *M, size_t *N, int flag) {
	if (flag == 1) {
		std::cout << "Введите размер матрицы, где M - кол-во столбцов, N - кол-во строк" << std::endl;
		std::cout << "M:";
		std::cin >> *M;
		std::cout << std::endl << "N:";
		std::cin >> *N;
	}
	else {
		std::cout << "Введите размер матрицы, матрица является квадратной, поэтому введите одно значени(M*M)" << std::endl;
		std::cout << "M:";
		std::cin >> *M;
		*M = *N;
	}
}

void matrix_output() {

}
void enter_values_matrix() {

}
Matrix<int> sub_matrix(size_t M, size_t N, Matrix<int>* matrix) {
	size_t M_second;
	size_t N_second;

	matrix_size(&M_second, &N_second, 1);
	while ((M != M_second) || (N != N_second)) {
		std::cout << "Введите вычитаемое (вторую матрицу) " << std::endl;
		std::cout << "Размер первой матрицы должен совпадать с размером второй" << std::endl;
		matrix_size(&M_second, &N_second, 1);
	}
	Matrix<int> matrix_2(M_second, N_second);
	matrix_2.input_matrix();
	return (*matrix - matrix_2);
}
Matrix<int> add_matrix(size_t M, size_t N, Matrix<int> *matrix) {
	size_t M_second;
	size_t N_second;

	matrix_size(&M_second, &N_second, 1);
	while ((M != M_second) || (N != N_second)) {
		std::cout << "Введите второе слагаемое (вторую матрицу) " << std::endl;
		std::cout << "Размер первой матрицы должен совпадать с размером второй" << std::endl;
		matrix_size(&M_second, &N_second, 1);
	}
	Matrix<int> matrix_2(M_second, N_second);
	matrix_2.input_matrix();
	return (*matrix+matrix_2);
}
TriangleMatrix<int> add_triangle_matrix(size_t M, size_t N, TriangleMatrix<int>* matrix) {
	std::cout << "Введите второе слагаемое (вторую матрицу) " << std::endl;
	std::cout << "Размер матрицы тот же" << std::endl;
	TriangleMatrix<int> matrix_2(M, N);
	matrix_2.input_triangle_matrix();
	return (*matrix + matrix_2);
}
TriangleMatrix<int> sub_triangle_matrix(size_t M, size_t N, TriangleMatrix<int>* matrix) {

	std::cout << "Введите вычитаемое (вторую матрицу) " << std::endl;
	std::cout << "Размер матрицы тот же" << std::endl;
	TriangleMatrix<int> matrix_2(M, N);
	matrix_2.input_triangle_matrix();
	return (*matrix - matrix_2);
}
TriangleMatrix<int> mult_triangle_matrix_with_matrix(size_t* M, size_t* N, TriangleMatrix<int>* matrix) {
	std::cout << "----УМНОЖЕНИЕ НА МАТРИЦУ----" << std::endl;

	std::cout << "Введите второе слагаемое (вторую матрицу) " << std::endl;
	std::cout << "Размер матрицы тот же" << std::endl;

	TriangleMatrix<int> matrix_2(*M, *N);
	matrix_2.input_triangle_matrix();
	return (*matrix * matrix_2);

}
TriangleMatrix<int> mult_triangle_matrix_with_number(TriangleMatrix<int>* matrix) {
	int number = 0;
	std::cout << "----УМНОЖЕНИЕ НА СКАЛЯР----" << std::endl;
	std::cout << "Введите число: ";
	std::cin >> number;


	return (*matrix * number);
}
Matrix<int> mult_matrix_with_number(Matrix<int> *matrix) {
	int number = 0;
	std::cout << "----УМНОЖЕНИЕ НА СКАЛЯР----" << std::endl;
	std::cout << "Введите число: ";
	std::cin >> number;


	return (*matrix * number);
}
//void mult_matrix_with_vector() {
//	int number = 0;
//	std::cout << "----УМНОЖЕНИЕ НА ВЕКТОР----" << std::endl;
//	std::cout << "Введите вектор: ";
//}
Matrix<int> mult_matrix_with_matrix(size_t *M, size_t *N, Matrix<int>* matrix) {
	std::cout << "----УМНОЖЕНИЕ НА МАТРИЦУ----" << std::endl;
	size_t M_second;
	size_t N_second;

	matrix_size(&M_second, &N_second, 1);
	while ((*M != N_second) || (*N != M_second)) {
		std::cout << "Введите второе слагаемое (вторую матрицу) " << std::endl;
		std::cout << "Размер второй матрицы должен быть N, M (M, N как у первой)" << std::endl;
		matrix_size(&M_second, &N_second, 1);
	}
	Matrix<int> matrix_2(M_second, N_second);
	matrix_2.input_matrix();
	return (*matrix * matrix_2);

}

void enter_matrix(size_t *M, size_t *N, Matrix<int> *matrix, int flag) {
	matrix_size(M, N, flag);
	matrix->input_matrix();
}
void choose_main_menu(char *choice, size_t *M, size_t *N, Matrix<int>* matrix) {
	std::cout << "Ваш выбор: ";
	*choice = _getch();
	system("cls");
	if (*choice == '1') {
	}
	else if (*choice == '2') {
		add_matrix(*M, *N, matrix);
	}
	else if (*choice == '3') {
		sub_matrix(*M, *N, matrix);
	}
	else if (*choice == '4') {
		mult_matrix_with_number(matrix);
	}
	else if (*choice == '5') {
		mult_matrix_with_matrix(M, N, matrix);
	}
}
void choose_triangle_menu(char* choice, size_t* M, size_t* N, TriangleMatrix<int>* matrix) {
	std::cout << "Ваш выбор: ";
	*choice = _getch();
	system("cls");
	if (*choice == '1') {
	}
	else if (*choice == '2') {
		add_triangle_matrix(*M, *N, matrix);
	}
	else if (*choice == '3') {
		sub_triangle_matrix(*M, *N, matrix);
	}
	else if (*choice == '4') {
		mult_triangle_matrix_with_number(matrix);
	}
	else if (*choice == '5') {
		mult_triangle_matrix_with_matrix(M, N, matrix);
	}
}


void main_menu() {

	std::cout << "----МАТРИЦЫ----" << std::endl;
	std::cout << "1. Ввести матрицу" << std::endl;
	std::cout << "2. Сложение " << std::endl;
	std::cout << "3. Вычитание" << std::endl;
	std::cout << "4. Умножение на скаляр" << std::endl;
	std::cout << "5. Умножение на матрицу" << std::endl;
	std::cout << "6. Назад" << std::endl;


}
void work_with_matrix(size_t* M, size_t* N, char* choice) {
	Matrix<int> matrix_1;
	enter_matrix(M, N, &matrix_1, 1);
	while (*choice != '6') {
		std::cout << "Ваша матрица: ";
		matrix_1.print_matrix();
		std::cout << std::endl;
		main_menu();
		choose_main_menu(choice, M, N, &matrix_1);
	}
}
void work_with_triangle_matrix(size_t* M, size_t* N, char* choice) {
	Matrix<int> matrix_1;
	enter_matrix(M, N, &matrix_1, 1);
	while (*choice != '6') {
		std::cout << "Ваша матрица: ";
		matrix_1.print_matrix();
		std::cout << std::endl;
		main_menu();
		choose_main_menu(choice, M, N, &matrix_1);
	}
}
void choose_type_menu(char* choice) {
	size_t M, N;
	std::cout << "Ваш выбор: ";
	*choice = _getch();
	system("cls");
	
		if (*choice == '1') {
			work_with_matrix(&M, &N, choice);
		}
		else if (*choice == '2') {
			work_with_triangle_matrix(&M, &N, choice);
		}
	
}

void matrix_type_menu() {
	std::cout << "----ДОБРО ПОЖАЛОВАТЬ----" << std::endl;
	std::cout << "С какими матрицами вы хотите работать?" << std::endl;
	std::cout << "1. Обычный вид" << std::endl;
	std::cout << "2. Треугольный вид" << std::endl;
	std::cout << "3. Выход" << std::endl;
}




int main() {
	char choice = 10;
	setlocale(LC_ALL, "Russian");
	std::cout << std::endl;
	while (choice != '3') {
		matrix_type_menu();
		choose_type_menu(&choice);
	}
	return 0;
}