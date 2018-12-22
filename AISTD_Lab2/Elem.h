#pragma once

class List;
class Elem {
public:
	size_t index;
	int data;

	Elem(size_t lenght);
	~Elem();

	Elem* next = nullptr;

	



};