#pragma once
#include "Edge.h"
#include <iostream>
#include <vector>
using namespace std;

class EdgeWeightedGraph
{
	public:
		EdgeWeightedGraph(int V)
		{
			this->V = V;
			adj.resize(V+1);
			E = 0;
		}

		void addEdge(Edge* e)
		{
			int v = e->either();
			int w = e->other(v);
			adj[v].push_back(e);
			adj[w].push_back(e);
			++E;
		}

		vector<Edge*> getAdj(int v) { return adj[v]; }

		vector<Edge*> edges()
		{
			vector<Edge*> edgeList;
			for (int i = 0; i < V; ++i)
			{
				for (int k = 0; k < adj[i].size(); ++k)
					edgeList.push_back(adj[i].at(k));
			}
			return edgeList;
		}

		int getEdges() { return E; }
		int getVertices() { return V; }
	private:
		int V;
		int E;
		vector<vector<Edge*>> adj;
	protected:
};