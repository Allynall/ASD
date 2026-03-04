#include "../lib_matrix/matrix.h"
#include "../lib_dsu/dsu.h"
#include <iostream>
#include <time.h>

Matrix<bool> generate(int N, int M) {
    Matrix<bool> walls(N + 1, M + 1);

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            walls[i][j] = 1;
        }
    }

    DSU dsu(N * M);

    MVector<int> vector_cell1;
    MVector<int> vector_cell2;
    MVector<int> vector_x;
    MVector<int> vector_y;

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < M; j++) {
            int left_cell = i * M + (j - 1);
            int right_cell = i * M + j;

            vector_cell1.push_back_elem(left_cell);
            vector_cell2.push_back_elem(right_cell);
            vector_x.push_back_elem(i);
            vector_y.push_back_elem(j);
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int top_cell = (i - 1) * M + j;
            int lower_cell = i * M + j;

            vector_cell1.push_back_elem(top_cell);
            vector_cell2.push_back_elem(lower_cell);
            vector_x.push_back_elem(i);
            vector_y.push_back_elem(j);
        }
    }

    MVector<int> indexes;
    for (int i = 0; i < vector_cell1.size(); i++) {
        indexes.push_back_elem(i);
    }

    srand(time(0));
    for (int i = vector_cell1.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = indexes[i];
        indexes[i] = indexes[j];
        indexes[j] = temp;
    }

    for (int k = 0; k < vector_cell1.size() - 1; k++) {
        int idx = indexes[k];

        int cell1 = vector_cell1[idx];
        int cell2 = vector_cell2[idx];
        int x = vector_x[idx];
        int y = vector_y[idx];

        if (dsu.find(cell1) != dsu.find(cell2)) {
            dsu.unionn(cell1, cell2);
            walls[x][y] = 0; 
        }
    }

/*    walls[0][0] = 0;     
    walls[N][M] = 0;  */  

    return walls;
}

void print(Matrix<bool>& walls, int N, int M) {
    std::cout << "\n";

    std::cout << " ";
    for (int j = 0; j < M; j++) {
        std::cout << "+-";
    }
    std::cout << "+\n";

    for (int i = 0; i < N; i++) {
        std::cout << " |";

        for (int j = 0; j < M; j++) {
            if (i == 0 && j == 0) {
                std::cout << "X";
            }
            else if (i == N - 1 && j == M - 1) {
                std::cout << "Y";
            }
            else {
                std::cout << " ";
            }

            if (j < M - 1) {
                if (walls[i][j + 1] == 1) {
                    std::cout << "|";
                }
                else {
                    std::cout << " ";
                }
            }
        }
        std::cout << "|\n";

        if (i < N - 1) {
            std::cout << " +";
            for (int j = 0; j < M; j++) {
                if (walls[i + 1][j] == 1) {
                    std::cout << "-+";
                }
                else {
                    std::cout << " +";
                }
            }
            std::cout << "\n";
        }
    }

    std::cout << " ";
    for (int j = 0; j < M; j++) {
        std::cout << "+-";
    }
    std::cout << "+\n";
}
