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
	Item *newItem = new Item();
	Item *maxItem = nullptr;
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
				if (dp[w] < (dp[w - current->getItemSize()] + current->getValue()) && current->getMax() != current->getUsed())
				{
					dp[w] = dp[w - current->getItemSize()] + current->getValue();
					maxItem = current;
					
				}
				
			}
			if (--count <= 0) {
				current = current->nextItem();
				if (current != nullptr) {
					count = current->getMax();
				}
			}
			
			if (maxItem!= nullptr) {
				maxItem->setUsed(maxItem->getUsed()+1);
				newItem->copy(maxItem);
				insert(newItem);
				maxItem = nullptr;
				newItem = new Item();

			}
		}
	}
	std::cout << dp[max_capacity];
	if (newItem->getValue() == 0)
		delete newItem;
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

void List::sort() {
	Item* currentPos = head;
	Item* prevPos = nullptr;
	Item* prevMaxVal = nullptr;
	Item* prevTemp = nullptr;
	while (currentPos->nextItem() != nullptr) {
		Item* temp = currentPos;
		
		Item* maxVal = currentPos;
		while (temp != nullptr) {
			if (temp->getValue() > maxVal->getValue()) {
				maxVal = temp;
				prevMaxVal = prevTemp;
			}
			prevTemp = temp;
			temp = temp->nextItem();
		}
		if (currentPos != maxVal) {
			prevMaxVal->setNext(maxVal->nextItem());
			if (prevPos != nullptr) {
				maxVal->setNext(prevPos->nextItem());
				prevPos->setNext(maxVal);
				prevPos = currentPos;
				currentPos = currentPos->nextItem();
			}
			else {
				head = maxVal;
				maxVal->setNext(currentPos);
				prevPos = maxVal;
			}
		}
		
	}

}
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

void List::setMaxCapacity(size_t max)
{
	max_capacity = max;
}

void List::size()
{
	Item* current = head;
	while (current != nullptr)
	{
		sizeList += current->getMax();
		current = current->nextItem();
	}
}

void List::printList()
{
	Item* temp = head;
	if (temp != nullptr) {
		cout << "Name   Value   Size" << endl;
		while (temp != nullptr) {
			cout << temp->getName() << "     " << temp->getValue()  << "     " << temp->getItemSize() << endl;
			temp = temp->nextItem();
		}
	}
	else
		cout << "List is empty";
}
