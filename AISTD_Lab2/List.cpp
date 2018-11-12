#include "stdafx.h"
#include "List.h"


List::List()
{
	head = new Elem;
	current = head;
}
void List::addElem(int index = 0) {
	if (index < 0)
		current = goTo(index);
	if (current != nullptr) {
	Elem* newElem = new Elem;
	Elem* next = current->next;
	newElem->next = current->next;
	current = goTo(current->index - 1);
	current->next = newElem;
}
else 
	std::cout << "Element not found" << std::endl;
};
Elem * List::goTo(char* data)
{
	Elem * temp = head;
	while (temp->data != data || temp->next != nullptr)
		temp = temp->next;
	return (temp->data == data ? temp: nullptr);
};

Elem* List::goTo(int index) {
	Elem * temp = head;
	while (temp->index != index || temp->next != nullptr)
		temp = temp->next;
	return (temp->index == index ? temp : nullptr);
};
