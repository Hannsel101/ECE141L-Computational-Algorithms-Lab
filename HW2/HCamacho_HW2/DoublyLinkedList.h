#pragma once
#include "Node.h"

template<class type>
class DoublyLinkedList
{
	public:
		DoublyLinkedList();
		// Defualt constructor

		~DoublyLinkedList();
		// Destructor

		type at(int index);
		// Returns the value held at the given index in the list

		void insertFront(type value);
		// Inserts a node at the front of the list. The new node
		// becomes the new head

		void insertBack(type value);
		// Inserts a node at the back of the list. The new node
		// becomes the new tail

		void insertAt(int index);
		// Inserts a node at the specified position. If the position
		// is out of bounds then no node is inserted;

		int getSize();
		// Returns the number of elements in the list

	private:
		Node<type>* head;
		Node<type>* tail;
		int size;

	protected:
		bool isEmpty();
		// Helper function that returns true if list of size 0

		bool destroyList();
		// Helper function that deallocates all the memory allocated
		// by the nodes in the list

		Node<type>* find(type value);
		// Helper function to search for and return a pointer to the location
		// of an item on the list, if it exists.

		void insert(int index);
		// Inserts a new node at the specified location
};
/******************************************************************
* Function Definitions start here**********************************
*******************************************************************/
template<class type>
DoublyLinkedList<type>::DoublyLinkedList()
{

}
//******************************************************************
template<class type>
DoublyLinkedList<type>::~DoublyLinkedList()
{

}
//******************************************************************
template<class type>
type DoublyLinkedList<type>::at(int index)
{

}
//******************************************************************
template<class type>
void DoublyLinkedList<type>::insertFront(type value)
{

}
//******************************************************************
template<class type>
void DoublyLinkedList<type>::insertBack(type value)
{

}
//******************************************************************
template<class type>
void DoublyLinkedList<type>::insertAt(int index)
{

}
//******************************************************************
template<class type>
int DoublyLinkedList<type>::getSize()
{

}
//******************************************************************