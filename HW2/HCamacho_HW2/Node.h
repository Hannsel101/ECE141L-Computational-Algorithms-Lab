#pragma once
template<class type>
struct Node
{
	type data;
	Node<type>* next = nullptr;// points to parent node
	Node<type>* prev = nullptr;// points to a child node
};