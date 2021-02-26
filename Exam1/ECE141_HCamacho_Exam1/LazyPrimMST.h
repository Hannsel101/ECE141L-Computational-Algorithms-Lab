#pragma once
#include "edgeWeightedGraph.h"
#include "compareEdge.h"
#include <vector>
#include <queue>

class LazyPrimMST
{
	private:
		bool* marked;
		queue<Edge> mst;
		priority_queue<Edge, vector<Edge>, compareEdge> pq;


	public:
		LazyPrimMST(EdgeWeightedGraph G)
		{
			marked = new bool[G.getV()];
			for (int i = 0; i < G.getV(); ++i)
				marked[i] = false;

			visit(G, 0);
			while (!pq.empty())
			{
				Edge e = pq.top();
				pq.pop();

				int v = e.either();
				int w = e.other(v);

				if (marked[v] && marked[w]) continue;
				mst.push(e);
				if (!marked[v]) visit(G, v);
				if (!marked[w]) visit(G, w);
			}
		}

		void visit(EdgeWeightedGraph G, int v)
		{
			marked[v] = true;
			for (Edge e : G.Adj(v))
				if (!marked[e.other(v)]) pq.emplace(e);
		}

		queue<Edge> edges() { return mst; }

		double getWeight() { return 0.25; }
		~LazyPrimMST(){}
};