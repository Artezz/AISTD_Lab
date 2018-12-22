#pragma once
class Elem;
class List
{
public:
	int lenght;
	
	Elem *head = nullptr;
	
	List();

	void insert(size_t index);//+
	void push_back(); //+
	void push_front();//+
	void pop_back();//+-
	void pop_front();//+
	int at(size_t index);//+
	void remove(size_t index);//+
	size_t get_size();//+
	void print_to_console();//
	void clear();//+
	void set(size_t index, int data);//+
	bool is_Empty();//+
	Elem* goTo(size_t index);//+
	void reOrg();//+
	void swap(size_t index1, size_t index2);//+

};

