/*
2.4 You have two numbers represented by a linked list, 
where each node contains a single digit. 
The digits are stored in reverse order, such that the 1’s digit is at the head of the list. 
Write a function that adds the two numbers and returns the sum as a linked list.

EXAMPLE
Input: 
	(3 -> 1 -> 5), 	 : 513
	(5 -> 9 -> 2)		 : 295
Output: 8 -> 0 -> 8
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

	// link the old list off the new node
	new_node->next = (*head);

	// Move the head to point to the new node
	(*head) = new_node;
}

void displayList(struct node *head)
{
	struct node *temp = head;

	while(temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

struct node *newNode(int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

struct node *addTwoLists(struct node *first, struct node *second, int carry)
{
	struct node *res = NULL;
	struct node *temp, *prev = NULL;
	int sum;

	while(first != NULL || second != NULL) {
		sum = carry + (first ? first->data:0) + (second ? second->data:0);
		carry = (sum >= 10) ? 1 : 0;
		sum = sum % 10;
		temp = newNode(sum);

		if(res == NULL) {
			res = temp;
			prev = res;
		}
		else
			//res->next = temp;
			prev->next = temp;

		prev = temp;
		//temp = prev; <-- Wrong
		//res = temp;

		if(first) first = first->next;
		if(second) second = second->next;
	}

	if(carry > 0)
		prev->next = newNode(carry);

	return res;
}

/*
We can implement this recursively by adding node by node, just as we would digit by digit.
1. result.data = (node1 + node2 + any earlier carry) % 10
2. if node1 + node2 > 10, then carry a 1 to the next addition.
3. add the tails of the two nodes, passing along the carry.

Solution using Recusrion
Time Complexity :O(n) where n is size of bigger Linked List
*/

struct node *addTwoLists2(struct node *first, struct node *second, int carry)
{
	struct node *res = NULL;
	struct node *more = NULL;
	int sum;

	if(first == NULL && second == NULL && !carry) {
		return NULL;
	}

	res = (struct node *)malloc(sizeof(struct node));
	
	sum = carry + (first ? first->data:0) + (second ? second->data:0);

	res->data = sum % 10;
	more = addTwoLists2( first != NULL ? first->next : NULL,
						second != NULL ? second->next : NULL,
						sum >= 10 ? 1 : 0);

	res->next = more;

	return res;
}

int main(int argc, char **argv)
{
	struct node *head1 = NULL;
	struct node *head2 = NULL;
	struct node *res = NULL, *res2 = NULL, *res3 = NULL;
	int carry = 0;

	push(&head1, 7);
	push(&head1, 5);
	push(&head1, 9);
	//push(&head1, 5);
	//push(&head1, 7);	
	// 7->5->9->4->6
	displayList(head1);
	

	push(&head2, 4);
	push(&head2, 8);
	push(&head2, 9);

	// 8->4
	displayList(head2);

	res = addTwoLists(head1, head2, carry);
	// 5->0->0->5->6
	displayList(res);

	carry = 0;
	res2 = addTwoLists2(head2, head1, carry);
	displayList(res2);

	return 0;
}
