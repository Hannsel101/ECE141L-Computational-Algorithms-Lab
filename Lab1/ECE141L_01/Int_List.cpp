#include "Int_List.h"
#include <chrono>
#include <thread>
#include <algorithm>

void Int_List::sum3_brute_force()
{
	// Start timing the algorithm
	auto start = chrono::steady_clock::now();

	// sum3 brute force nested for loops
	int count = 0;
	for (int i = 0; i < size; ++i)
		for (int j = i + 1; j < size; ++j)
			for (int k = j + 1; k < size; ++k)
				if ((list.at(i) + list.at(j) + list.at(k) == 0))
				{
					count++;
				}
					
	// Stop timing the algorithm
	auto end = chrono::steady_clock::now();
	
	// Print out the results
	cout << "There are " << count << " triples. Brute force elapsed time: " << endl;
	cout << chrono::duration<double>(end - start).count() << " s\n";
}

void Int_List::sum3_bin_search()
{
	// Start timing the algorithm
	auto start = chrono::steady_clock::now();

	// Sort the vector
	sort(list.begin(), list.end());
	
	// Perform the sum3 binary search algorithm
	int count = 0;
	for(int i=0; i<size; ++i)
		for (int j = i + 1; j < size; j++)
		{
			if (binarySearch(j+1, size-1, -(list.at(i)+list.at(j))) > j)
				count++;
		}

	// Stop timing the algorithm
	auto end = chrono::steady_clock::now();

	// Print out the results
	cout << "There are " << count << " triples. Binary search elapsed time: " << endl;
	cout << chrono::duration<double>(end - start).count() << " s\n";
}

Int_List::Int_List(string inputFile)
	: Base_List<int>(inputFile)
{

}

Int_List::~Int_List()
{
	destroy();
}

int Int_List::binarySearch(int start, int end_itr, int value)
{
	int mid;
	while (start <= end_itr)
	{
		mid = start + (end_itr - start) / 2;
		if (list.at(mid) == value) return mid;
		else if (value < list.at(mid)) return binarySearch(start, mid - 1, value);
		else if (value > list.at(mid)) return binarySearch(mid + 1, end_itr, value);//start = mid + 1;
		
	}
	return -1;
}
