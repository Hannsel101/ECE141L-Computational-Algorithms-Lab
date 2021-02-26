#pragma once

#include "Edge.h"
#include <vector>

class EdgeWeightedGraph
{
	private:
		int V;
		int E;
		vector<Edge>* adj;
	public:
		EdgeWeightedGraph(int V)
		{
			this->V = V;
			this->E = 0;
			adj = new vector<Edge>[V];
		}

		EdgeWeightedGraph(string in)
		{
			fstream inFile(in);

			// Exit program is the file is not opened correctly
			if (!inFile.is_open() || !inFile.good())
			{
				cout << "File Read Error\n";
				exit(EXIT_FAILURE);
			}

			// Read in the number of vertices and edges in the graph
			inFile >> V >> E;

			// Create new adjacency list
			adj = new vector<Edge>[E];

			// Add all the edges to the adjacency lists
			for (int i = 0; i < E; ++i)
			{
				// Add an edge
				int vertex, connection;
				float weight;

				inFile >> vertex >> connection >> weight;

				Edge newEdge(vertex, connection, weight);
				//Edge newEdge2(connection, vertex, weight);

				adj[vertex].push_back(newEdge);
				adj[connection].push_back(newEdge);
			}
		}

		int getV() { return V; }
		int getE() { return E; }

		void addEdge(Edge e)
		{
			int v = e.either();
			int w = e.other(v);
			adj[v].push_back(e);
			adj[w].push_back(e);
			++E;
		}

		vector<Edge> Adj(int v){ return adj[v]; }

		vector<Edge> edges()
		{
			vector<Edge> b;
			for (int v = 0; v < V; v++)
				for (Edge e : adj[v])
					if (e.other(v) > v) b.push_back(e);

			return b;
		}

		void printEdges()
		{
			for (int v = 0; v < V; v++)
				for (Edge e : adj[v])
					e.toString();
		}

		~EdgeWeightedGraph() {}
};