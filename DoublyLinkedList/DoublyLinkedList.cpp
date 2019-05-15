// DoublyLinkedList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "List.h"
#include "Iterator.h"

using namespace std;

int main()
{
	list<int> listOfInts;
	listOfInts.push_back(616);
	listOfInts.push_front(515);
	listOfInts.push_front(313);
	listOfInts.push_back(777);

	for (auto iter = listOfInts.begin(); iter != listOfInts.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}