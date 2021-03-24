#pragma once
#include <iostream>
using namespace std;

template<class Type>
class IdxMinPQ
{
	public:
		IdxMinPQ(unsigned int maxN);
		// Constructor that sets the size of the priority queue
		// to size maxN

		~IdxMinPQ();

		void insert(int k, Type obj);
		// Inserts a new obj of generic Type into the heap

		void change(int k, Type obj);
		//

		bool contains(int k);
		// Does k contain an object

		void remove(int k);
		// Delete K and the value to stores

		Type min();
		// Returns the smallest obj

		int minIndex();
		// Returns the index of the obj with the minimal distance

		int delMin();
		// Remove the minimal item and return the now empty index

		bool isEmpty();
		// Returns true if the queue is empty.
		// Returns false otherwise

		unsigned int size();
		// Returns the number of objects stored in the queue

		void decreaseKey(int k, Type key);
		// Decrease the key in the given index to the key that is passed in

	private:
		unsigned int maxN;
		unsigned int n;
		int* PQ;
		int* QP;
		Type* keys;
	protected:
};
//===========================================================================
//===========================================================================
//===========================================================================
template<class Type>
IdxMinPQ<Type>::IdxMinPQ(unsigned int maxN)
{
	this->maxN = maxN;
	n = 0;
	keys = new Type[maxN];
	PQ = new int[maxN];
	QP = new int[maxN];
	for (int i : QP)
		QP[i] = -1;
}
//===========================================================================
template<class Type>
IdxMinPQ<Type>::~IdxMinPQ()
{
	delete[] keys;
	delete[] PQ;
	delete[] QP;
}
//===========================================================================
template<class Type>
void IdxMinPQ<Type>::insert(int k, Type obj)
{
	if (constains(k))
		return;
	qp[k] = n;
	pq[n] = k;
	keys[k] = obj;
	n++;
	swim(n);
}
//===========================================================================
template<class Type>
void IdxMinPQ<Type>::change(int k, Type obj)
{
	if (isEmpty() || k < 0 || k >= maxN)
		return;
	keys[k] = obj;
	swim(qp[k]);
	sink(qp[k]);
}
//===========================================================================
template<class Type>
bool IdxMinPQ<Type>::contains(int k)
{
	if (k < 0 || k >= maxN || qp[i] == -1)
		return false;
	return true;
}
//===========================================================================
template<class Type>
void IdxMinPQ<Type>::remove(int k)
{

}
//===========================================================================
template<class Type>
Type IdxMinPQ<Type>::min()
{
	if(!isEmpty())
		return keys[pq[0]];
	return NULL;
}
//===========================================================================
template<class Type>
int IdxMinPQ<Type>::minIndex()
{
	if (!isEmpty())
		return PQ[0];
	return -99;
}
//===========================================================================
template<class Type>
int IdxMinPQ<Type>::delMin()
{
	if(isEmpty())
		return -99;
	int minimum = pq[0];
	change(0, n--);
	sink(0);

	if (minimum == pq[n + 1]) return -99;

	qp[minimum] = -1;
	keys[minimum] = NULL:
	pq[n + 1] = -1;
	return minimum;
}
//===========================================================================
template<class Type>
bool IdxMinPQ<Type>::isEmpty()
{
	return (n == 0);
}
//===========================================================================
template<class Type>
unsigned int IdxMinPQ<Type>::size()
{
	return n;
}

template<class Type>
void IdxMinPQ<Type>::decreaseKey(int k, Type key)
{

}