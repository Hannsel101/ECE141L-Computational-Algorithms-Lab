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

void testBTree()
{
	BinaryTree bTree;

	bTree.insert(5);
	bTree.insert(11);
	bTree.insert(7);
	bTree.insert(6);
	bTree.insert(9);
	bTree.insert(8);
	bTree.insert(10);

	bTree.printInorder();

	cout << endl << "Testing unrollRight" << endl;
	bTree.unrollTree();
	bTree.printInorder();

	cout << endl << "Testing new tree and unroll right" << endl;

	BinaryTree bTree1;

	bTree1.insert(15);
	bTree1.insert(5);
	bTree1.insert(7);
	bTree1.insert(3);
	bTree1.insert(13);
	bTree1.insert(14);
	bTree1.insert(12);

	bTree1.printInorder();

	cout << endl << "Testing unrollRight" << endl;
	bTree1.unrollTree();
	bTree1.printInorder();
	cout << endl;
	cout << "Transforming binary tree into circular linked list" << endl;
	CircularLinkedList<int> testList;
	bTree1.createCircular(testList);
	testList.print();
}