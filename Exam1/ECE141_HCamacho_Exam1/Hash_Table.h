#pragma once

class Hash_Table {
	public:
		Hash_Table(unsigned int size);
		// sets the Size of the hashtable to input var size
		// Creates a new array of booleans based on Size


		~Hash_Table();
		// Deallocates memory held by the array of booleans HT

		bool exist(size_t key);
		// performs a simple hash of the input var key to determine
		// if a collision occurs.
		// Returns TRUE for a collision, FALSE otherwise

		void insert(size_t key);
		// adds a new hash to the hashtable, performing replacement
		// if a collision occurs

		unsigned int getSize();
		// Returns the maximum number of unique hashes that can be stored

		void clearTable();
	private:
		unsigned int Size;
		// The maximum number of hashes that can be stored in the table

		bool* HT;
		// The hashtable of booleans. An index contains a TRUE if a data
		// member already exists in the hash location. Returns FALSE otherwise

	protected:
		unsigned int hash(size_t key);
		// Helper function to perform hashing on an the input var key
		// Returns the location to store the key into the Hash Table HT
};