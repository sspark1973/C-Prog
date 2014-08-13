#include <stdio.h>
#include <stdlib.h>

typedef struct IntElement {
	struct ListElement *next;
	int data;
} IntElement;

bool insertInFront(IntElement **head, int data) {
	IntElement *newElem = malloc(sizeof(IntElement));

	if(!newElem) return false;

	newElem->data = data;
	newElem->next = *head;
	*head = newElem;

	return true;
}

int main()
{
	return 0;
}
