#include"stdafx.h"
#include "Include.h"
#include "fstream"

using namespace std;
Item::Item() {
	next = nullptr;

	name = new char[100];
	value = 0;
	itemSize = 0;
	max = 0;
	used = 0;
	
}
Item::~Item() {


}
void Item::Item_Read(fstream& list_of_item) {

	try {
		if (list_of_item.eof())
			throw ("End of file");
		list_of_item >> name;
		list_of_item >> value;
		list_of_item >> itemSize;
		list_of_item >> max;
	}
	catch (char *e) {

	}


}

void Item::copy(Item* copy) {
	name = copy->getName();
	value = copy->getValue();
	itemSize = copy->getItemSize();
	max = copy->getMax();
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

void Item::setMax(size_t newMax)
{
	max = newMax;
}
size_t Item::getUsed() {
	return used;
}
void Item::setUsed(size_t inc) {
	used = inc;
}