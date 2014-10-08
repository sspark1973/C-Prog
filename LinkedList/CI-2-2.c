/*
2.2 Implement an algorithm to find the nth to last element of a singly linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node **head, int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));

	new_node->data = data;
	new_node->next = (*head);
	(*head) = new_node;
}

/*
Method 1 (Use length of linked list)
1) Calculate the length of Linked List. Let the length be len.
2) Print the (len – n + 1)th node from the begining of the Linked List.
*/
void printNthFromLast(struct node *head, int n)
{
	struct node *temp = head;
	int len = 0, i;

	while(temp != NULL) {
		temp = temp->next;
		len++;
	}

	printf("List Lenght : %d\n", len);

	if(len < n) 
		return;

	temp = head;

	for(i = 1; i < len - n + 1; i++)
		temp = temp->next;

	printf("Last[%d]th data: %d\n", n, temp->data);
	
}

struct node *printNthFromLast2(struct node *head, int n)
{

	if(head == NULL || n < 1)
		return NULL;

	struct node *p1 = head;
	struct node *p2 = head;

	int i;

	for(i = 0; i < n - 1; ++i) {
		if(p2 == NULL) {
			return NULL;
		}
		p2 = p2->next;
	}

	while(p2->next != NULL) {
		p1 = p1->next;
		p2 = p2->next;
	}

	printf("Last[%d]th data: %d\n", n, p1->data);

	return p1;
	
}


int main()
{
	struct node *head = NULL, *result = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 35);
	push(&head, 28);

	printNthFromLast(head, 4);
	result = printNthFromLast2(head, 4);

	getchar();

	return 0;
}


