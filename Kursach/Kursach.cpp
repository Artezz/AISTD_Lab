// Kursach.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Include.h"

int main()
{
	size_t capacity = 0;
	std::cin >> capacity;
	if (capacity != 0) {
		List *itemList = new List();
		List *backpack = new List();
		itemList->read_from_file();
		itemList->size();
		itemList->sort();
		backpack->setMaxCapacity(capacity);
		backpack->dp(itemList);
		backpack->printList();
	}
	else
		std::cout << "Capacity is 0";
	system("pause");

    return 0;
}

