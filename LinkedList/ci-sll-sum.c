/*
You are given two numbers in the form of linked list.
Add them without reversing the linked lists. 

linked lists can be of any length. 
Ex:123 1->2->3 
10234 1->0->2->3->4 
ans: 10357 1->0->3->5->7
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node **node, int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));

	new_node->data = data;
	new_node->next = (*node);
	(*node) = new_node;
}

void display(struct node *head)
{
	if(head == NULL)
		return;

	while(head) {
		printf("%d\t", head->data);
		head = head->next;
	}
	printf("\n");
}

int FindLength(struct node *node)
{
	int count = 0;
	while(node) {
		count++;
		node = node->next;
	}

	printf("%s length : %d \n", __FUNCTION__, count);

	return count;
}
		

struct node *Add2(struct node *p1, struct node *p2, int carry, int state)
{
	if(p1 == NULL && p2 == NULL)
		return NULL;

	struct node *ret = NULL;
	push(&ret, 0);

	if(state > 0) {
		ret->data = carry + p2->data;
		carry = ret->data / 10;
		ret->data %= 10;
		ret->next = Add2(p1->next, p2, carry, state-1);
	} else if(state < 0) {
		ret->data = carry + p2->data;
		carry = ret->data / 10;
		ret->data %= 10;
		ret->next = Add2(p1, p2->next, carry, state+1);
	} else {
		ret->data = carry + p1->data + p2->data;
		carry = ret->data / 10;
		ret->data %= 10;
		ret->next = Add2(p1->next, p2->next, carry, 0);
	}

	printf("%s data[%d]\n", __FUNCTION__, ret->data);
	return ret;
		
}

struct node *Add(struct node *head1, struct node *head2)
{
	int state = FindLength(head1) - FindLength(head2);
	struct node *sum = NULL;

	int carry = 0;

	sum = Add2(head1, head2, carry, state);

	return sum;
}

int main()
{
	struct node *head1 = NULL;
	struct node *head2 = NULL;

	struct node *sum = NULL;

	push(&head1, 8);
	push(&head1, 7);
	push(&head1, 9);

	push(&head2, 4);
	push(&head2, 3);
	push(&head2, 2);
	push(&head2, 0);
	push(&head2, 1);

	display(head1);
	display(head2);

	sum = Add(head1, head2) ;

	display(sum);

	return 0;
}
