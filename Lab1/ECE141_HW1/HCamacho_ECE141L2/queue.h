#include "linkedList.h"

#pragma once
template <class type>
class queue : public linkedList<type> {
	public:
		queue();
		~queue();

		type front();
		// returns a reference to the first element of the queue
		
		type back();
		// returns a reference to the last element of the queue

		void enqueue(type value);
		// creates and inserts a new element to the end of the queue

		void dequeue();
		// removes the front element of the queue
	private:
	protected:
};
/*
* Function definitions start  here
*/
template <class type>
queue<type>::queue()
	:linkedList<type>()
{
}
//-----------------------------------------------------------
template <class type>
queue<type>::~queue()
{
	linkedList<type>::destroyList();
}
//-----------------------------------------------------------
template <class type>
type queue<type>::front()
{
	if (!linkedList<type>::isEmpty())
		return linkedList<type>::head->value;
}
//-----------------------------------------------------------
template <class type>
type queue<type>::back()
{
	if (!linkedList<type>::isEmpty())
		return linkedList<type>::tail->value;
}
//-----------------------------------------------------------
template <class type>
void queue<type>::enqueue(type value)
{
	linkedList<type>::insertNode(value);
}
//-----------------------------------------------------------
template <class type>
void queue<type>::dequeue()
{

	
	if (!linkedList<type>::isEmpty())
	{
		type item = linkedList<type>::head->value;
		linkedList<type>::deleteNode(value);
	}
		
}
//-----------------------------------------------------------



