#pragma once
#include <iostream>
using namespace std;


template <class Value>
class Node
{
	public:
		Value value = NULL;
		Node<Value>* next[256];

		Node()
		{	
			for (int i = 0; i < 256; i++)
			{
				next[i] = nullptr;
			}
		}		
};


template <class Value>
class TrieST
{
	public:
		TrieST(int R)
		{
			this->R = R;
			root = new Node<Value>;
		}

		void put(string key, Value val) { root = put(root, key, val, 0); }

		bool contains(string key) { return (get(key) != NULL); }

		Value get(string key)
		{
			Node<Value>* x = get(root, key, 0);
			if (x == nullptr) return NULL;
			return x->value;
		}

	private:
		int R;
		Node<Value>* root;

		Node<Value>* put(Node<Value>* x, string key, Value val, int d)
		{
			if (x == nullptr) x = new Node<Value>;
			if (d == key.length()) { x->value = val; return x; }
			char c = key.at(d);
			x->next[c] = put(x->next[c], key, val, d + 1);
			return x;
		}

		Node<Value>* get(Node<Value>* x, string key, int d)
		{
			if (x == nullptr) return nullptr;
			if (d == key.length()) return x;
			char c = key.at(d);
			return get(x->next[c], key, d + 1);
		}
};
