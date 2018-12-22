#include "stdafx.h"
#include "Include.h"

class Iterator;
class TreeIterator_bft;
class TreeIterator_dft;
BinaryTree::BinaryTree() {
	root = nullptr;

}
BinaryTree::~BinaryTree()
{

}

TreeIterator_bft *BinaryTree::create_bft_iterator() {
	return new TreeIterator_bft(root);
}
TreeIterator_dft *BinaryTree::create_dft_iterator() {
	return new TreeIterator_dft(root);
}
bool BinaryTree::contains(size_t index)
{
	TreeIterator_dft *search = this->create_dft_iterator();
	while (search->has_next() && index != search->get_index()) {
		search->next();
	}
	return ((index == search->get_index())?true:false);
}

void BinaryTree::insert(size_t index)
{
	try {
		if (root != nullptr) {
			if (contains(index))
				throw "Element already exist";
			Node *temp = root;
			Node *tempPrev = nullptr;
			while (temp != nullptr) {
				if (temp->getIndex() > index) {
					tempPrev = temp;
					temp = temp->getArm(0);
				}
				else {
					tempPrev = temp;
					temp = temp->getArm(1);
				}
			}
			(tempPrev->getIndex() > index) ? tempPrev->setArm(index, 0) : tempPrev->setArm(index, 1);
		}
		else
			root = new Node(index);
	}
	catch (char* e) { already_exist(e); }

}

void BinaryTree::remove(size_t index)
{
	try{
	if (!contains(index))
		throw "Element not exist";
	Node *temp = root;
	Node *tempForDel = nullptr;
	while (temp->getIndex() != index) {
		if (temp->getIndex() > index) {
			temp = temp->getArm(1);
		}
		if (temp->getIndex() < index) {
			temp->getArm(0);
		}
	}
	tempForDel = temp;
	temp = temp->getArm(1);
	temp->setParent(tempForDel->getParent());
	while (temp->getArm(0) != nullptr)
		temp = temp->getArm(0);
	temp->setArm(tempForDel->getArm(0), 0); }
	catch (char* e) { already_exist(e); }
}

void BinaryTree::print()
{
	TreeIterator_dft search(root);
	while (search.has_next()) {
		std::cout << search.get_index() << "   ";
		search.next();
	}
	
}
