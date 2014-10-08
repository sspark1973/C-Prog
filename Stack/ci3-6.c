/*
3 6 Write a program to sort a stack in ascending order  
You should not make any assumptions about how the stack is implemented  

The following are the only functions that should be used to write this program: 
push | pop | peek | isEmpty    pg 52 

SOLUTION
Sorting can be performed with one more stack   
The idea is to pull an item from the original stack and push it on the other stack

If pushing this item would violate the sort order of the new stack, 
we need to remove enough items from it so that it¡¯s possible to push the new item   
Since the items we removed are on the original stack, we¡¯re back where we started   

The algorithm is O(N^2) and appears below 

*/

#include <stdio.h>
#include <stdlib.h>

struct sNode
{
	int data;
	struct sNode *next;
};


void push(struct sNode** top_ref, int new_data)
{
	struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode));

	if(new_node == NULL) {
		printf("Stack overflow\n");
		getchar();
		exit(0);
	}

	new_node->data = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

int pop(struct sNode** top_ref)
{
	int res;
	struct sNode *top;

	if(*top_ref == NULL) {
		printf("%s : Stack overflow \n", __FUNCTION__);
		getchar();
		exit(0);
	} else {
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}

void display(struct sNode *stack)
{
	int i;

	if(stack == NULL) {
		printf("%s : Stack is empty\n", __FUNCTION__);
		getchar();
		exit(0);
	}	

	do {
		printf("%d ", stack->data);
		stack = stack->next;
	} while(stack);

	printf("\n");
}

int peek(struct sNode *stack)
{
	if(stack == NULL) {
		printf("%s : Stack is Empty\n", __FUNCTION__);
		return 0;
	}

	printf("peek : %d\n", stack->data);
	
	return stack->data;
}

int main()
{
	struct sNode *stack1 = NULL;
	struct sNode *stack2 = NULL;

	push(&stack1, 40);
	push(&stack1, 30);
	push(&stack1, 20);

	display(stack1);

	//peek(stack1);

	while(stack1) {
		int tmp = pop(&stack1);

		while(!stack2 && peek(stack2) > tmp) {
			int tmp2 = pop(&stack2);
			push(&stack1, tmp2);
		}

		push(&stack2, tmp);
	}

	display(stack2);
	
	getchar();
	return 0;
}


