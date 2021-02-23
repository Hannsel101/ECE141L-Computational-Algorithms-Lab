#pragma once
class Edge 
{
	public:
		Edge(int v, int w, double weight)
		{
			this->weight = weight;
			this->v = v;
			this->w = w;
		}

		int either() { return v; }
		
		int other(int vertex)
		{
			if (vertex == v)
				return w;
			return v;
		}

		int compareTo(Edge that)
		{
			if (this->weight < that.weight) 
				return -1;
			else if (this->weight > that.weight)
				return 1;
			else
				return 0;
		}

		double getWeight() { return weight; }
	private:
		int v, w;
		double weight;
	protected:
};