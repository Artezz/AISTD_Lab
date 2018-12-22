#include "stdafx.h"
#include "Include.h"

Node::Node(size_t index) {
	this->index = index;
	parent = nullptr;
	leftArm = NULL;
	rightArm = NULL;
}

size_t Node::getIndex() {
	return index;
}
Node* Node::getArm(bool turn) {
	/*if ((turn ? rightArm : leftArm) == NULL)
		return nullptr;*/
	return turn ? rightArm : leftArm;
}
Node* Node::getParent() {
	return parent;
}
void Node::setArm(size_t index, bool flag) {
	Node *temp = new Node(0);
	temp->parent = this;
	temp->index = index;
	flag ? this->rightArm = temp : this->leftArm = temp;
}

void Node::setParent(Node * nParent)
{
	parent = nParent;
}

void Node::setArm(Node * nParent, bool flag)
{
	flag ? this->rightArm = nParent : this->leftArm = nParent;
}
