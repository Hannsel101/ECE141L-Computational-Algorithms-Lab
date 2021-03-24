#pragma once
#include <iostream>
#include <typeinfo>

using namespace std;

template <class Value>
class nullClass
{
public:
	Value nullVal;

	nullClass()
	{
		string varS = "0";
		char varC;
		int varI = 0;
		float varF = 0.0;
		double varD = 0.0;

		if (typeid(nullVal).name() == typeid(varS).name())
			nullVal = '\0';
		else if (typeid(nullVal).name() == typeid(varC).name())
			nullVal = '\0';
		else if (typeid(nullVal).name() == typeid(varI).name())
			nullVal = (int)NULL;
		else if (typeid(nullVal).name() == typeid(varF).name())
			nullVal = (float)NULL;
		else if (typeid(nullVal).name() == typeid(varD).name())
			nullVal = (double)NULL;
	}
};

template <class Value>
class Node
{
	public:
		nullClass<Value> nObj;
		Value value = nObj.nullVal;
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

		bool contains(string key) { return (get(key) != nObj.nullVal); }

		Value get(string key)
		{
			Node<Value>* x = get(root, key, 0);
			if (x == nullptr) return nObj.nullVal;
			return x->value;
		}

	private:
		int R;
		Node<Value>* root;
		nullClass<Value> nObj;

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
