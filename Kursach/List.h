#pragma once
class Item;
class List {
	size_t max_capacity, sizeList;
	Item *head;
	void insert(Item* newItem);
	
	Item* getHead();
	size_t getSize();
public:

	List();
	~List();
	void dp(List* list);
	void size();
	void read_from_file();
	void setMaxCapacity(size_t max);
	void printList();
	void sort();
};