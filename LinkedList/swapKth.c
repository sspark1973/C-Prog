#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node *next;
} node;

void push(node **head, int data) {
	node *newNode = (node *)malloc(sizeof(node));

	newNode->data = data;
	newNode->next = (*head);
	(*head) = newNode;
}

void printList(node *head) {

	node *temp = head;
	while(temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


int countLink(node *head) {
	int count = 0;
	node *temp = head;

	while(temp != NULL) {
		count++;
		temp = temp->next;
	}

	return count;
}

	
/*
Swap Kth node from beginning with Kth node from end in a Linked List
Given a singly linked list, swap kth node from beginning with kth node from end. 
	
Swapping of data is not allowed, only pointers should be changed. 
This requirement may be logical in many situations where the linked list data part is huge 
(For example student details line Name, RollNo, Address, ..etc). 

The pointers are always fixed (4 bytes for most of the compilers).

*/
void swapKth(node **head, int k) {

	node *temp = (*head);
	int n = countLink(temp), i;

	if(n < k) {
		printf("Invalid k!!!\n");
		return;
	}

	if(2*k - 1 == n) {
		printf("start/end kth is same\n");
		return;
	}


	node *xPrev = NULL, *x = NULL;
	node *yPrev = NULL, *y = NULL;

	x = (*head);
	for(i = 1; i < k; i++) {
		xPrev = x;
		x = x->next;
	}
		
	y = (*head);
	for(i = 1; i < n - k + 1; i++) {
		yPrev = y;
		y = y->next;
	}

	//xPrev->next = x->next;
	//free(x);
	if(xPrev) xPrev->next = y;
	if(yPrev) yPrev->next = x;

	node *tmp = x->next;
	x->next = y->next;
	y->next = tmp;

	if(k == 1) (*head) = y;
	if(k == n) (*head) = x;

}

/*
Given a linked list, reverse alternate nodes and append at the end
Given a linked list, reverse alternate nodes and append them to end of list. Extra allowed space is O(1) 
Examples

Input List:  1->2->3->4->5->6
Output List: 1->3->5->6->4->2

Input List:  12->14->16->18->20
Output List: 12->16->20->18->14
We strongly recommend to minimize the browser and try this yourself first.

The idea is to maintain two linked lists, one list of all odd positioned nodes (1, 3, 5 in above example) and other list of all even positioned nodes (6, 4 and 2 in above example). Following are detailed steps.
1) Traverse the given linked list which is considered as odd list. Do following for every visited node.
¡¦¡¦a) If the node is even node, remove it from odd list and add it to the front of even node list. Nodes are added at front to keep the reverse order.
2) Append the even node list at the end of odd node list.		
*/
void rearrange(node *odd) {
	if(odd == NULL || odd->next == NULL || odd->next->next == NULL) return;

	node *even = odd->next;
	odd->next = odd->next->next;

	odd = odd->next;
	even->next = NULL;

	while(odd && odd->next) {
		node *temp = odd->next->next;

		odd->next->next = even;
		even = odd->next;

		odd->next = temp;

		if(temp != NULL)
			odd = temp;
	}
	odd->next = even;
}


int main() {
	int i;
	node *head = NULL;

	for(i = 7; i > 0; --i) {
		push(&head, i);
	}

	printList(head);

#if 0
	for(i=1; i < 9; i++) {
		swapKth(&head, i);
		printList(head);
	}
#endif

	rearrange(head);
	printList(head);
	return 0;
}
		

