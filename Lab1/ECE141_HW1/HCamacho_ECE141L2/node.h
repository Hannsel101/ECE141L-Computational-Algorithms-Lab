#pragma once
template<class type>
struct node
{
	type value;
	node<type>* next = nullptr;
};
