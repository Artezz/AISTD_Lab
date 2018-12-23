#pragma once
class Item;
class List {
	size_t max_capacity, sizeList;
	Item *head;
	void insert(Item* newItem);
	void size();
	Item* getHead();
	size_t getSize();
public:
	List();
	~List();
	void dp(List* list);
	//Item* next();

	void read_from_file();

	void printList();

};