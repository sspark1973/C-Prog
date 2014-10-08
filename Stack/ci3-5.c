/*
Implement Queue using Stacks
A queue can be implemented using two stacks. 
Let queue to be implemented be q and stacks used to implement q be stack1 and stack2. 

q can be implemented in two ways:

Method 1 (By making enQueue operation costly)
This method makes sure that 
newly entered element is always at the top of stack 1, 
so that deQueue operation just pops from stack1. 
To put the element at top of stack1, stack2 is used.

enQueue(q, x)
  1) While stack1 is not empty, 
  push everything from satck1 to stack2.
  2) Push x to stack1 (assuming size of stacks is unlimited).
  3) Push everything back to stack1.

dnQueue(q)
  1) If stack1 is empty then error
  2) Pop an item from stack1 and return it

Method 2 (By making deQueue operation costly)

In this method, in en-queue operation, 
the new element is entered at the top of stack1. 
In de-queue operation, if stack2 is empty then all the elements are moved to stack2 and finally top of stack2 is returned.

enQueue(q,  x)
  1) Push x to stack1 (assuming size of stacks is unlimited).

deQueue(q)
  1) If both stacks are empty then error.
  2) If stack2 is empty
       While stack1 is not empty, push everything from satck1 to stack2.
  3) Pop the element from stack2 and return it.

Method 2 is definitely better than method 1. 
Method 1 moves all the elements twice in enQueue operation, 
while method 2 (in deQueue operation) moves the elements once and moves elements only if stack2 empty.

Implementation of method 2:
*/

#include <stdio.h>
#include <stdlib.h>

struct sNode
{
	int data;
	struct sNode *next;
};

struct queue
{
	struct sNode *stack1;
	struct sNode *stack2;
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

void enQueue(struct queue *q, int x)
{
	push(&q->stack1, x);
}

int pop(struct sNode** top_ref)
{
	int res;
	struct sNode *top;

	if(*top_ref == NULL) {
		printf("Stack overflow \n");
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

int deQueue(struct queue *q)
{
	int x;

	if(q->stack1 == NULL && q->stack2 == NULL) {
		printf("Q is empty\n");
		getchar();
		exit(0);
	}

	if(q->stack2 == NULL) {
		while(q->stack1 != NULL) {
			x = pop(&q->stack1);
			push(&q->stack2, x);
		}
	}

	x = pop(&q->stack2);

	return x;
}

void display(struct queue *q)
{
	int i;
	struct sNode *stack1, *stack2;
	stack1 = q->stack1;
	stack2 = q->stack2;

	if(q->stack1 == NULL && q->stack2 == NULL) {
		printf("Q is empty\n");
		getchar();
		exit(0);
	}	

	do {
		printf("%d ", stack1->data);
		stack1 = stack1->next;
	} while(stack1);

	printf("\n");
}

int main()
{
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->stack1 = NULL;
	q->stack2 = NULL;

	enQueue(q, 1);
	enQueue(q, 5);
	enQueue(q, 10);

	display(q);

	printf("%d ", deQueue(q));
	printf("%d ", deQueue(q));
	printf("%d ", deQueue(q));

	display(q);


	getchar();
	return 0;
}

