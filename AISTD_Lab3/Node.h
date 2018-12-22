#pragma once

class BinaryTree;
class Node {

	size_t index;
	Node *parent;
	Node *leftArm;
	Node *rightArm;

public:
	Node(size_t index);
	size_t getIndex();
	Node *getArm(bool turn);
	void setArm(size_t index, bool flag);
	void setParent(Node *nParent);
	void setArm(Node *nParent, bool flag);
	Node *getParent();
};