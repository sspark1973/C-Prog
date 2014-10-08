/*
2.5 Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.
EXAMPLE
Input: A -> B -> C -> D -> E -> C [the same C as earlier]
Output: C
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
	printf("%d\t %#x\t\n", new_node->data, new_node);
}

void displayList(struct node *head)
{
	struct node *temp = head;

	while(temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
		//getchar();
	}

	printf("\n");
}

void removeLoop(struct node *loop_node, struct node *head)
{
	struct node *ptr1;
	struct node *ptr2;

	ptr1 = head;

	while(1) {
		ptr2 = loop_node;
		while(ptr2->next != loop_node && ptr2->next != ptr1) {
			ptr2 = ptr2->next;
		}

		if(ptr2->next == ptr1)
			break;
		else
			ptr1 = ptr1->next;
	}
	printf("removeLoop data[%d]\n", ptr2->data);
	ptr2->next = NULL;
}

/*
Floyd’s Cycle-Finding Algorithm:
This is the fastest method. Traverse linked list using two pointers.  
Move one pointer by one and other pointer by two.  
If these pointers meet at some node then there is a loop.  If pointers do not meet then linked list doesn’t have loop.
*/

/*
Method 1 (Check one by one) 
We know that Floyd’s Cycle detection algorithm terminates when fast and slow pointers meet at a common point. 

We also know that this common point is one of the loop nodes (2 or 3 or 4 or 5 in the above diagram). 
We store the address of this in a pointer variable say ptr2. 
Then we start from the head of the Linked List and check for nodes one by one if they are reachable from ptr2. 
When we find a node that is reachable, we know that this node is the starting node of the loop in Linked List and we can get pointer to the previous of this node.
*/
int detectAndRemoveLoop(struct node *list)
{
	struct node *slow_p = list, *fast_p = list;

	while(slow_p && fast_p && fast_p->next)	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;

		if(slow_p == fast_p) {
			printf("Found Loop data[%d],[%d]\n", slow_p->data, fast_p->data);
			removeLoop(slow_p, list);
			return 1;
		}
	}

	return 0;
}

struct node *FindBeginning(struct node *head)
{
	struct node *n1 = head;
	struct node *n2 = head;

	while(n2->next != NULL) {
		n1 = n1->next;
		n2 = n2->next->next;

		if(n1==n2) {
			break;
		}
	}

	if(n2->next == NULL)
		return NULL;

	printf("FindBeginning data[%d]\n", n2->data);

	struct node *loop_node = n2;
	n1 = head;

	while(1) {
		while(n2->next != loop_node && n2 != n1) {
			n2 = n2->next;
		}

		if(n2 == n1)
			break;
		else
			n1 = n1->next;
	}

#if 0
	while(n1 != n2) {
		n1 = n1->next;
		n2 = n2->next;
	}
#endif	

	return n2;
}

	
int main(int argc, char **argv)
{
	struct node *head = NULL;
	struct node *node_ptr = NULL;

	push(&head, 10);
	push(&head, 4);
	push(&head, 15);
	push(&head, 20);	
	push(&head, 50);	


	displayList(head);

	getchar();

	head->next->next->next->next->next = head->next->next;

	node_ptr = FindBeginning(head);

	printf("begin circle data[%d]\n", node_ptr->data);

	//displayList(node_ptr);

	detectAndRemoveLoop(head);

	displayList(head);

	return 0;
}

