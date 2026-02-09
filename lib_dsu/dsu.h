#pragma once
#include <iostream>


class DSU {
	int* _parent, * _rank;
	size_t _size;
public:
	DSU(size_t size); //++
	DSU(const DSU& other); //++
	~DSU(); //++

	size_t size(); //++
	int* parent() const; //++
	int* rank() const; //++

	void unionn(int x, int y); //++
	int find(int x);
	int find_rec(int x);
};
