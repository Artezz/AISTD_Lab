#include "stdafx.h"
#include "Include.h"

TreeIterator_dft::TreeIterator_dft(Node * start)
{
	try {
		if (start == nullptr)
			throw "The element does not exist";
		flag = 0;
		current = start;
		prev = nullptr;
		nextE = start;
		next();
	}
	catch (char* e) { out_of_range(e); }
}

void TreeIterator_dft::next()
{
	bool flagStop = 0;
	current = nextE;
		if (current->getArm(1) == nullptr && flag == 1) {
			flag = 0;
			while (current != nullptr && (current->getArm(1) == nullptr || prev == current->getArm(1)) ) {
				prev = current;
				current = current->getParent();
			}
			if (current != nullptr && current->getArm(1) != nullptr) {
				current = current->getArm(1);
				flagStop = 1;
			}
		}
		if (current != nullptr && (current->getArm(0) == nullptr && flag == 0)) {
			flag = 1;
			while (current != nullptr &&(current->getArm(1) == nullptr && current->getParent() != nullptr)) {
				current = current->getParent();
			}

		}
		prev = nextE;
		if (current != nullptr && !flagStop)
			current = current->getArm(flag);
		nextE = current;
		current = prev;
		prev = nullptr;
		flagStop = 0;
}

bool TreeIterator_dft::has_next()
{
		return nextE == nullptr?false:true;
}

int TreeIterator_dft::get_index()
{
	return current->getIndex();
}
