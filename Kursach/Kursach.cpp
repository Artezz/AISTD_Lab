// Kursach.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Include.h"

int main()
{
	List *itemList = new List();
	List *backpack = new List();
	itemList->read_from_file();
	backpack->dp(itemList);
	backpack->printList();
	system("pause");

    return 0;
}

