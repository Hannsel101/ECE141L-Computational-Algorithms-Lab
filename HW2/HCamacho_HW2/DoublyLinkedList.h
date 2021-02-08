#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

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

		void insertAt(type value, int index);
		// Inserts a node at the specified position. If the position
		// is out of bounds then no node is inserted;

		void removeFront();
		// Removes the node at the front of the list. The next node
		// in the list becomes the new head

		void removeBack();
		// Removes the node at the back of the list. The previous node
		// becomes the new tail
		
		void removeAt(int index);
		// Removes the node at the specified index

		int getSize();
		// Returns the number of elements in the list

		void print();
		// Prints the entire list in order from front to back

	private:
		Node<type>* head;
		Node<type>* tail;
		int size;

	protected:
		bool isEmpty();
		// Helper function that returns true if list of size 0

		void destroyList();
		// Helper function that deallocates all the memory allocated
		// by the nodes in the list

		Node<type>* find(type value);
		// Helper function to search for and return a pointer to the location
		// of an item on the list, if it exists.

		void insert(type value, int index);
		// Helper function to insert a new node at the specified location

		void remove(int index);
		// Helper function to remove a node at the specified location
};
/******************************************************************
* Function Definitions start here**********************************
*******************************************************************/
template<class type>
DoublyLinkedList<type>::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}
//******************************************************************
template<class type>
DoublyLinkedList<type>::~DoublyLinkedList()
{
	destroyList();
}
//******************************************************************
template<class type>
type DoublyLinkedList<type>::at(int index)
{
	// Value out of bounds or list is empty
	if ((index >= size) || (index < 0) || (size == 0))
	{
		return -2000000;
	}
	else
	{
		// Move to location in the list and return the value
		Node<type>* iter = head;
		for (int i = 0; i < index; ++i)
		{
			iter = iter->next;
		}
		return iter->data;
	}
}
//******************************************************************
template<class type>
void DoublyLinkedList<type>::insertFront(type value)
{
	insert(value, 0);
}
//******************************************************************
template<class type>
void DoublyLinkedList<type>::insertBack(type value)
{
	insert(value, size);
}
//******************************************************************
template<class type>
void DoublyLinkedList<type>::insertAt(type value, int index)
{
	insert(value, index);
}
//******************************************************************
template<class type>
void DoublyLinkedList<type>::removeFront()
{
	remove(0);
}
//******************************************************************
template<class type>
void DoublyLinkedList<type>::removeBack()
{
	remove(size - 1);
}
//******************************************************************
template<class type>
void DoublyLinkedList<type>::removeAt(int index)
{
	remove(index);
}
//******************************************************************
template<class type>
int DoublyLinkedList<type>::getSize()
{
	return size;
}
//******************************************************************
template<class type>
void DoublyLinkedList<type>::print()
{
	cout << "List: ";
	if (isEmpty())
	{
		cout << "EMPTY\n";
		return;
	}

	Node<type>* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << "  ";
		temp = temp->next;
	}
	cout << endl;
}
//******************************************************************
template<class type>
bool DoublyLinkedList<type>::isEmpty()
{
	return (size == 0);
}
//******************************************************************
template<class type>
void DoublyLinkedList<type>::destroyList()
{
	// Keep removing the head node until the list is empty
	while (head != nullptr)
	{
		remove(0);
	}
	size = 0;
}
//******************************************************************
template<class type>
Node<type>* DoublyLinkedList<type>::find(type value)
{
	if (isEmpty())// Empty list case
	{
		cout << "Error: Cannot search an empty list";
		return nullptr;
	}
	
}
//******************************************************************
template<class type>
void DoublyLinkedList<type>::insert(type value, int index)
{
	// Check for out of bounds condition
	if (index > size || index < 0)
	{
		cout << "Error: Attempt to insert into invalid location\n";
		return;
	}

	Node<type>* newNode = new Node<type>;
	newNode->data = value;

	if (isEmpty())// Empty list case
	{
		head = newNode;
		tail = newNode;
	}
	else if (index == 0)// Insert front
	{
		// Link node to the front of list and make it new head
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else if (index == size)// Insert back
	{
		// Link node to the back of list and make it new tail
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	else// Insert anywhere in between head and tail
	{
		// Iterate to one before the location
		Node<type>* curr = head;
		for (int i = 0; i < index - 1; ++i)
			curr = curr->next;

		// Attach newNode pointers to next and prev node
		newNode->next = curr->next;
		newNode->prev = curr;

		// Attach pointers from surrounding nodes to newNode
		curr->next = newNode;
		newNode->next->prev = newNode;
	}
	++size;
}
//******************************************************************
template<class type>
void DoublyLinkedList<type>::remove(int index)
{
	if (isEmpty())// Empty list condition
	{
		cout << "Error: Cannot remove from empty list\n";
		return;
	}
	else if (index < 0 || index >= size)// Out of bounds checking
	{
		cout << "Error: Cannot delete from out of bounds index\n";
		return;
	}

	// Temporary pointer to point to node set for deletion
	Node<type>* temp = head;

	if (size == 1)// Single node list case
	{
		// Set temp to head and set head = tail = nullptr
		temp = head;
		tail = nullptr;
		head = tail;
	}
	else if (index == 0)// Remove front
	{
		// set a pointer to head and move head to the next node
		temp = head;
		head = head->next;

		// Remove pointers referencing node to be deleted
		temp->next = nullptr;
		head->prev = nullptr;
	}
	else if (index == size - 1)// Remove back
	{
		// set a pointer to tail and move tail back one node
		temp = tail;
		tail = tail->prev;

		// Remove pointers referencing node to be deleted
		temp->prev = nullptr;
		tail->next = nullptr;
	}
	else// Delete a node in between head and tail
	{
		// Iterate to the node to be deleted
		for (int i = 0; i <= index-1; ++i)
			temp = temp->next;

		// Derefernce the node to be deleted
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		temp->next = nullptr;
		temp->prev = nullptr;
	}
	delete temp;
	--size;
}