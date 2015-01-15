/*
http://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list-by-changing-links/
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node *next;
} node;

void push(node **head_ref, int data) {
	node *temp = (node *)malloc(sizeof(node));

	temp->data = data;
	temp->next = (*head_ref);
	(*head_ref) = temp;

	return;
}

void printList(node *head) {
	while(head) {
		printf("%d\t", head->data);
		head = head->next;
	}
	return;
}

void convertEach(node **head) {
	node *xPrev = NULL, *x, *yPrev, *y, *tmp, *curr = (*head);

	while(curr && curr->next) {
		//xPrev = NULL;
		x = curr;
		y = x->next;
		yPrev = x;

		if(xPrev) xPrev->next = y;
		if(yPrev) yPrev->next = x;
	
		tmp = x->next;
		x->next = y->next;
		y->next = tmp;

		if(xPrev == NULL) (*head) = y;
		//if(y->next == NULL) (*head) = x;

		xPrev = x;
		if(curr->next->next) curr = curr->next->next;
	}

	return;
}

/* Function to pairwise swap elements of a linked list */
void swapNodes(node **head)
{
    // If linked list is empty or there is only one node in list
    if (*head == NULL || (*head)->next == NULL)
        return;
 
    // Initialize previous and current pointers
    node *prev = *head;
    node *curr = (*head)->next;
 
    *head = curr;  // Change head before proceeeding
 
    // Traverse the list
    while (1)
    {
        node *next = curr->next;
        curr->next = prev; // Change next of current as previous node
 
        // If next NULL or next is the last node
        if (next == NULL || next->next == NULL)
        {
            prev->next = next;
            break;
        }
 
        // Change next of previous to next next
        prev->next = next->next;
 
        // Update previous and curr
        prev = next;
        curr = prev->next;
    }
}

int main() {
	node *head = NULL;

	push(&head, 10);
	push(&head, 20);
	push(&head, 30);
	push(&head, 40);
	push(&head, 50);
	push(&head, 60);
	push(&head, 70);
	push(&head, 80);
	
	printList(head);
	printf("\n");

	//convertEach(&head); 
	swapNodes(&head); 

	printList(head);
	printf("\n");

	return 0;
}
