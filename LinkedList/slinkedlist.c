#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct IntElement {
	struct IntElement *next;
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

bool deleteElement(IntElement **head, IntElement *deleteMe)
{
	IntElement *elem;

	if(!head || !*head || !deleteMe)
		return false;

	elem = *head;

	if(deleteMe == *head) {
		*head = elem->next;
		free(deleteMe);
		return true;
	}

	while(elem) {
		if(elem->next == deleteMe) {
			elem->next = deleteMe->next;
			free(deleteMe);
			return true;
		}
		elem = elem->next;
	}
	return false;
}

void deleteList(IntElement **head)
{
	IntElement *deleteMe = *head;

	while(deleteMe) {
		IntElement *next = deleteMe->next;
		free(deleteMe);
		deleteMe = next;
	}
	*head = NULL;
}

/* PROBLEM head and tail are global pointers to the first and last element, 
respectively,
of a singly linked list of integers. Implement C functions for the following
prototypes:
	bool delete( Element *elem );
	bool insertAfter( Element *elem, int data );
The argument to delete is the element to be deleted. 
The two arguments to
insertAfter give the element after which the new element is to be inserted and
the data for the new element. 

It should be possible to insert at the beginning of the
list by calling insertAfter with NULL as the element argument. These functions
should return a boolean indicating success.
Your functions must keep the head and tail pointers current.
*/

IntElement *head = NULL;
IntElement *tail = NULL;

bool delete(IntElement *elem)
{
	IntElement *curPos = head;

	if(!elem) return false;

	if(elem == head) {
		head = elem->next;
		free(elem);

		if(!head)
			tail = NULL;
		return true;
	}

	while(curPos) {
		if(curPos->next == elem) {
			curPos->next = elem->next;
			free(elem);

			if(curPos->next == NULL)
				tail = curPos;

			return true;
		}
		curPos = curPos->next;
	}
	return false;
}

bool insertAfter(IntElement *elem, int data)
{
	IntElement *newElem, *curPos = head;

	newElem = (IntElement *)malloc(sizeof(IntElement));
	if(!newElem)
		return false;

	newElem->data = data;

	if(!elem) {
		newElem->next = head;
		head = newElem;

		if(!tail)
			tail = newElem;

		return true;
	}

	while(curPos) {
		if(curPos == elem) {
			newElem->next = curPos->next;
			curPos->next = newElem;

			if(!(newElem->next))
				tail = newElem;

			return true;
		}
		curPos = curPos->next;
	}

	free(newElem);
	return false;
}

/*
PROBLEM Find and fix the bugs in the following C function that is supposed to
remove the head element from a singly linked list:
*/
void removeHead(IntElement **head)
{
	IntElement *temp;

	if(head && *head) {
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}

/*
PROB LEM Given a singly linked list, devise a time- and space-efficient algorithm
to find the mth-to-last element of the list. 
Implement your algorithm, taking care
to handle relevant error conditions. 
Define mth to last such that when m = 0 the
last element of the list is returned.
*/
IntElement *findMToLastElement(IntElement *head, int m)
{
	IntElement *current, *mBehind;
	int i;

	if(!head)
		return NULL;

	current = head;
	for(i = 0; i < m; i++) {
		if(current->next) {
			current = current->next;
		} else {
			return NULL;
		}
	}

	mBehind = head;
	while(current->next) {
		current = current->next;
		mBehind = mBehind->next;
	}

	return mBehind;
}

/* Takes a pointer to the head of a linked list and determines if
* the list ends in a cycle or is NULL terminated
*/
bool determineTermination(IntElement *head)
{
/*
	IntElement *fast, *slow;
	slow = head;
	fast = head->next;

	while(true) {
		if(!fast || !fast->next)
			return false;
		else if(fast == slow || fast->next == slow)
			return true;
		else {
			slow = slow->next;
			fast = fast->next->next;
		}
	}
*/
	IntElement *fast, *slow;
	fast = head;
	slow = head;

	while(slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast) {
			printf("Found Loop Data[%d], [%d]\n", slow->data, fast->data);
			return true;
		}
	}
	return false;
}

int main()
{
	return 0;
}
