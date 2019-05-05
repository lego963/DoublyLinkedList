#pragma once

#include "Node.h"

template<class T>
class iterator
{
public:
	node<T>* current;

	explicit iterator(node<T>*& ptr) : current(ptr) {}

	T& operator*()
	{
		return current->data;
	}

	iterator& operator++()
	{
		current = current->next;
		return *this;
	}

	iterator operator++(int)
	{
		auto temp = *this;
		current = current->next;
		return temp;
	}

	iterator& operator--()
	{
		current = current->prev;
		return *this;
	}

	iterator operator--(int)
	{
		iterator temp = *this;
		current = current->prev;
		return temp;
	}

	bool operator != (const iterator<T>& it)
	{
		return current != it.current;
	}
};
