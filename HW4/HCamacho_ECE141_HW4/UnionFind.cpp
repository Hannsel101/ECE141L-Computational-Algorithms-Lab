#include "UnionFind.h"

UnionFind::UnionFind(int V)
{
	if (V <= 0)
	{
		cout << "Invalid number of vertices";
		vertices = 0;
	}

	vertices = V;
	size = new int[V];
	id = new int[V];
	numComponents = V;

	// Link each component to itself and set their size to 1
	for (int i = 0; i < V; i++)
	{
		size[i] = 1;
		id[i] = i;
	}
}
//====================================================
UnionFind::~UnionFind()
{

}
//====================================================
int UnionFind::find(int p)
{
	int root = p;

	// Find the root
	while (root != id[root])
		root = id[root];

	// Path Compression
	while (p != root)
	{
		int next = id[p];
		id[p] = root;
		p = next;
	}
	return root;
}
//====================================================
void UnionFind::Union(int p, int q)
{
	int root1 = find(p);
	int root2 = find(q);

	// Check if they are in the same group
	if (root1 == root2) return;

	// Otherwise merge the two sets together by merging the
	// smaller one into the larger one
	if (size[root1] < size[root2])
	{
		size[root2] += size[root1];
		id[root1] = root2;
	}
	else
	{
		size[root1] += size[root2];
		id[root2] = root1;
	}
	
	// The number of sets has decreased by 1
	numComponents--;
}
//====================================================

//====================================================