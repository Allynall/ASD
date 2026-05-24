#pragma once

#include <iostream>
#include <iomanip>
#include "../lib_tvector/tvector.h"
#include "../lib_list/list.h"

template <class T>
struct Vertex {
	T _value;

	Vertex() : _value(T()) {}
    Vertex(T value) : _value(value) {}

    bool operator==(const Vertex<T>& other) const {
        return _value == other._value;
    }

    bool operator!=(const Vertex<T>& other) const {
        return _value != other._value;
    }

};

template <class T>
struct Edge {
	int _weight;
	Vertex<T> _source;  
	Vertex<T> _target; 

	Edge() : _weight(0), _source(Vertex<T>()), _target(Vertex<T>()) {}
	Edge(int weight, Vertex<T> source, Vertex<T> target)
		: _weight(weight), _source(source), _target(target) {
	}


};

template <class T>   
class Graph {
    TVector<List<std::pair<Vertex<T>, int>>> _graph;
	TVector<Vertex<T>> _vertexes;

	bool _is_directed;
public:

    Graph(TVector<std::pair<Vertex<T>, Vertex<T>>> edges, bool is_directed = false);
    Graph(TVector<std::pair<std::pair<Vertex<T>, Vertex<T>>, int>> edges, bool is_directed = false);

    void add_edge(const Vertex<T>& source, const Vertex<T>& target, int weight = 1);
    void delete_edge(const Edge<T>& edge);
    void delete_vertex(const Vertex<T>& vertex);

    void print() const;
    int getVertexCount() const;
    int getVertexIndex(const Vertex<T>& vertex) const;
    Vertex<T> getVertex(int index) const;

    List<std::pair<Vertex<T>, int>> get_neighbors_with_weights(int index) const;

private:
	void addVertexIfNotExists(const Vertex<T>& v);
};


template <class T>
Graph<T>::Graph(TVector<std::pair<Vertex<T>, Vertex<T>>> edges, bool is_directed)
    : _is_directed(is_directed) {
    for (int i = 0; i < edges.size(); i++) {
        add_edge(edges[i].first, edges[i].second, 1);
    }
}

template <class T>
Graph<T>::Graph(TVector<std::pair<std::pair<Vertex<T>, Vertex<T>>, int>> edges, bool is_directed)
    : _is_directed(is_directed) {
    for (int i = 0; i < edges.size(); i++) {
        add_edge(edges[i].first.first, edges[i].first.second, edges[i].second);
    }
}

template <class T>
void Graph<T>::addVertexIfNotExists(const Vertex<T>& vertex) {
    if (getVertexIndex(vertex) == -1) {
        _vertexes.push_back_elem(vertex);
        _graph.push_back_elem(List<std::pair<Vertex<T>, int>>());
    }
}

template <class T>
void Graph<T>::add_edge(const Vertex<T>& source, const Vertex<T>& target, int weight) {
    addVertexIfNotExists(source);
    addVertexIfNotExists(target);

    int source_idx = getVertexIndex(source);
    int target_idx = getVertexIndex(target);

    auto tmp = std::make_pair(target, weight);
    _graph[source_idx].push_back(tmp);

    if (!_is_directed) {
        tmp = std::make_pair(source, weight);
        _graph[target_idx].push_back(tmp);
    }
}

template <class T>
void Graph<T>::delete_edge(const Edge<T>& edge) {
    int source_idx = getVertexIndex(edge._source);
    int target_idx = getVertexIndex(edge._target);

    if (source_idx == -1 || target_idx == -1) {
        throw std::runtime_error("Vertex not found");
    }

    List<std::pair<Vertex<T>, int>>& source_list = _graph[source_idx];
    List<std::pair<Vertex<T>, int>> new_source_list;
    int pos = 0;
    for (auto it = source_list.begin(); it != source_list.end(); it++) {
        if ((*it).first != edge._target) {
            new_source_list.push_back(*it);
        }
    }
    _graph[source_idx] = new_source_list;
    if (!_is_directed) {
        List<std::pair<Vertex<T>, int>>& target_list = _graph[target_idx];
        List<std::pair<Vertex<T>, int>> new_target_list;
        pos = 0;
        for (auto it = target_list.begin(); it != target_list.end(); it++) {
            if ((*it).first != edge._source) {
                new_target_list.push_back(*it);
                break;
            }
        }
        _graph[target_idx] = new_target_list;
    }
}

template <class T>
void Graph<T>::delete_vertex(const Vertex<T>& vertex) {
    int vertex_idx = getVertexIndex(vertex);
    if (vertex_idx == -1) {
        throw std::runtime_error("Vertex not found");
    }

    for (int i = 0; i < _graph.size(); i++) {
        List<std::pair<Vertex<T>, int>>& neighbors = _graph[i];
        int pos = 0;
        for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
            if ((*it).first == vertex) {
                neighbors.erase(pos);
                break;
            }
            pos++;
        }
    }

    _vertexes.erase_elem(vertex_idx + 1);
    _graph.erase_elem(vertex_idx + 1);
}

template <class T>
void Graph<T>::print() const {
    for (int i = 0; i < _vertexes.size(); i++) {
        std::cout << _vertexes[i]._value << " -> ";

        if (_graph[i].is_empty()) {
            std::cout << "пуст";
        }
        else {
            bool first = true;
            for (auto it = _graph[i].begin(); it != _graph[i].end(); it++) {
                if (!first) {
                    std::cout << ", ";
                }
                std::cout << (*it).first._value << "(" << (*it).second << ")";
                first = false;
            }
        }
        std::cout << std::endl;
    }
}

template <class T>
int Graph<T>::getVertexCount() const {
    return _vertexes.size();
}

template <class T>
int Graph<T>::getVertexIndex(const Vertex<T>& vertex) const {
    for (int i = 0; i < _vertexes.size(); i++) {
        if (_vertexes[i] == vertex) {
            return i;
        }
    }
    return -1;
}

template <class T>
Vertex<T> Graph<T>::getVertex(int index) const {
    if (index < 0 || index >= _vertexes.size()) {
        throw std::out_of_range("Index out of range");
    }
    return _vertexes[index];
}

template <class T>
List<std::pair<Vertex<T>, int>> Graph<T>::get_neighbors_with_weights(int index) const {
    if (index < 0 || index >= _graph.size()) {
        throw std::out_of_range("Index out of range");
    }
    return _graph[index];
}
