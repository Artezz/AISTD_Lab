#pragma once
class List;
class Item {

	char* name;
	size_t value, itemSize, max, used;
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
	void copy(Item* copy);
	void setNext(Item* newItem);
	void setMax(size_t newMax);
	size_t getUsed();
	void setUsed(size_t inc);

};