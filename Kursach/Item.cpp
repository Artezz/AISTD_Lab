#include"stdafx.h"
#include "Include.h"
#include "fstream"

using namespace std;
Item::Item() {
	next = nullptr;

	name = new char[100];
	name = "\0";
	value = 0;
	itemSize = 0;
	max = 0;
	
}
Item::~Item() {


}
void Item::Item_Read(fstream& list_of_item) {

	try {
		if (list_of_item.eof())
			throw ("End of file");
		list_of_item >> *name;
		list_of_item >> value;
		list_of_item >> itemSize;
		list_of_item >> max;
	}
	catch (char *e) {

	}


}

char * Item::getName()
{
	return name;
}

size_t Item::getValue()
{
	return value;
}

size_t Item::getItemSize()
{
	return itemSize;
}

size_t Item::getMax()
{
	return max;
}

Item * Item::nextItem()
{
	return next;
}

void Item::setNext(Item * newItem)
{
	next = newItem;
}
