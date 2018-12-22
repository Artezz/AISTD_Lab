#pragma once
class TreeIterator_bft;
class TreeIterator_dft;
class Node;
class BinaryTree {
private:
	Node *root;
public:
	BinaryTree();
	~BinaryTree();
	TreeIterator_bft* create_bft_iterator();
	TreeIterator_dft* create_dft_iterator();
	bool contains(size_t);
	void insert(size_t);
	void remove(size_t);
	void print();


};
