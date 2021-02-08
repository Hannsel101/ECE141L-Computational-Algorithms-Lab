#include "testFunctions.h"

void testDoubly()
{
	DoublyLinkedList<int> test;

	test.print();
	cout << "Size: " << test.getSize() << endl;

	test.insertAt(5, 5);
	test.insertAt(5, -1);
	test.insertBack(5);
	test.insertFront(4);

	test.print();
	cout << "Size: " << test.getSize() << endl;

	test.insertFront(20);
	test.insertFront(0);

	test.print();
	cout << "Size: " << test.getSize() << endl;

	test.removeFront();

	test.print();
	cout << "Size: " << test.getSize() << endl;

	test.removeBack();

	test.print();
	cout << "Size: " << test.getSize() << endl;
	
	test.removeAt(2);
	test.removeAt(1);

	test.print();
	cout << "Size: " << test.getSize() << endl;

	test.removeBack();
	test.print();
	cout << "Size: " << test.getSize() << endl;
}