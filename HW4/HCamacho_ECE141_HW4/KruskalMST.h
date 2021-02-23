#pragma once
#include "EdgeWeightedGraph.h"
#include "UnionFind.h"
#include "compareEdge.h"
#include <queue>
class KruskalMST
{
	public:
		KruskalMST(EdgeWeightedGraph G)
		{
			priority_queue<Edge, vector<Edge>, compareEdge> pq;
			vector<Edge*> edgeList(G.edges());
			
		
			for (int i = 0; i < edgeList.size()-1; ++i)
			{
				Edge newEdge = *edgeList.at(i);
				pq.push(newEdge);
			}
			
			int iter = edgeList.size()-1;
			Edge popped = pq.top();
			for (int i = 0; i < iter; ++i)
			{
				popped = pq.top();
				cout << popped.getWeight() << endl;
				pq.pop();

			}
			
			UnionFind uf(G.getVertices());
			
			//while (!pq.empty() && mst.size() < G.getVertices() - 1)
			//{
			//	Edge *e = pq.del
			//}
		}

		~KruskalMST() {}
	private:
		queue<Edge*> mst;
};