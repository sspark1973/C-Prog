/*
2.3 Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
EXAMPLE
Input: the node ‘c’ from the linked list a->b->c->d->e
Result: nothing is returned, but the new linked list looks like a->b->d->e
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node **head, int data)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = data;
	new_node->next = (*head);
	(*head) = new_node;
}

void printList(struct node *head)
{
	struct node *temp = head;

	while(temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

/*
A simple solution is to traverse the linked list until you find the node you want to delete. 
But this solution requires pointer to the head node which contradicts the problem statement.

Fast solution is to copy the data from the next node to the node to be deleted and delete the next node. 
Something like following.

	struct node *temp  = node_ptr->next;
	node_ptr->data  = temp->data;
	node_ptr->next  = temp->next;
	free(temp);

NOTE: This problem can not be solved if the node to be deleted is the last node in the linked list. 
That’s ok—your interviewer wants to see you point that out. 
You could consider marking it as dummy in that case. 
This is an issue you should discuss with your interviewer.

*/
void deleteNode(struct node *node_ptr)
{
	struct node *temp = node_ptr->next;
	node_ptr->data = temp->data;
	node_ptr->next = temp->next;
	free(temp);
}

int main(int argc, char *argv)
{
	struct node *head = NULL;

	push(&head, 1);
	//push(&head, 4);
	//push(&head, 1);
	//push(&head, 12);
	//push(&head, 1);
	//push(&head, 10);
	//push(&head, 18);

	printList(head);
	deleteNode(head);
	printList(head);
	
	return 0;
}



