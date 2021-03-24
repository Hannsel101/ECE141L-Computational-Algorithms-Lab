#include <iostream>
#include <cstdlib>
#include <sstream>
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

	cout << endl << endl;
}
//===============================================
void partB()
{

}