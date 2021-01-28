#include "Int_List.h"
#include <chrono>

void Int_List::sum3_brute_force()
{
	int count = 0;
	for (int i = 0; i < size; ++i)
		for (int j = i + 1; j < size; ++j)
			for (int k = j + 1; k < size; ++k)
				if (list.at(i) + list.at(j) + list.at(k) == 0)
					count++;
	cout << "Number of 3-tuple pairs that sum to zero are: " << count << endl;
}

void Int_List::sum3_bin_search()
{

}
