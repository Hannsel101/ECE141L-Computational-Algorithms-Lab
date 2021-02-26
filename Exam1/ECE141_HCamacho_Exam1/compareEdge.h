#pragma once
#include "Edge.h"

struct compareEdge
{
	bool operator()(Edge& a, Edge& b)
	{
		if (a.getWeight() > b.getWeight())
		{
			return false;
		}
		return true;
	}
};