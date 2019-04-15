#pragma once
#include "Node.h"
#include "Iterator.h"
#include <iostream>

template <class T>
class list
{
private:
	node<T>* head_;
	node<T>* tail_;
public:
	list()
	{
		head_ = new node<T>();
		tail_ = new node<T>();
	}

	bool is_empty()
	{
		return (head_->next == NULL);
	}

	void insert_first(T & e)
	{
		if (is_empty())
		{
			auto* new_node = new node<T>(e);
			head_->next = new_node;
			tail_->prev = new_node;
		}
		else
		{
			auto* actual_first = head_->next;
			auto* new_node = new node<T>(e, actual_first);
			actual_first->prev = new_node;
			head_->next = new_node;
		}
	}

	void insert_last(T & e)
	{
		if (is_empty())
		{
			auto* new_node = new node<T>(e);
			head_->next = new_node;
			tail_->prev = new_node;
		}
		else
		{
			auto* actual_last = tail_->prev;
			auto* new_node = new node<T>(e, NULL, actual_last);
			actual_last->next = new_node;
			tail_->prev = new_node;
		}
	}

	bool insertBefore(node<T> * ref, T & e) {
		if (is_empty())
		{
			return false;
		}
		auto* search_ref = head_->next;
		while (search_ref != nullptr)
		{
			if (search_ref == ref)
			{
				break;
			}
			search_ref = search_ref->next;
		}
		if (search_ref == nullptr)
		{
			return false;
		}
		else
		{
			auto* before_ref = search_ref->prev;
			auto* new_node = new node<T>(e, search_ref, before_ref);
			if (before_ref == nullptr)
			{
				head_->next = new_node;
			}
			else
			{
				before_ref->next = new_node;
			}
			search_ref->prev = new_node;
			return true;
		}
	}

	bool insert_after(node<T> * ref, T & e)
	{
		if (is_empty())
		{
			return false;
		}
		auto* search_ref = head_->next;
		while (search_ref != nullptr)
		{
			if (search_ref == ref)
			{
				break;
			}
			search_ref = search_ref->next;
		}
		if (search_ref == nullptr)
		{
			return false;
		}
		else
		{
			auto* after_ref = search_ref->next;
			auto* new_node = new node<T>(e, after_ref, search_ref);
			if (after_ref == nullptr)
			{
				tail_->prev = new_node;
			}
			else
			{
				after_ref->prev = new_node;
			}
			search_ref->next = new_node;
			return true;
		}
	}

	bool remove(node<T> * r)
	{
		if (is_empty())
		{
			return false;;
		}
		auto* remove_node = tail_->prev;
		while (remove_node != nullptr)
		{
			if (remove_node == r)
			{
				break;
			}
			remove_node = remove_node->prev;
		}
		if (remove_node == nullptr)
		{
			return false;
		}
		else
		{
			auto* after_remove = remove_node->next;
			auto* before_remove = remove_node->prev;
			if (after_remove == nullptr)
			{
				tail_->prev = before_remove;
			}
			else
			{
				after_remove->prev = before_remove;
			}
			if (before_remove == nullptr)
			{
				head_->next = after_remove;
			}
			else
			{
				before_remove->next = after_remove;
			}
			delete remove_node;
			return true;
		}
	}

	void clear()
	{
		auto counter = 0;
		while (tail_->prev != NULL)
		{
			auto* remove = tail_->prev;
			tail_->prev = remove->prev;
			delete remove;
			counter++;
		}
	}

	iterator<T>* get_iterator_at_head()
	{
		auto* i = new iterator<T>(head_);
		return i;
	}

	iterator<T>* get_iterator_at_tail()
	{
		auto* i = new iterator<T>(tail_);
		return i;
	}


	~list()
	{
		clear();
		delete head_;
		delete tail_;
	}
};