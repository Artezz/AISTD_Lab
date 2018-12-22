#include "stdafx.h"
#include "Include.h"

bool compare(List *l1, List *l2) {
	bool flag = 1;
	if (l1->lenght == l2->lenght) {
		Elem *cur1 = l1->head;
		Elem *cur2 = l2->head;
		while (cur1 != nullptr) {
			if (cur1->data != cur2->data && cur1->index != cur2->index)
				flag = 0;
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
	}
	else
		flag = 0;
	return (flag == 1 ? true : false);
}