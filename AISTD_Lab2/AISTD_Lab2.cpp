// AISTD_Lab2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Include.h"

using namespace std;
int main()
{
	List *test = new List;
	test->push_back();
	test->pop_back();
	test->print_to_console();
	/*test->pop_back();
	test->print_to_console();
	test->push_back();
	test->print_to_console();
	test->insert(1);
	test->print_to_console();
	test->pop_front();
	test->print_to_console();*/
	system("pause");
    return 0;
}

