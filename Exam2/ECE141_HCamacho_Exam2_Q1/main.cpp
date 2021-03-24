#include <iostream>
#include <cstdlib>
#include <time.h>

#include "TST.h"

using namespace std;

void generateRandomNumbers(TST<int>& newTST, int& counter, int genAmount);
// Generates N Random phone numbers where N=genAmount.
// Counter keeps track of how many numbers have been stored in total into the TST
// newTST is the Ternary Search Trie used to store the phone numbers

int main()
{
	TST<int> newTST;
	int genAmt = 0, counter = 0;
	char run = 'Y';

	while (toupper(run) == 'Y')
	{
		cout << "Enter the amount of Phone Numbers to generate: ";
		cin >> genAmt;

		if (genAmt <= 0)
		{
			cout << endl << "Invalid amount please try again\n\n";
			continue;
		}

		generateRandomNumbers(newTST, counter, genAmt);

		cout << "\n\nContinue? (Y/N) ";
		cin >> run;
		cout << endl << endl;
	}
	return EXIT_SUCCESS;
}
//==========================================================================
//========FUNCTION DEFINITION START=========================================
//==========================================================================
void generateRandomNumbers(TST<int>& newTST, int& counter, int genAmount)
{
	srand(time(NULL));
	int rNum0 = 0;
	int rNum1 = 0;
	int rNum2 = 0;
	
	int i = 0;

	do 
	{
		rNum0 = rand() % 999 + 1000;
		rNum1 = rand() % 999 + 1000;
		rNum2 = rand() % 9999 + 10000;

		string rString0 = to_string(rNum0);

		string newNum;
		newNum = rString0.substr(1, 3);

		rString0 = to_string(rNum1);
		newNum += rString0.substr(1, 3);

		rString0 = to_string(rNum2);
		newNum += rString0.substr(1, 4);

		if (newTST.contains(newNum)) continue;

		newTST.put(newNum, counter);
		cout << newNum << "\t\t" << counter << endl;
		++counter;
		++i;

	} while (i < genAmount);
	
}