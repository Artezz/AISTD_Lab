#include"stdafx.h"
#include "Include.h"
#include "fstream"

using namespace std;
Item::Item(fstream& list_of_item) {
	next = nullptr;
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

char * Item::getName()
{
	return name;
}

unsigned int Item::getValue()
{
	return value;
}

unsigned int Item::getItemSize()
{
	return itemSize;
}

unsigned int Item::getMax()
{
	return max;
}

double Item::getRelativeValue()
{
	return relative_value;
}

Item * Item::nextItem()
{
	return next;
}

void Item::setNext(Item * newItem)
{
	next = newItem;
}
