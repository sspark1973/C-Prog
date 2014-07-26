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

int main()
{
	struct node *head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 35);
	push(&head, 28);

	printNthFromLast(head, 4);
	getchar();

	return 0;
}


