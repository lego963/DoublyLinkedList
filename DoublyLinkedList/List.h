#pragma once
#include "Node.h"
#include "Iterator.h"

template<class T>
class list
{
	int length_;
	node<T>* head_;
	node<T>* tail_;

public:
	list()
	{
		length_ = 0;
		head_ = tail_ = nullptr;
	}

	void clear()
	{
		this->~list();
	}

	bool is_empty() const
	{
		return !length_;
	}

	void push_front(const T& value)
	{
		if (head_ == nullptr)
		{
			head_ = new node<T>(value);
			tail_ = head_;
		}
		else
		{
			auto* temp = new node<T>(value);
			temp->next = head_;
			head_->prev = temp;
			head_ = temp;
		}
		length_++;
	}

	void push_back(const T& value)
	{
		if (head_ == nullptr)
		{
			head_ = new node<T>(value);
			tail_ = head_;
		}
		else
		{
			auto* temp = new node<T>(value);
			tail_->next = temp;
			temp->prev = tail_;
			tail_ = temp;
		}
		length_++;
	}

	void pop_front()
	{
		if (!this->is_empty())
		{
			head_ = head_->next;
			head_->prev = nullptr;
			length_--;
		}
	}

	void pop_back()
	{
		if (!this->is_empty())
		{
			tail_ = tail_->prev;
			tail_->next = nullptr;
			length_--;
		}
	}

	iterator<T> begin()
	{
		auto it(head_);
		return it;
	}

	iterator<T> end()
	{
		auto it(tail_->next);
		return it;
	}

	void insert(iterator<T> it, const T& value)
	{
		node<T>* temp = new node<T>(value);

		if (is_empty())
		{
			head_ = tail_ = temp;
			temp->next = temp->prev = nullptr;
		}
		else
		{
			if (it.current == nullptr)
			{
				temp->next = nullptr;

				tail_->next = temp;
				temp->prev = tail_;

				tail_ = temp;
			}
			else
			{
				if (it.current->prev == nullptr)
				{
					temp->prev = nullptr;
					head_ = temp;
				}
				else
				{
					it.current->prev->next = temp;
					temp->prev = it.current->prev;
				}

				temp->next = it.current;
				it.current->prev = temp;
			}
		}

		length_++;
	}

	void erase(iterator<T> it)
	{

		if (it.current != nullptr)
		{
			if (it.current->prev == nullptr && it.current->next == nullptr)
			{
				head_ = tail_ = nullptr;
			}

			if (it.current->prev == nullptr && it.current->next != nullptr)
			{
				it.current->next->prev = nullptr;
				head_ = it.current->next;
			}

			if (it.current->prev != nullptr && it.current->next == nullptr)
			{
				it.current->prev->next = nullptr;
				tail_ = it.current->prev;
			}

			if (it.current->prev != nullptr && it.current->next != nullptr)
			{
				it.current->prev->next = it.current->next;
				it.current->next->prev = it.current->prev;
			}

			length_--;
			delete it.current;
		}
	}

	~list()
	{
		if (!is_empty())
		{
			node<T>* tmp = head_;
			while (true)
			{
				tmp = tmp->next;
				if (tmp != nullptr)
				{
					delete tmp->prev;
					tmp->prev = nullptr;
				}
				else
				{
					delete tail_;
					tail_ = head_ = nullptr;
					break;
				}
			}
			length_ = 0;
		}
	}
};