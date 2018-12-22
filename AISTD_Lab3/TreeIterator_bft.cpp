#include "stdafx.h"
#include "Include.h"
#include "Math.h"

TreeIterator_bft::TreeIterator_bft(Node * start)
{
	current = start;
	curFloor = 1;
	countC = 0;
	maxCount = pow(2, curFloor);
	children = nullptr;
	parents = new Node*[maxCount];
	parents[1] = current;
	count = 0;
	maxFloor = 0;

}

void TreeIterator_bft::next()
{
	if (!has_next())
		throw out_of_range("The element does not exist");
	if (count == maxCount-1 || parents[count] == nullptr)
		next_floor();
	else
		count++;

}

bool TreeIterator_bft::has_next()
{
	if(count == maxCount-1)
		if(children[0] == nullptr)
			return false;
}

int TreeIterator_bft::get_index()
{
	return parents[count]->getIndex();
}

void TreeIterator_bft::next_floor() {
	maxCount = countC;
	curFloor++;
	parents = children;
	has_nextFloor();
	count = 0;
}
void TreeIterator_bft::has_nextFloor() {
	size_t countP = 0;
	size_t countC = 0;
	children = new Node*[pow(2, curFloor + 1)];
	while (parents[countP] != nullptr && countP != maxCount) {
		for (size_t k = 0; k < 2; k++) {
			children[countC] = parents[countP]->getArm(k);
			if (parents[countP]->getArm(k) != nullptr)
				countC++;
		}
		countP++;
	}
}