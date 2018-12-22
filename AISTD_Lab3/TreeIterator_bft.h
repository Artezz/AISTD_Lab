#pragma once
class Iterator;
class Node;
class TreeIterator_bft:public Iterator {
	Node *current;
	Node **parents;
	Node **children;
	size_t curFloor, count, maxCount, maxFloor, countC;
	void next_floor();
public:
	TreeIterator_bft(Node *start);
	void next() override;
	bool has_next() override;
	int get_index() override;
	void has_nextFloor();

};