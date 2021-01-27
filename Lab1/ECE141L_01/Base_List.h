#pragma once
template <class type>
class Base_List
{
public:
	Base_List();
	~Base_List();

	void read();
	// Destroys list and rebuilds it by reading new entries from a specified input file.

	void write();
	// Prints out the contents of list to the screen

private:


protected:
	int size;// Stores the size of the list
	type* list;// Pointer to the beginning of the list

	void destroy();
	// Destroys the current list by freeing up allocated dynamic memory

};

