#pragma once

template <class T>
class node
{
public:
	node* next;
	node* prev;
	T element;
	node(const T& elem = T(), node* n = nullptr, node* p = nullptr) : next(n), prev(p), element(elem) {}
	~node() {}
};

