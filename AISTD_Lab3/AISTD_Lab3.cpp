// AISTD_Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Include.h"

int main()
{
	BinaryTree *tree = new BinaryTree;
	tree->insert(50);
	tree->insert(40);
	tree->insert(30);
	tree->insert(35);
	tree->insert(60);
	tree->insert(55);
	tree->insert(61);
	tree->insert(55);
	tree->print();
	system("pause");
    return 0;
}

