#pragma once
class List;

class Item {

	char* name;
	unsigned int value, itemSize, max;
	Item* next;
public:
	Item(fstream& list_of_item);
	~Item();
	char* getName();
	unsigned int getValue();
	unsigned int getItemSize();
	unsigned int getMax();
	Item* nextItem();
	void setNext(Item* newItem);

};