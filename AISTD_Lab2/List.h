#pragma once
#include "iostream" 
class List
{
public:
	int lenght = 0;
	
	Elem* head;
	Elem* current;
	
	List();

	void addElem(int index);
	Elem* goTo(char* data);
	Elem* goTo(int index);
};

class Elem:List {
public:
	int index;
	char* data;
	Elem* next = nullptr;

	Elem() {
		lenght++;
		data = new char;
		std::cin >> data;
	};
	~Elem(){
		delete data;
		std::cout << "Удален";
	}
};