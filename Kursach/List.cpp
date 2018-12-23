#include"stdafx.h"
#include "Include.h"
#include <fstream>
using namespace std;
List::List() {

}
List::~List() {

}

void List::dp(List * list)
{
	Item* current = list->getHead();
	size_t n = list->getSize(), count = 0;
	int* dp = new int[max_capacity+1];
	dp[0] = 0;
	for (int w = 1; w <= max_capacity; w++)
	{
		current = list->getHead();
		count = current->getMax();
		dp[w] = dp[w - 1];
		for (size_t i = 0; i < n; i++)
		{
			
			if (current->getItemSize() <= w)
			{
				if (dp[w] < dp[w - current->getItemSize()] + current->getValue())
				{
					dp[w] = dp[w - current->getItemSize()] + current->getValue();
					insert(current);
				}
				
			}
			if (count-- <= 0) {
				current = current->nextItem();
				count = current->getMax();
			}
		}
	}
}

////Item* List::next()
////{
////	return current->nextItem();
////}

Item * List::getHead()
{
	return head;
}

size_t List::getSize()
{
	return sizeList;
}

//void List::sort() {
//	Item* currentPos = head;
//	Item* prevPos = nullptr;
//	Item* prevMaxRevVal = nullptr;
//	Item* prevTemp = nullptr;
//	while (currentPos->nextItem() != nullptr) {
//		Item* temp = currentPos;
//		Item* maxRevVal = currentPos;
//		while (temp->nextItem() != nullptr) {
//			if (temp->getRelativeValue() >= maxRevVal->getRelativeValue()) {
//				maxRevVal = temp;
//				prevMaxRevVal = prevTemp;
//			}
//			prevTemp = temp;
//			temp = temp->nextItem();
//		}
//		if (prevPos != nullptr) {
//			prevMaxRevVal->setNext(maxRevVal->nextItem());
//			maxRevVal->setNext(prevPos->nextItem());
//			prevPos->setNext(maxRevVal);
//
//		}
//
//		prevPos = currentPos;
//		currentPos = currentPos->nextItem();
//	}
//
//}
void List::insert(Item* newItem) {
	newItem->setNext(head);
	head = newItem;
}
void List::read_from_file() {
	fstream list_of_item;
	
	list_of_item.open("Backpack.txt");
	if (list_of_item.is_open()) {
		while (!list_of_item.eof()) {
			Item *temp = new Item();
			temp->Item_Read(list_of_item);
			try {
				if (temp->getItemSize() == 0 || temp->getMax() == 0 || temp->getName() == "" || temp->getValue() == 0)
					throw "Uncorrect item";
				insert(temp);
			}
			catch (char* e) {
				cout << e << endl;
				delete temp;
				list_of_item.clear();
				if (list_of_item.get() != '\n')
					list_of_item.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		list_of_item.close();
	}
}

void List::size()
{
	Item* current = head;
	while (current->nextItem() != nullptr)
	{
		sizeList += current->getMax();
	}
}

void List::printList()
{
	Item* temp = head;
	while (temp->nextItem() != nullptr) {
		cout << temp->getName() << "  " << temp->getItemSize() << "  " << temp->getValue() << "  " << temp->getMax() << endl;
		temp = temp->nextItem();
	}
}
