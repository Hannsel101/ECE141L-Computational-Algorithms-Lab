// HCamacho_HW2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "testFunctions.h"

void problem1();
void problem2();
void extraCredit();
void rotateLeft(int (&arr)[4][4], int row, int size);

int main()
{
    //testDoubly();
    //testBTree();
    problem1();
    problem2();
	extraCredit();
}

void problem1()
{
	cout << "HW1 Start...\n\n";
	BinaryTree bTree1;

	cout << "Creating new B tree by inserting 15, 5, 7, 3, 13, 14, 12...\n";
	bTree1.insert(15);
	bTree1.insert(5);
	bTree1.insert(7);
	bTree1.insert(3);
	bTree1.insert(13);
	bTree1.insert(14);
	bTree1.insert(12);

	cout << "Printing Binary Tree InOrder\n";
	bTree1.printInorder();

	cout << endl << endl;
	cout << "Transforming binary tree into circular linked list" << endl;
	CircularLinkedList<int> testList;
	bTree1.createCircular(testList);
	testList.print();
	cout << endl << endl << "HW1 Done...\n---------------------------------------------------\nHW2 Start...\n\n";
}

void problem2()
{
    long long M[5] = { 187,492,501,413,125 };

    long long h = 0;
    for (int i = 0; i < 5; ++i)
    {
        h += M[i] * M[i] * M[i] * M[i];
    }
    long long k = 571;

    long long absVal = h / k;

    h = h - k * absVal;
    cout << "The hash = " << h << endl;
	cout << endl << "Due to the modulo being 571 and the very large set of possible unique inputs\n"
		<< "This algorithm is not collision resistent. \n\nOnce 572 unique values have been hashed\n"
		<< "There will be at least one x and y such that H(x) = H(Y)\n\n";
}

void extraCredit()
{
	// Input message
	string m = "ABCDEFGHIJKLMNOP";

	// Used to subtract from character inputs to allow for A=0, B=1, etc...
	char diff = 'A';

	// Arrange letters into a 4x4 array
	int num[4][4];
	for (int i = 0; i < 16; ++i)
	{
		num[i / 4][i % 4] = m[i] - diff;
	}

	// Phase1: Accumulate the individual columns
	int Acc[4] = { 0,0,0,0 };
	for(int i=0; i<4; ++i)
	{
		for (int k = 0; k < 4; ++k)
		{
			Acc[i] += num[k][i];
		}
		Acc[i] %= 26;
	}

	// Phase2
	// Rotate row 1: once to the left
	rotateLeft(num, 0, 4);
	

	// Rotate row 2: twice to the left
	rotateLeft(num, 1, 4);
	rotateLeft(num, 1, 4);

	// Rotate row 3: three times to the left
	rotateLeft(num, 2, 4);
	rotateLeft(num, 2, 4);
	rotateLeft(num, 2, 4);

	// Reverse the order of row 4
	int temp = num[3][0];
	num[3][0] = num[3][3];
	num[3][3] = temp;
	temp = num[3][1];
	num[3][1] = num[3][2];
	num[3][2] = temp;

	// Perform accumulation a second time then sum the two accumulators
	int Acc2[4] = { 0,0,0,0 };
	for (int i = 0; i < 4; ++i)
	{
		for (int k = 0; k < 4; ++k)
		{
			Acc2[i] += num[k][i];
		}
		Acc2[i] %= 26;
	}

	// Sum the indices of the two accumulators into a final accumumulator
	int result[4] = { 0,0,0,0 };
	for (int i = 0; i < 4; ++i)
		result[i] = (Acc[i] + Acc2[i]) % 26;

	// Convert and print the letters of the hash
	char to_letters[4];
	cout << endl << "Hash Input: " << m << endl;
	cout << "Hash Digest: ";
	for (int i = 0; i < 4; ++i)
	{
		to_letters[i] = result[i] + diff;
		cout << to_letters[i];
	}
	cout << endl << endl;
	cout << "Extra Credit End...\n";
}

void rotateLeft(int(&arr)[4][4], int row, int size)
{
	int temp = arr[row][0];
	for (int i = 0; i < size; ++i)
	{
		if (i == size - 1)
			arr[row][i] = temp;
		else
			arr[row][i] = arr[row][i + 1];
	}
}