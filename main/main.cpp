// Copyright 2024 Marina Usova

#define EASY_EXAMPLE
#ifdef EASY_EXAMPLE

#include <iostream>
#include <iomanip>
#include "../lib_algorithms/algorithms.cpp"
//#include "../lib_polynom/polynom.cpp
#include "../lib_monom/monom.cpp"
#include "../lib_skip_list/skip_list.h"
#include "../lib_bs_tree/bs_tree.h"


int main() {
    setlocale(LC_ALL, "Russian");
    /*int N, M;
     std::cout << "Enter the dimensions of the maze N M:";
     std::cin >> N >> M;

     Matrix<int> walls = generate(N, M);
     finding_path(walls, N, M);
     print(walls, N, M);*/

     /*Monom m;
     std::cout << "Enter a monomial: ";
     std::cin >> m;
     std::cout << "Entered" << m << std::endl;
     return 0;*/

     /*srand(time(nullptr));
     SkipList<int, std::string> list(3);

     list.insert(5, "five");
     list.insert(2, "two");
     list.insert(8, "eight");
     list.print();

     NodeL<int, std::string>* f  =  list.find_nearest(7);
     list.insert(1, "one");
     list.insert(9, "nine");
     list.insert(3, "three");
     list.print();*/

     //list.insert(5, "FIVE");
     //list.print();

     //BSTree<int, int> tree;
     //tree.insert(4, 5);
     //tree.insert(7, 6);
     //tree.insert(8, 2);
     //tree.insert(1, 3);
     //tree.find(4); //поискать че как

     //tree.find(5);
     /*tree.insert(6, 6);
     tree.insert(4, 4);
     tree.insert(1, 1);
     tree.insert(9, 9);
     tree.insert(5, 5);
     tree.insert(7, 7);
     tree.insert(12, 12);
     tree.print_DLCR();*/

     /*TVector<NodeTr<int, std::string>> data;
     data.push_back_elem(NodeTr<int, std::string>(5, "пять"));
     data.push_back_elem(NodeTr<int, std::string>(3, "три"));
     data.push_back_elem(NodeTr<int, std::string>(7, "семь"));
     data.push_back_elem(NodeTr<int, std::string>(1, "один"));
     data.push_back_elem(NodeTr<int, std::string>(9, "девять"));
     data.push_back_elem(NodeTr<int, std::string>(2, "два"));
     data.push_back_elem(NodeTr<int, std::string>(4, "четыре"));
     data.push_back_elem(NodeTr<int, std::string>(6, "шесть"));
     data.push_back_elem(NodeTr<int, std::string>(8, "восемь"));
     data.print_elems();
     std::cout << std::endl;

     TVector<int> keys;
     for (int i = 0; i < data.size(); i++) {
         keys.push_back_elem(data[i].data.first);
     }

     TVector<int> heapSorted = heapSort(keys);
     heapSorted.print_elems();

     std::cout << std::endl;

     TVector<NodeTr<int, std::string>> BSTSorted = BSTSort(data);
     BSTSorted.print_elems();
     */
     /* PrQueue<int> pq2;
      pq2.push(5, 100);
      pq2.push(3, 200);
      pq2.push(3, 250);

      pq2.print();

      int const size_1 = 4;
      int const size_2 = 4;

      std::pair<std::string, int> m1[size_1] = {
          {"table", 1349},
          {"hash", 1985},
          {"list", 4372},
          {"vector", 1000}
      };

      std::pair<std::string, int> m2[size_2] = {
          {"list", 5863},
          {"massive", 4312},
          {"vector", 2580},
          {"queue", 9999}
      };

      HashTable<int> table(size_1 + size_2);
      mergeArrays(m1, size_1, m2, size_2, table);
      table.print();*/
      //setlocale(LC_ALL, "Russian");
      //
      //неор невзв
      
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
      
      Graph<int> g1(edges, false);
      g1.print();
      
      //ориент
      
      Graph<int> g2(edges, true);
      g2.print();
      
      //взвеш
      
      TVector<std::pair<std::pair<Vertex<int>, Vertex<int>>, int>> weighted_edges;
      
      weighted_edges.push_back_elem(std::make_pair(std::make_pair(Vertex<int>(1), Vertex<int>(4)), 5));
      weighted_edges.push_back_elem(std::make_pair(std::make_pair(Vertex<int>(1), Vertex<int>(2)), 3));
      weighted_edges.push_back_elem(std::make_pair(std::make_pair(Vertex<int>(2), Vertex<int>(3)), 2));
      weighted_edges.push_back_elem(std::make_pair(std::make_pair(Vertex<int>(2), Vertex<int>(4)), 4));
      weighted_edges.push_back_elem(std::make_pair(std::make_pair(Vertex<int>(2), Vertex<int>(5)), 6));
      weighted_edges.push_back_elem(std::make_pair(std::make_pair(Vertex<int>(3), Vertex<int>(6)), 1));
      weighted_edges.push_back_elem(std::make_pair(std::make_pair(Vertex<int>(3), Vertex<int>(0)), 7));
      weighted_edges.push_back_elem(std::make_pair(std::make_pair(Vertex<int>(4), Vertex<int>(6)), 8));
      weighted_edges.push_back_elem(std::make_pair(std::make_pair(Vertex<int>(5), Vertex<int>(0)), 3));
      
      Graph<int> g3(weighted_edges, false);
      Edge<int> to_del(1, Vertex<int>(1), Vertex<int>(4));
      std::cout << "\n";
      g3.print();
      g3.delete_edge(to_del);
      std::cout << "\n";
      g3.print();
      Vertex<int> vertex1(2);
      g3.delete_vertex(vertex1);
      std::cout << "\n";
      g3.print();



    /*TVector<std::pair<Vertex<int>, Vertex<int>>> edges;
    edges.push_back_elem({ Vertex<int>(0), Vertex<int>(1) });
    edges.push_back_elem({ Vertex<int>(0), Vertex<int>(2) });
    edges.push_back_elem({ Vertex<int>(1), Vertex<int>(3) });
    edges.push_back_elem({ Vertex<int>(2), Vertex<int>(4) });
    edges.push_back_elem({ Vertex<int>(3), Vertex<int>(4) });

    Graph<int> graph(edges, false);

    Vertex<int> source(0);
    Vertex<int> target(4);

    TVector<Vertex<int>> result = Dijkstra_algorithm(graph, source, target);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i]._value;
        if (i < result.size() - 1) {
            std::cout << " -> ";
        }
    }

    TVector<std::pair<std::pair<Vertex<int>, Vertex<int>>, int>> edges_directed;
    edges_directed.push_back_elem({ {Vertex<int>(0), Vertex<int>(1)}, 10 });
    edges_directed.push_back_elem({ {Vertex<int>(0), Vertex<int>(2)}, 5 });
    edges_directed.push_back_elem({ {Vertex<int>(1), Vertex<int>(3)}, 2 });
    edges_directed.push_back_elem({ {Vertex<int>(2), Vertex<int>(1)}, 3 });
    edges_directed.push_back_elem({ {Vertex<int>(2), Vertex<int>(3)}, 9 });
    edges_directed.push_back_elem({ {Vertex<int>(3), Vertex<int>(4)}, 4 });
    edges_directed.push_back_elem({ {Vertex<int>(1), Vertex<int>(4)}, 7 });

    Graph<int> graph2(edges_directed, true);

    Vertex<int> source2(0);
    Vertex<int> target2(4);

    
    std::cout << std::endl;
    TVector<Vertex<int>> result2 = Dijkstra_algorithm(graph2, source2, target2);
    for (int i = 0; i < result2.size(); i++) {
        std::cout << result2[i]._value;
        if (i < result2.size() - 1) {
            std::cout << " -> ";
        }
    }*/
}

#endif  // EASY_EXAMPLE
