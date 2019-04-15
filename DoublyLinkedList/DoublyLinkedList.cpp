// DoublyLinkedList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "List.h"
#include "Iterator.h"
#include <algorithm>

using namespace std;

int main()  // NOLINT(bugprone-exception-escape)
{
	auto list_of_ints = new list<int>();
	auto command = ' ';
	int value;

	while (command != '0')
	{
		cout << "press 1 to add number" << endl;
		cout << "press 2 to remove element" << endl;
		cout << "press 3 to print list" << endl;
		cout << "press 0 to exit" << endl;

		cin >> command;
		cout << endl;
		switch (command)
		{
		case '0':
			break;
		case '1':
			cout << "type an integer: ";
			cin >> value;

			if (list_of_ints->is_empty())
			{
				list_of_ints->insert_last(value);
			}
			else
			{
				auto* iter = list_of_ints->get_iterator_at_tail();
				node<int>* search;

				while ((search = iter->previous_node()) != nullptr)
				{
					auto s = search->element;
					if (s > value)
					{
						break;
					}
				}

				if (search == nullptr)
				{
					list_of_ints->insert_first(value);
				}
				else
				{
					list_of_ints->insert_after(search, value);
				}
				delete iter;
			}
			break;
		case '2':
		{
			cout << "type element: ";
			cin >> value;

			auto* iter = list_of_ints->get_iterator_at_head();
			node<int>* search;

			while ((search = iter->next_node()) != nullptr)
			{
				if (search->element == value)
				{
					break;
				}
			}

			if (search == nullptr)
			{
				cout << "fail value" << endl;
			}
			else
			{
				if (list_of_ints->remove(search))
				{
					cout << "gj wp" << endl;
				}
				else
				{
					cout << "invalid operation" << endl;
				}
			}
			delete iter;
			break;
		}
		case '3':
			if (list_of_ints->is_empty())
			{
				cout << "the list is empty" << endl;
			}
			else {

				auto* iter = list_of_ints->get_iterator_at_head();
				node<int>* list;

				while ((list = iter->next_node()) != nullptr) {
					cout << list->element << endl;
				}
				delete iter;
			}
			break;
		default:
			cout << "Invalid option" << endl;
			break;
		}
	}

	delete list_of_ints;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.