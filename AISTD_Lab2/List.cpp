#include "..\Kursach\List.h"
#include "..\Kursach\List.h"
#include "stdafx.h";
#include "Include.h";

//Добавление
void List::push_back() {
	Elem* current = head;
	
	if (is_Empty())
		head = new Elem(++lenght);
	else {
		while (current->next != nullptr)
			current = current->next;
		current->next = new Elem(++lenght);
	}
};


void List::push_front() {
	Elem *newElem = new Elem(++lenght);
	newElem->next = head;
	head = newElem;
	reOrg();
}

void List::insert(size_t index) {
	Elem* newElem;
	if (index == 1)
		push_front();
	else if (index == get_size())
		push_back();
	else if (index > 1 && index < get_size()) {
		newElem = new Elem(++lenght);
		Elem* current = head;
		current = goTo(index - 1);
			newElem->next = current->next;
			current->next = newElem;
			reOrg();
	}
	else
		std::cout << "Element not found" << std::endl;
};
//
void List::set(size_t index, int newData) {
	if (index > 0 && index <= get_size()) {
		Elem *current = goTo(index);
		current->data = newData;
	}
	else
		std::cout << "Element not found" << std::endl;
}
//Удаление
void List::pop_back() {
	if (!is_Empty()) {
		Elem *forDel;
		if (get_size() != 1) {
			Elem *current = goTo(lenght - 1);
			forDel = current->next;
			current->next = nullptr;
		}
		else {
			forDel = head;
			head = nullptr;
		}
		lenght--;
		delete forDel;
	}
	else
		std::cout << "List is empty" << std::endl;
}
void List::pop_front() {
	if (!is_Empty()) {
		Elem *forDel = head;
		head = head->next;
		delete forDel;
		lenght--;
		reOrg();
	}
	else
		std::cout << "List is empty" << std::endl;
}
void List::remove(size_t index) {
	if (index == 1)
		pop_front();
	else if (index == get_size())
		pop_back();
	else if (index > 1 && index < get_size()) {
		Elem* current = head;
		current = goTo(index - 1);
		Elem *forDel = current->next;
		current->next = forDel->next;
		delete forDel;
		lenght--;
		reOrg();
	}
	else
		std::cout << "Element not found" << std::endl;
}

void List::clear() {
	if (!is_Empty()) {
		size_t k = get_size();
		for (size_t i = 1; i <= k; i++) {
			pop_front();
		}
	}
	else
		std::cout << "List is empty" << std::endl;
}

//Проходит по списку и изменяет значение index на актуальное
void List::reOrg() {
	if (!is_Empty()) {
		Elem *current = head;
		for (size_t i = 1; i <= lenght;i++) {
			current->index = i;
			current = current->next;
		}
	}
	else
		std::cout << "List is empty" << std::endl;
}
//Навигация по списку
Elem* List::goTo(size_t index) {
	Elem * temp = head;
	while (temp->index != index && temp->next != nullptr)
		temp = temp->next;
	return (temp->index == index ? temp : nullptr);
};
//Работа с данными
bool List::is_Empty() {
	return (head == nullptr ? 1 : 0);
}

size_t List::get_size() {
	return lenght;
}
int List::at(size_t index) {
	Elem *current = goTo(index);
	return (current->data);
}
void List::swap(size_t index1, size_t index2) {
	if (!is_Empty()) {
		Elem *elem1 = goTo(index1);
		Elem *elem2 = goTo(index2);
		int temp = elem1->data;
		elem1->data = elem2->data;
		elem2->data = temp;
	}
}
void List::print_to_console() {
	if (!is_Empty()) {
		Elem *current = head;
		for (size_t i = 1; i <= get_size();i++) {
			std::cout << "/ " << current->data << " /";
			current = current->next;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "List is empty" << std::endl;
	}
}
//Конструкторы, деструкторы
List::List()
{
	lenght = 0;
	head = nullptr;
}




Elem::Elem(size_t lenght) {
	index = lenght;
	data = lenght;

};

Elem::~Elem() {
	std::cout <<"Element "<< index << " deleted" << std::endl;
}
