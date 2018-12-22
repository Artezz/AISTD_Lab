#pragma once
class Iterator;
class Node;
class TreeIterator_dft :public Iterator {
	bool flag;
	Node *current;
	Node *prev;
	Node *nextE;
public:
	TreeIterator_dft(Node *start);
	void next() override;
	bool has_next() override;
	int get_index() override;


};