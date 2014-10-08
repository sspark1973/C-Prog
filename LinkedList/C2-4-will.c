/* 
 *  2.4 You have two numbers repersened by a linked list, where each node contains
 *      single digit.  The digits are stored in reverse order, such that the 1's digit is 
 *      at the head of the lsit. 
 *      Write function that addss the two numbers and return the sum as a linked list
 *
 * Example 
 * Input : (3->1->5) + (5->9->2)
 * Output : 8 -> 0 -> 8
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef struct IntElem {
	struct IntElem *next;
	int value;
}IntElem;

/* Add list */
int AddList(IntElem **head,  int value)
{
	IntElem *node = *head;
	IntElem *new_node;
	
	if(!head ) {
		printf(" wrong head and tail parameters \n");	
		return -1;
	}

	new_node = malloc(sizeof(IntElem));

	if(!new_node) {
		printf("memory allocation failed\n");
		return -1;
	}


	new_node->value = value;
	new_node->next = NULL;

	/* empty list */
	if(node ==  NULL)
		*head = new_node;
	

	while(node) {
		//printf("node[0x%08X:%d]->0x%08X \n", node, node->value,node->next);
		if(node->next == NULL)  {
			node->next = new_node;
			node = NULL;
		} else {
			node = node->next;
		}
	}
		
	return 1;	
}


int sum(IntElem *List1, IntElem *List2, int *p_carry, int *p_result)
{
	int sum = 0;

	
	if(!p_carry)
		return -1;

	if(List1)
		sum += List1->value;

	if(List2)
		sum += List2->value;
	
	sum += *p_carry;

	*p_result = sum % 10;
	*p_carry = sum/10;

	printf("result : %d carry: %d\n", *p_result, *p_carry);

	return 1;
}


int sumList(IntElem *head1, IntElem *head2, IntElem **result)
{
	IntElem *node1 = head1;
	IntElem *node2 = head2;
	int carry = 0;
	int node_sum = 0;
	
	if( !head1 || !head2 || !result) {
		//printf("sumList parameter errror 0x%08x 0x%08x 0x%08x\n",head1,head2,result);
		return -1;
	}
	while(node1 ||node2) {

		if( sum(node1, node2,&carry, &node_sum))	
			AddList(result, node_sum);

		if(node1)
			node1 = node1->next;
		if(node2)
			node2 = node2->next;
	}

	if(carry)
		AddList(result, carry);

	return 1;
}




void PrintList(IntElem *head)
{
	IntElem *node;
	
	if(!head) {
		printf("No element\n");
		return;	
	}

	/* Print 1st element */
	printf("%d ",head->value);

	node = head->next;
	
	while(node) {
		printf(" - > %d",node->value);

		node = node->next;
	}
	printf("\n");

	return;
}



void main(void)
{
	IntElem *list1= NULL;
	IntElem *list2 = NULL;
	IntElem *resultList = NULL;

	
	AddList(&list1,1);
	AddList(&list1,7);
	AddList(&list1,3);
	AddList(&list1,5);

	PrintList(list1);
	
	AddList(&list2,4);
	AddList(&list2,5);
	AddList(&list2,6);
	PrintList(list2);

	sumList(list1, list2, &resultList);

	PrintList(resultList);

	return;
}
 
