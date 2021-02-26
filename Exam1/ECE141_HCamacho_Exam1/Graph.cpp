#include "Graph.h"
Graph::Graph(int V)
{
	this->vertices = V;
	this->edges = 0;
	adj = new vector<int>[V];
}
//=========================================================================
Graph::Graph(string in)
{
	fstream inFile(in);

	// Exit program is the file is not opened correctly
	if (!inFile.is_open() || !inFile.good())
	{
		cout << "File Read Error\n";
		exit(EXIT_FAILURE);
	}

	// Read in the number of vertices and edges in the graph
	inFile >> vertices >> edges;

	// Create new adjacency list
	adj = new vector<int>[edges];

	// Add all the edges to the adjacency lists
	for (int i = 0; i < edges; ++i)
	{
		// Add an edge
		int vertex, connection;
		inFile >> vertex >> connection;
		adj[vertex].push_back(connection);
		adj[connection].push_back(vertex);
	}
}
//=========================================================================
int Graph::V()
{
	return vertices;
}
//=========================================================================
int Graph::E()
{
	return edges;
}
//=========================================================================
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
	++edges;
}
//=========================================================================
vector<int> Graph::Adj(int v)
{
	return adj[v];
}
//=========================================================================
string Graph::toString()
{
	return "OK";
}
//=========================================================================