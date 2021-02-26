#pragma once
#include <iostream>
using namespace std;

class Edge
{
	private:
		int v;
		int w;
		double weight;

	public:
		Edge(int v, int w, double weight)
		{
			this->v = v;
			this->w = w;
			this->weight = weight;
		}

		double getWeight() { return weight; }

		int either() { return v; }

		int other(int vertex) 
		{ 
			if (vertex == v) return w;
			else if (vertex == w) return v;
			return -99;//Error
		}

		int compareTo(Edge that)
		{
			if (this->getWeight() < that.getWeight()) return -1;
			else if (this->getWeight() > that.getWeight()) return 1;
			else return 0;
		}

		void toString()
		{
			cout << v << "-" << w << " weight: " << getWeight() << "\n";
		}
};