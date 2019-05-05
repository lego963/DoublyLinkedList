#pragma once

template<class T>
class node
{
public:
	T data;
	node<T>* next;
	node<T>* prev;

	explicit node(T element)
	{
		data = element;
		next = prev = nullptr;
	}

};
