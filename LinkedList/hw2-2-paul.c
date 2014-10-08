/*
** 2-2 Implement an algorithm to find the nth to last element of a singly linked list.
*/
#include <stdio.h>
#define NULL 0
#define Node struct link_list

Node {
	int data;
	Node *next;
};


main()
{

	int input;
	Node head;
	
	//build a linked list here.

	find_nth_to_last(head, 10);
}

void find_nth_to_last(Node* head, int n)
{
	int i;
	Node *temp = head;

	if( temp == NULL )
	{
		printf("Error: linked list is empty\n");		
		return;
	}
		
	if( n > 1)
	{
		for( i = 0; i < n-1 ; i++)
		{
			if( temp == NULL )
			{
				printf("Error: size is smaller than %d", n);		
				return;
			}
			temp=temp->next;
		}
	}

	while( temp != NULL )
	{
		printf("%d: %d\n", n++, temp->data);
		temp=temp->next;
	}
}	
