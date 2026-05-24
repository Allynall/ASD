#pragma once

#include <iostream>
#include <iomanip>
#include "../lib_matrix/matrix.h"
#include "../lib_tvector/tvector.h"
#include "../lib_graph/graph.h"

template <class T>
class GraphMatrix {
private:
    Matrix<int> _matrix;
    TVector<Vertex<T>> _vertexes;
    bool _is_directed;


public:
    GraphMatrix(TVector<std::pair<Vertex<T>, Vertex<T>>> edges, bool is_directed = false);
    GraphMatrix(TVector<std::pair<std::pair<Vertex<T>, Vertex<T>>, int>> edges, bool is_directed = false);

    void add_edge(const Vertex<T>& source, const Vertex<T>& target, int weight = 1);
    void delete_edge(const Edge<T>& edge);
    void delete_vertex(const Vertex<T>& vertex);

    void print() const;
    int getVertexCount() const;
    Vertex<T> getVertex(int index) const;
    int getWeight(int i, int j) const;

private:
    int getVertexIndex(const Vertex<T>& vertex) const;
    Matrix<int> initMatrix(int size, Matrix<int> matrix);
    void addVertexIfNotExists(const Vertex<T>& vertex);
};

template <class T>
int GraphMatrix<T>::getVertexIndex(const Vertex<T>& vertex) const {
    for (int i = 0; i < _vertexes.size(); i++) {
        if (_vertexes[i] == vertex) return i;
    }
    return -1;
}

template <class T>
Matrix<int> GraphMatrix<T>::initMatrix(int size, Matrix<int> matrix) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

template <class T>
void GraphMatrix<T>::addVertexIfNotExists(const Vertex<T>& vertex) {
    if (getVertexIndex(vertex) != -1) return;

    int old_size = _vertexes.size();
    _vertexes.push_back_elem(vertex);

    Matrix<int> new_matrix(old_size + 1, old_size + 1);

    new_matrix = initMatrix(old_size + 1, new_matrix);

    for (int i = 0; i < old_size; i++) {
        for (int j = 0; j < old_size; j++) {
            new_matrix[i][j] = _matrix[i][j];
        }
    }

    _matrix = new_matrix;
}

template <class T>
GraphMatrix<T>::GraphMatrix(TVector<std::pair<Vertex<T>, Vertex<T>>> edges, bool is_directed)
    : _is_directed(is_directed) {
    for (int i = 0; i < edges.size(); i++) {
        add_edge(edges[i].first, edges[i].second, 1);
    }
}

template <class T>
GraphMatrix<T>::GraphMatrix(TVector<std::pair<std::pair<Vertex<T>, Vertex<T>>, int>> edges, bool is_directed)
    : _is_directed(is_directed) {
    for (int i = 0; i < edges.size(); i++) {
        add_edge(edges[i].first.first, edges[i].first.second, edges[i].second);
    }
}

template <class T>
void GraphMatrix<T>::add_edge(const Vertex<T>& source, const Vertex<T>& target, int weight) {
    addVertexIfNotExists(source);
    addVertexIfNotExists(target);

    int i = getVertexIndex(source);
    int j = getVertexIndex(target);

    _matrix[i][j] = weight;
    if (!_is_directed) {
        _matrix[j][i] = weight;
    }
}

template <class T>
void GraphMatrix<T>::delete_edge(const Edge<T>& edge) {
    int i = getVertexIndex(edge._source);
    int j = getVertexIndex(edge._target);

    if (i == -1 || j == -1) {
        throw std::runtime_error("Vertex not found");
    }

    _matrix[i][j] = 0;
    if (!_is_directed) {
        _matrix[j][i] = 0;
    }
}

template <class T>
void GraphMatrix<T>::delete_vertex(const Vertex<T>& vertex) {
    int idx = getVertexIndex(vertex);
    if (idx == -1) {
        throw std::runtime_error("Vertex not found");
    }

    _vertexes.erase_elem(idx + 1);

    int new_size = _vertexes.size();
    if (new_size == 0) {
        _matrix = Matrix<int>(0, 0);
        return;
    }

    Matrix<int> new_matrix(new_size, new_size);

    new_matrix = initMatrix(new_size, new_matrix);

    int new_i = 0;
    for (int old_i = 0; old_i < _matrix.get_M(); old_i++) {
        if (old_i == idx) continue; //стр

        int new_j = 0;
        for (int old_j = 0; old_j < _matrix.get_N(); old_j++) {
            if (old_j == idx) continue; //столб
            new_matrix[new_i][new_j] = _matrix[old_i][old_j];
            new_j++;
        }
        new_i++;
    }

    _matrix = new_matrix;
}

template <class T>
void GraphMatrix<T>::print() const {
    setlocale(LC_ALL, "RUS");
    int size = _vertexes.size();

    if (size == 0) {
        std::cout << "Граф пуст\n";
        return;
    }

    std::cout << "    ";
    for (int i = 0; i < size; i++) {
        std::cout << std::setw(4) << _vertexes[i]._value;
    }
    std::cout << "\n";

    for (int i = 0; i < size; i++) {
        std::cout << std::setw(4) << _vertexes[i]._value;
        for (int j = 0; j < size; j++) {
            int val = _matrix[i][j];
            std::cout << std::setw(4) << val;
    
        }
        std::cout << "\n";
    }
}

template <class T>
int GraphMatrix<T>::getVertexCount() const {
    return _vertexes.size();
}

template <class T>
Vertex<T> GraphMatrix<T>::getVertex(int index) const {
    if (index < 0 || index >= _vertexes.size()) {
        throw std::out_of_range("Index out of range");
    }
    return _vertexes[index];
}

template <class T>
int GraphMatrix<T>::getWeight(int i, int j) const {
    if (i < 0 || i >= _vertexes.size() || j < 0 || j >= _vertexes.size()) {
        throw std::out_of_range("Index out of range");
    }
    return _matrix[i][j];
}