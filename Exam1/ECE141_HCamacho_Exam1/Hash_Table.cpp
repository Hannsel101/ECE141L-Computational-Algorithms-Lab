#include "Hash_Table.h"

Hash_Table::Hash_Table(unsigned int size)
{
	Size = size;
	HT = new bool[size];
	for (int i = 0; i < size; ++i)
		HT[i] = false;
}
//===========================================================
Hash_Table::~Hash_Table()
{
	//delete[] HT;
}
//===========================================================
bool Hash_Table::exist(size_t key)
{
	return HT[hash(key)];
}
//===========================================================
void Hash_Table::insert(size_t key)
{
	HT[hash(key)] = true;
}
//===========================================================
unsigned int Hash_Table::hash(size_t key)
{
	return key % Size;
}
//===========================================================
unsigned int Hash_Table::getSize()
{
	return Size;
}
//===========================================================
void Hash_Table::clearTable()
{
	for (int i = 0; i < Size; ++i)
		HT[i] = 0;
}