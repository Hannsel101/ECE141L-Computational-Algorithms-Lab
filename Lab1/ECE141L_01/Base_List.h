#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


#pragma once
template <class type>
class Base_List
{
public:
	Base_List(string inputFile);
	~Base_List();

	void read(string inputFile);
	// Destroys list and rebuilds it by reading new entries from a specified input file.

	void write();
	// Prints out the contents of list to the screen

private:


protected:
	int size;// Stores the size of the list
	vector<type> list;// Pointer to the beginning of the list

	void destroy();
	// Destroys the current list by freeing up allocated dynamic memory

};
/*
* **********************************************************
* Function definitions for Base_List class below
* **********************************************************
*/
template <class type>
Base_List<type>::Base_List(string inputFile)
{
	size = 0;
	destroy();
	read(inputFile);
}
//**********************************************************//
template <class type>
Base_List<type>::~Base_List()
{
	destroy();
}
//**********************************************************//
template <class type>
void Base_List<type>::read(string inputFile)
{
	// Deallocate the memory held by the linked list
	destroy();

	// Open inputInts.txt file
	fstream inputStream;
	inputStream.open(inputFile);

	// Repopulate the list based on the input file
	type x;
	while (inputStream >> x)
	{
		size++;
		list.push_back(x);
	}

	// Close the input file
	inputStream.close();
}
//**********************************************************//
template <class type>
void Base_List<type>::write()
{
	for (int i = 0; i < list.size(); ++i)
	{
		cout << list.at(i) << " ";
		if (((i % 15) == 0) && i!=0)
			cout << endl;
		
	}
	cout << endl << "Size is now: " << size << endl;
}
//**********************************************************//
template <class type>
void Base_List<type>::destroy()
{	
	// Only delete the list if the list is populated
	if (size)
	{
		// Deallocate the memory of individual objects in the list
		list.clear();

		// Deallocate the storage space held by the vector
		list.shrink_to_fit();
		size = 0;
	}
}

