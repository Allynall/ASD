#include <gtest/gtest.h>
#include "..\lib_graph_matrix\graph_matrix.h"

TEST(GraphMatrixTest, can_create_unweighted_graph) {
    TVector<std::pair<Vertex<int>, Vertex<int>>> edges;
    edges.push_back_elem(std::make_pair(Vertex<int>(1), Vertex<int>(4)));
    edges.push_back_elem(std::make_pair(Vertex<int>(1), Vertex<int>(2)));
    edges.push_back_elem(std::make_pair(Vertex<int>(2), Vertex<int>(3)));
    edges.push_back_elem(std::make_pair(Vertex<int>(2), Vertex<int>(4)));
    edges.push_back_elem(std::make_pair(Vertex<int>(2), Vertex<int>(5)));
    edges.push_back_elem(std::make_pair(Vertex<int>(3), Vertex<int>(6)));
    edges.push_back_elem(std::make_pair(Vertex<int>(3), Vertex<int>(0)));
    edges.push_back_elem(std::make_pair(Vertex<int>(4), Vertex<int>(6)));
    edges.push_back_elem(std::make_pair(Vertex<int>(5), Vertex<int>(0)));

    
    ASSERT_NO_THROW(GraphMatrix<int> g(edges, false));
    
}

TEST(GraphMatrixTest, can_create_directed_graph) {
    TVector<std::pair<Vertex<int>, Vertex<int>>> edges;
    edges.push_back_elem(std::make_pair(Vertex<int>(1), Vertex<int>(4)));
    edges.push_back_elem(std::make_pair(Vertex<int>(1), Vertex<int>(2)));

    ASSERT_NO_THROW(GraphMatrix<int> g(edges, true));
}

TEST(GraphMatrixTest, can_create_weighted_graph) {
    TVector<std::pair<std::pair<Vertex<int>, Vertex<int>>, int>> weighted_edges;
    weighted_edges.push_back_elem(std::make_pair(std::make_pair(Vertex<int>(1), Vertex<int>(4)), 5));
    weighted_edges.push_back_elem(std::make_pair(std::make_pair(Vertex<int>(1), Vertex<int>(2)), 3));
    weighted_edges.push_back_elem(std::make_pair(std::make_pair(Vertex<int>(2), Vertex<int>(3)), 2));

    GraphMatrix<int> s(weighted_edges, false);
    ASSERT_NO_THROW(GraphMatrix<int> g(weighted_edges, false));
    s.print();
}

TEST(GraphMatrixTest, can_add_edge) {
    TVector<std::pair<Vertex<int>, Vertex<int>>> edges;
    GraphMatrix<int> g(edges, false);

    ASSERT_NO_THROW(g.add_edge(Vertex<int>(1), Vertex<int>(4), 5));
    EXPECT_EQ(g.getVertexCount(), 2);
}

TEST(GraphMatrixTest, can_add_edge_without_weight) {
    TVector<std::pair<Vertex<int>, Vertex<int>>> edges;
    GraphMatrix<int> g(edges, false);

    ASSERT_NO_THROW(g.add_edge(Vertex<int>(1), Vertex<int>(4)));
    EXPECT_EQ(g.getVertexCount(), 2);
}

TEST(GraphMatrixTest, add_edge_correct_weight) {
    TVector<std::pair<Vertex<int>, Vertex<int>>> edges;
    GraphMatrix<int> g(edges, false);
    g.add_edge(Vertex<int>(1), Vertex<int>(4), 7);

    EXPECT_EQ(g.getWeight(0, 1), 7);
    EXPECT_EQ(g.getWeight(1, 0), 7);
}


TEST(GraphMatrixTest, can_delete_edge) {
    TVector<std::pair<Vertex<int>, Vertex<int>>> edges;
    GraphMatrix<int> g(edges, false);
    g.add_edge(Vertex<int>(1), Vertex<int>(4), 5);

    Edge<int> to_del(5, Vertex<int>(1), Vertex<int>(4));
    ASSERT_NO_THROW(g.delete_edge(to_del));
    EXPECT_EQ(g.getWeight(0, 1), 0);
}

TEST(GraphMatrixTest, delete_edge_undirected) {
    TVector<std::pair<Vertex<int>, Vertex<int>>> edges;
    GraphMatrix<int> g(edges, false);
    g.add_edge(Vertex<int>(1), Vertex<int>(4), 5);

    Edge<int> to_del(5, Vertex<int>(1), Vertex<int>(4));
    g.delete_edge(to_del);
    EXPECT_EQ(g.getWeight(0, 1), 0);
    EXPECT_EQ(g.getWeight(1, 0), 0);
}

TEST(GraphMatrixTest, delete_edge) {
    TVector<std::pair<Vertex<int>, Vertex<int>>> edges;
    GraphMatrix<int> g(edges, true);
    g.add_edge(Vertex<int>(1), Vertex<int>(4), 5);

    Edge<int> to_del(5, Vertex<int>(1), Vertex<int>(4));
    g.delete_edge(to_del);
    EXPECT_EQ(g.getWeight(0, 1), 0);
    EXPECT_EQ(g.getVertexCount(), 2);
}

TEST(GraphMatrixTest, throw_when_delete_edge_vertex_not_found) {
    TVector<std::pair<Vertex<int>, Vertex<int>>> edges;
    edges.push_back_elem(std::make_pair(Vertex<int>(1), Vertex<int>(4)));
    GraphMatrix<int> g(edges, false);

    Edge<int> to_del(5, Vertex<int>(1), Vertex<int>(99));
    ASSERT_ANY_THROW(g.delete_edge(to_del));
}

TEST(GraphMatrixTest, can_delete_vertex) {
    TVector<std::pair<Vertex<int>, Vertex<int>>> edges;
    edges.push_back_elem(std::make_pair(Vertex<int>(1), Vertex<int>(4)));
    GraphMatrix<int> g(edges, false);

    ASSERT_NO_THROW(g.delete_vertex(Vertex<int>(1)));
    EXPECT_EQ(g.getVertexCount(), 1);
}

TEST(GraphMatrixTest, delete_vertex_removes_all_edges) {
    TVector<std::pair<Vertex<int>, Vertex<int>>> edges;
    GraphMatrix<int> g(edges, false);
    g.add_edge(Vertex<int>(1), Vertex<int>(4), 5);
    g.add_edge(Vertex<int>(1), Vertex<int>(2), 3);
    g.add_edge(Vertex<int>(2), Vertex<int>(4), 7);
    g.print();
    g.delete_vertex(Vertex<int>(4));
    std::cout << std::endl;
    g.print();
    EXPECT_EQ(g.getVertexCount(), 2);
}

TEST(GraphMatrixTest, throw_delete_vertex_not_found) {
    TVector<std::pair<Vertex<int>, Vertex<int>>> edges;
    edges.push_back_elem(std::make_pair(Vertex<int>(1), Vertex<int>(4)));
    GraphMatrix<int> g(edges, false);

    ASSERT_ANY_THROW(g.delete_vertex(Vertex<int>(99)));
}

