#pragma once
#include <iostream>

using namespace std;

class UnionFind
{
	public:
		UnionFind(int V);
		~UnionFind();
		int find(int p);
		void Union(int p, int q);
		bool connected(int p, int q) { return (find(p) == find(q));}
		int componentSize(int p) { return size[find(p)]; }
		int getSize() { return vertices; }
		int components() { return numComponents; }
	private:
		int vertices;
		int edges;
		int* size;
		int* id;
		int numComponents;
	protected:

};

