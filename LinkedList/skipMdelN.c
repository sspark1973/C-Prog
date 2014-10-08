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

void skipMdelN(node **head, int m, int n) {
	int i, j;
	node *curr = *head;
	node *t;

	while(curr) {
	for (i=1; i < m && curr != NULL; ++i) {
		curr = curr->next;
	}

	if(curr == NULL) {
		return;
	}

	t = curr->next;

	for (j = 1; j <= n && t != NULL; ++j) {
		node *tmp = t;
		t = t->next;
		free(tmp);
	}

	curr->next = t;
	curr = t;
	}
}
	
int main()
{
	node *head = NULL;

	push(&head, 5);
	push(&head, 15);
	push(&head, 25);
	push(&head, 35);
	push(&head, 45);
	push(&head, 55);
	push(&head, 65);
	push(&head, 75);
	push(&head, 85);
	push(&head, 95);

	printList(head);

	skipMdelN(&head, 3, 2);
	printList(head);

	return 0;
}


