#pragma once
#include <iostream>
#include <string>

#define null -99

using namespace std;

template <class Value>
struct Node
{
	Value val = null;
	char c = '\0';
	Node<Value>* left = nullptr;
	Node<Value>* mid = nullptr;
	Node<Value>* right = nullptr;
};

template <class Value>
class TST
{
	public:
		TST()
		{
			root = nullptr;
		}

		void put(string key, Value val)
		{
			root = put(root, key, val, 0);
		}

		bool contains(string key) { return (get(key) != null); }
		
		Value get(string key)
		{
			Node<Value>* x = get(root, key, 0);
			if (x == nullptr) return null;
			return x->val;
		}

	private:
		Node<Value>* root;

		Node<Value>* put(Node<Value>* x, string key, Value val, int d)
		{
			char c = key.at(d);
			if (x == nullptr) { x = new Node<Value>; x->c = c; }
			if (c < x->c) x->left = put(x->left, key, val, d);
			else if (c > x->c) x->right = put(x->right, key, val, d);
			else if (d < key.length() - 1) x->mid = put(x->mid, key, val, d + 1);
			else x->val = val;
			return x;
		}

		Node<Value>* get(Node<Value>* x, string key, int d)
		{
			if (x == nullptr) return nullptr;
			char c = key.at(d);
			if (c < x->c) return get(x->left, key, d);
			else if (c > x->c) return get(x->right, key, d);
			else if (d < key.length() - 1) return get(x->mid, key, d + 1);
			else return x;
		}
};

