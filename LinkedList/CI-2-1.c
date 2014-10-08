/*
2.1 Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/

/*
For example if the linked list is 12->11->12->21->41->43->21 then removeDuplicates() 
should convert the list to 12->11->21->41->43.

METHOD 1 (Using two loops)
This is the simple way where two loops are used. 

Outer loop is used to pick the elements one by one and inner loop compares the picked element with rest of the elements.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void push(struct node ** head_ref, int new_data)
{
	struct node *new_node = (struct node*) malloc(sizeof(struct node));

	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct node *node)
{
	while(node != NULL) {
		printf("%d\t", node->data);
		node = node->next;
	}
	printf("\n");
}

/*
METHOD 1 (Using two loops)
This is the simple way where two loops are used. 
Outer loop is used to pick the elements one by one and inner loop compares the picked element with rest of the elements.

Time Complexity: O(n^2)
*/
void removeDuplicate(struct node *start)
{
	struct node *ptr1, *ptr2, *dup;

	ptr1 = start;

	while(ptr1 != NULL && ptr1->next != NULL) {
		ptr2 = ptr1;

		while(ptr2->next != NULL) {
			if(ptr1->data == ptr2->next->data) {
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				free(dup);
			}
			else {
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}

int main()
{
	struct node *start = NULL;

	push(&start, 10);
	push(&start, 11);
	push(&start, 12);
	push(&start, 13);
	push(&start, 14);
	push(&start, 15);
	push(&start, 16);

	printList(start);

	removeDuplicate(start);

	printList(start);

	return 0;
}

