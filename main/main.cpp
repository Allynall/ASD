// Copyright 2024 Marina Usova

#define EASY_EXAMPLE
#ifdef EASY_EXAMPLE

#include <iostream>
#include <iomanip>
#include "../lib_algorithms/algorithms.cpp"

int main() {
    int N, M;
    std::cout << "Enter the dimensions of the maze N M:";
    std::cin >> N >> M;

    Matrix<bool> walls = generate(N, M);
    print(walls, N, M);

    return 0;
}

#endif  // EASY_EXAMPLE
