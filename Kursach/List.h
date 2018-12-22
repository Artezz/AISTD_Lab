#pragma once
class Item;
class List {
	size_t max_capacity;
	Item *head;
	Item *current;
	void insert(Item* newItem);
	void sort();
	void read_from_file();
public:
	List();
	~List();
	void dp(Item* list);
	void next();

	void printList();

};