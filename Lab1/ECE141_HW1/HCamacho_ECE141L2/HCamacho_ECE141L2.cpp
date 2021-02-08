// HCamacho_ECE141L2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "linkedList.h"
#include <queue>

using namespace std;

class table {
public:
private:
protected:
};

void createTable();
void testPQ();

int main()
{
	createTable();
}

void createTable()
{
	linkedList<int> table[3];
	table[0].insertNode(0);
	table[0].insertNode(1);
	table[0].insertNode(2);
	table[1].insertNode(3);
	table[1].insertNode(4);
	table[1].insertNode(5);
	table[2].insertNode(6);
	table[2].insertNode(7);
	table[2].insertNode(8);

	table[0].printList();
	cout << endl;
	table[1].printList();
	cout << endl;
	table[2].printList();
	cout << endl;
	
	linkedList<linkedList<int>> initialTable;
	initialTable.insertNode(table[0]);
	
	

}

void testPQ()
{

}

