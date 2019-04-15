#pragma once
#include "Node.h"

template <class T>
class iterator
{
private:
	node<T>* current_node_;

public:
	iterator(node<T>* node = nullptr) :current_node_(node) {}

	node<T>* next_node()
	{
		if (current_node_ == nullptr) {
			return nullptr;
		}
		current_node_ = current_node_->next;
		return current_node_;
	}

	node<T>* previous_node() 
	{
		if (current_node_ == nullptr) 
		{
			return nullptr;
		}
		current_node_ = current_node_->prev;
		return current_node_;
	}

	~iterator()
	{
		if (current_node_ == nullptr)
		{
			current_node_ = NULL;
		}
		delete current_node_;
	}
};

