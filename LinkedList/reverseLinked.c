/*
Write a function to reverse a linked list
Iterative Method
Iterate trough the linked list. In loop, change next to prev, prev to current and current to next.

http://www.geeksforgeeks.org/write-a-function-to-reverse-the-nodes-of-a-linked-list/

Try : 
http://www.careercup.com/question?id=14684669


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node *next;
} node;

int push(node **head, int data)
{
	node *newNode = (node *)malloc(sizeof(node));

	if(newNode == NULL) {
		printf("Malloc Error!!\n");
		return -1;
	}

	newNode->data = data;
	newNode->next = (*head);
	(*head) = newNode;

	return 0;
}

void printList(node *head) {
	node *list = head;

	while(list != NULL) {
		printf("%d\t", list->data);
		list = list->next;
	}
	printf("\n");
}

void reverseList(node **head) {
	node *prev = NULL;
	node *current = *head;
	node *next;

	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

int main()
{
	node *head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 85);

	printList(head);

	reverseList(&head);
	printList(head);

	return 0;
}
