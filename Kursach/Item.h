#pragma once
class List;
class Item {

	char* name;
	size_t value, itemSize, max;
	Item* next;
public:
	void Item_Read(std::fstream& list_of_item);
	Item();
	~Item();
	char* getName();
	size_t getValue();
	size_t getItemSize();
	size_t getMax();
	Item* nextItem();
	void setNext(Item* newItem);

};