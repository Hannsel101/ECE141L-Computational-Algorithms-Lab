#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Graph
{
	public:
		Graph(int V);
		Graph(string in);
		int V();
		int E();
		void addEdge(int v, int w);
		vector<int> Adj(int v);
		string toString();
	private:
		int vertices;
		int edges;
		vector<int>* adj;
	protected:
};

