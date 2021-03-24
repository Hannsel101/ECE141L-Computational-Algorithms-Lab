#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "R_WayTrie.h"

using namespace std;

void partA();
void partB();

int main()
{
	partA();
	partB();
	return EXIT_SUCCESS;
}
//===============================================
//===============================================
//===============================================
void partA()
{
	TrieST<int> trieObj(256);
	string word;
	int val;

	cout << "Please type in a sentence:\n";
	// It was the best of times, yet it was unpleasant times, there should be a wisdom, if not, it must have been the age of foolishness.

	// Process input from keyboard into R-Way Trie
	while (cin >> word)
	{
		
		// Remove punctuation marks from the end of words
		switch (word.at(word.length() - 1)) {
			case '.': case '!': case '?':
			case ';': case ':': case ',':
				word.pop_back();
				break;
			default:
				break;
		}

		// Insert into trie and update number of occurances
		val = trieObj.get(word);
		if (val == NULL) val = 1;
		else val++;

		trieObj.put(word, val);

		if (cin.peek() == '\n')break;
	}
	cout << endl;

	// Testing Code for exam
	if (trieObj.contains("was"))
		cout << "was repeated " << trieObj.get("was") << " times." << endl;
	else
		cout << "does not contain was" << endl;
	cout << endl;
	if (trieObj.contains("worst"))
		cout << "worst repeated " << trieObj.get("worst") << " times." << endl;
	else
		cout << "does not contain worst" << endl;
	cout << endl;
	if (trieObj.contains("foolish"))
		cout << "foolish repeated " << trieObj.get("foolish") << " times." << endl;
	else
		cout << "does not contain foolish" << endl;
	cout << endl;
	cout << "End of test!\n";

	cout << endl << endl << "=============================================================\n\n";
}
//===============================================
void partB()
{
	TrieST<string> trieObj(256);
	string sentence;
	vector<string> sVect;

	// Open file and check if file was open correctly
	ifstream input;
	input.open("problem2.txt");
	if (!input.good())
	{
		cout << "Error opening file\n";
		return;
	}

	// Process the input file while the end of file has not been reached
	string inputLine;
	string word;
	int currLine = 0;

	cout << "Input:\n";
	while (!input.eof())
	{
		getline(input, inputLine);
		cout << inputLine << endl;
		currLine++;
		stringstream inputS(inputLine);
		while (inputS >> word)
		{
			// Remove punctuation marks from the end of words
			switch (word.at(word.length() - 1)) {
			case '.': case '!': case '?':
			case ';': case ':': case ',':
				word.pop_back();
				break;
			default:
				break;
			}
			
			
			// Check the current version of value
			// Then append the new lines the key is found
			string val = trieObj.get(word);
			if (val.at(0) != '\0')
			{
				char comp = val.at(val.length() - 1);
				string comp0 = to_string(currLine);
				char comp2 = comp0.at(0);
				
				int intVal = comp2 - 48;

				if (comp + 1 == comp2)
				{
					if (val.length() > 1 && val.length() % 2 == 1)
					{
						val.at(val.length() - 1) = comp2;
					}
					else
						val += "-" + to_string(intVal);
				}
				else
				{
					val += "  " + to_string(intVal);
				}
			}
			else
			{
				sVect.push_back(word);
				val = to_string(currLine);
			}
				
			
			trieObj.put(word, val);
		}
	}

	cout << endl << endl << "Output:\n";
	sort(sVect.begin(), sVect.end());
	for (string s : sVect)
	{
		cout << s << "\t\t" << trieObj.get(s) << endl;
	}
}