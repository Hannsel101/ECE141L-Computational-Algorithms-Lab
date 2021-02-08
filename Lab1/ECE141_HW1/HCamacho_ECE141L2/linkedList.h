#include "node.h"
#include <iostream>

using namespace std;

#pragma once
template<class type>
class linkedList
{
	public:
		linkedList();
		~linkedList();

		int getSize();
		// returns the integer value size of the list

		void insertNode(type value);
		// creates and inserts a new node with specified value
		// into the end of the list

		void deleteNode(type value);
		// Searches for and delete the node of specified value
		// from the list

		void printList();
		// prints out the contents of the list to the terminal

		void destroyList();
		// deallocates the memory of the nodes in the list and
		// removes them from the list

	private:
	
	protected:
		int size;
		node<type>* head;
		node<type>* tail;
		bool isEmpty();
		// returns true if the list is empty
};
/*
* Function definitions start  here
*/
template<class type>
linkedList<type>::linkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}
//-----------------------------------------------------------
template<class type>
linkedList<type>::~linkedList()
{
	destroyList();
}
//-----------------------------------------------------------
template<class type>
int linkedList<type>::getSize()
{
	return size;
}
//-----------------------------------------------------------
template<class type>
void linkedList<type>::insertNode(type value)
{
	node<type>* newNode = new node<type>;
	newNode->value = value;
	
	if (head == nullptr)// No node case
	{
		head = newNode;
		tail = newNode;
	}
	else// General case
	{
		tail->next = newNode;
		tail = tail->next;
	}
	++size;
}
//-----------------------------------------------------------
template<class type>
void linkedList<type>::deleteNode(type value)
{
	if (isEmpty())
	{
		cout << "List is empty!\n";
		return;
	}

	// define temporary pointers used to iterate the list
	node<type>* temp = head;
	node<type>* prev = temp;

	if (head->value == value)// Case 1: head is node to remove
	{
		if (head == tail)// Single node case
		{
			head = nullptr;
			tail = nullptr;
		}
		else// General case
		{
			head = head->next;
		}

		// dereference next pointer, deallocate the memory held by the
		// the node, and decrement the size.
		temp->next = nullptr;
		delete temp;
		size--;
	}
	else// Node to remove is not the first node
	{
		// iterate temp away from first node
		temp = temp->next;

		for (int i = 1; i < size; ++i)
		{
			if (temp->value == value)// Node has been found
			{
				if (temp == tail)// If node is the last node
				{
					// Set tail to the new last element in the list
					tail = prev;

					// Ensure no dangling pointers remain before deletion
					prev->next = nullptr;
					temp->next = nullptr;

					delete temp;
				}
				else
				{
					// Remove the node from the linked list
					prev->next = temp->next;

					// Set pointers to null for node to be deleted
					temp->next = nullptr;
					delete temp;
				}
				size--;
				break;
			}

			// iterate pointers
			prev = temp;
			temp = temp->next;
		}
	}
}
//-----------------------------------------------------------
template<class type>
void linkedList<type>::printList()
{
	// Ensure list isnt empty
	if (isEmpty())
	{
		cout << "List is empty!\n";
		return;
	}

	// Create a temporary pointer to iterate through list
	node<type>* temp = head;
	for (int i = 0; i < size; ++i)
	{
		cout << temp->value << " ";
		temp = temp->next;

		// Print a newline every 10 values for cleaner formatting
		if ((i%10 == 0) && (i!=0))
			cout << endl;
	}
}
//-----------------------------------------------------------
template<class type>
bool linkedList<type>::isEmpty()
{
	return (size == 0);
}
//-----------------------------------------------------------
template<class type>
void linkedList<type>::destroyList()
{
	while(head != nullptr)
	{
		node<type>* temp = head;
		head = head->next;
		temp->next = nullptr;
		delete temp;
		size--;
	}
}
