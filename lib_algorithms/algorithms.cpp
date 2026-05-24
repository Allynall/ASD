#include "../lib_matrix/matrix.h"
#include "../lib_dsu/dsu.h"
#include "../lib_heap/heap.h"
#include "../lib_bs_tree/bs_tree.h"
#include "../lib_hash_table/hash_table.h"
#include "../lib_graph/graph.h"
#include "../lib_pr_queue/pr_queue.h"
#include <iostream>
#include <time.h>

Matrix<int> generate(int N, int M) {
    int rows = 2 * N + 1;  
    int cols = M + 1;
    Matrix<int> labirint(rows, cols);
    //srand(time(0));
    //srand(18);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            labirint[i][j] = 1;
        }
    }

    DSU dsu(N * M);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int current = i * M + j;

            if (j < M - 1) {
                if (rand() % 100 < 40) {  
                    int right = i * M + (j + 1);
                    if (dsu.find(current) != dsu.find(right)) {
                        dsu.unionn(current, right);
                        labirint[2 * i + 1][j + 1] = 0;  
                    }
                }
            }

            if (i < N - 1) {
                if (rand() % 100 < 40) {  
                    int bottom = (i + 1) * M + j;
                    if (dsu.find(current) != dsu.find(bottom)) {
                        dsu.unionn(current, bottom);
                        labirint[2 * i + 2][j] = 0;  
                    }
                }
            }
        }
    }

    int start_cell = 0;
    int end_cell = N * M - 1;

    while (dsu.find(start_cell) != dsu.find(end_cell)) {
        int i = rand() % N;
        int j = rand() % M;
        int current = i * M + j;
        int direction = rand() % 100;

        if (direction < 50 && j < M - 1) { 
            int right = i * M + (j + 1);
            if (dsu.find(current) != dsu.find(right)) {
                dsu.unionn(current, right);
                labirint[2 * i + 1][j + 1] = 0;
            }
        }
        else if (direction >= 50 && i < N - 1) {  
            int bottom = (i + 1) * M + j;
            if (dsu.find(current) != dsu.find(bottom)) {
                dsu.unionn(current, bottom);
                labirint[2 * i + 2][j] = 0;
            }
        }
    }

    labirint[0][0] = 0;  

    labirint[2 * N][M - 1] = 0;  

    return labirint;
}

void print(Matrix<int>& labirint, int N, int M) {
    std::cout << "\n";

    for (int i = 0; i < 2 * N + 1; ++i) {
        if (i % 2 == 0) {  
            for (int j = 0; j < M; ++j) {
                std::cout << "+";

                if (i == 0 && j == 0) {
                    std::cout << " X ";  
                }
                else if (i == 2 * N && j == M - 1) {
                    std::cout << " Y ";  
                }
                else if (labirint[i][j] == 1) {
                    std::cout << "---";
                    
                }
                else {
                    std::cout << "   ";
                }
            }
            std::cout << "+\n";
        }
        else {  
            for (int j = 0; j < M + 1; ++j) {
                if (labirint[i][j] == 1) {
                    std::cout << "|   ";
                }
                else {
                    std::cout << "    ";
                }
            }
            std::cout << "\n";
        }
    }
}

template <class TKey, class TValue>
void bypassingHeap(NodeTr<TKey, TValue>* node, TVector<NodeTr<TKey, TValue>>& result) {
    if (!node) return;

    bypassingHeap(node->left, result);
    result.push_back_elem(*node);
    bypassingHeap(node->right, result);
}


template <class T>
TVector<T> heapSort(const TVector<T>& data) {
    Heap<T> heap(data);
    TVector<T> result;

    while (!heap.is_empty()) {
        T element = heap.erase_root();
        result.push_back_elem(element);
    }
    return result;
}

template <class TKey, class TValue>
TVector<NodeTr<TKey, TValue>> BSTSort(const TVector<NodeTr<TKey, TValue>>& data) {
    BSTree<TKey, TValue> bst;

    for (size_t i = 0; i < data.size(); i++) {
        bst.insert(data[i].data.first, data[i].data.second);
    }
    TVector<NodeTr<TKey, TValue>> result;
    bypassingHeap(bst.root(), result);

    return result;
}


template <typename T>
void mergeArrays(const std::pair<std::string, T>* arr1, size_t size1, const std::pair<std::string, T>* arr2, size_t size2, HashTable<T>& table) {
    //HashTable<T> table(size1 + size2);

    for (size_t i = 0; i < size1; i++) {
        table.insert(arr1[i].first, arr1[i].second);
    }

    for (size_t i = 0; i < size2; i++) {
        try {
            table.found(arr2[i].first); 
        }
        catch (const std::logic_error&) {
            table.insert(arr2[i].first, arr2[i].second);
        }
    }
    //table.print();
}

template <typename T>
TVector<Vertex<T>> Dijkstra_algorithm(Graph<T>& graph, const Vertex<T>& source, const Vertex<T>& target) {
    int count_vertex = graph.getVertexCount();
    TVector<int> dist;
    //TVector<bool> visited;
    TVector<int> previous;

    for (int i = 0; i < count_vertex; i++) {
        dist.push_back_elem(INT_MAX);
        //visited.push_back_elem(false);
        previous.push_back_elem(-1);
    }

    PrQueue<T> queue;

    int source_idx = graph.getVertexIndex(source);
    int target_idx = graph.getVertexIndex(target);

    if (source_idx == -1 || target_idx == -1) {
        throw std::logic_error("Incorrectly submitted vertex");
    }
    dist[source_idx] = 0;
    queue.push(0, source._value);

    while (!queue.is_empty()) {
        NodePr<T> current = queue.pop();
        Vertex<T> current_vertex = current.value;
        int v_idx = graph.getVertexIndex(current_vertex);

        if (v_idx < 0 || v_idx >= count_vertex) {
            continue;
        }

        int cur_dist = current.priority;

        if (cur_dist > dist[v_idx]) {
            continue;
        }

        if (current_vertex == target) {
            TVector<Vertex<T>> path;
            int current = target_idx;
            while (current != -1) {
                path.push_front_elem(graph.getVertex(current)); 
                current = previous[current];
            }
            return path;
        }

       /* if (visited[v_idx]) {
            continue;
        }

        visited[v_idx] = true;*/
        


        List<std::pair<Vertex<T>, int>> neighbors = graph.get_neighbors_with_weights(v_idx);
        for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
            std::pair<Vertex<T>, int> edge = *it;
            Vertex<T> neighbor = edge.first;
            int weight = edge.second;
            int neighbor_idx = graph.getVertexIndex(neighbor);

            if (/*!visited[neighbor_idx] && */dist[v_idx] != INT_MAX) {
                int new_dist = dist[v_idx] + weight;
                if (new_dist < dist[neighbor_idx]) {
                    dist[neighbor_idx] = new_dist;
                    previous[neighbor_idx] = v_idx;
                    queue.push(new_dist, neighbor._value);
                }
            }
        }
    }
    return TVector<Vertex<T>>();
}


Graph<int> mazeToGraph(const Matrix<int>& labirint, int N, int M) {
    TVector<std::pair<Vertex<int>, Vertex<int>>> edges;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int current = i * M + j;
            if (j < M - 1 && labirint[2 * i + 1][j + 1] == 0) {
                int right = i * M + (j + 1);
                edges.push_back_elem({ Vertex<int>(current), Vertex<int>(right) });
            }



            if (i < N - 1 && labirint[2 * i + 2][j] == 0) {
                int down = (i + 1) * M + j;
                edges.push_back_elem({ Vertex<int>(current), Vertex<int>(down) });
            }
        }
    }
    Graph<int> graph(edges, false);
    return graph; 

}
void print_path(Matrix<int>& labirint, int N, int M, const TVector<Vertex<int>>& path) {
    bool* PachCell = new bool[N * M]();
    for (int i = 0; i < path.size(); i++) {
        PachCell[path[i]._value] = true;
    }

    std::cout << "\n";
    for (int i = 0; i < 2 * N + 1; i++) {
        if (i % 2 == 0) {  
            for (int j = 0; j < M; j++) {
                std::cout << "+";
                if (i == 0 && j == 0) {
                    std::cout << " X " ;
                }
                else if (i == 2 * N && j == M - 1) {
                    std::cout << " Y ";
                }
                else if (labirint[i][j] == 1) {
                    std::cout << "---";
                }
                else {
                    std::cout << "   ";
                }
            }
            std::cout << "+\n";
        }
        else {  
            int roomRow = (i - 1) / 2;

            std::cout << "| ";

            for (int j = 0; j < M; j++) {
                int roomIdx = roomRow * M + j;

                if (PachCell[roomIdx]) {
                    std::cout << "* ";
                }
                else {
                    std::cout << "  ";
                }

                if (j < M - 1) {
                    if (labirint[i][j + 1] == 1) {
                        std::cout << "| ";
                    }
                    else {
                        std::cout << "  ";
                    }
                }
            }

            std::cout << "|\n";
        }
    }

    delete[] PachCell;

    }
void finding_path(Matrix<int>& labirint, int N, int M) {
    Graph<int> graph = mazeToGraph(labirint, N, M);

    Vertex<int> start(0);
    Vertex<int> end(N * M - 1);

    TVector<Vertex<int>> path = Dijkstra_algorithm(graph, start, end);
    for (int i = 0; i < path.size(); i++) {
        std::cout << path[i]._value;
        if (i < path.size() - 1) {
            std::cout << " -> ";
        }
    }
    print_path(labirint, N, M, path);
}

