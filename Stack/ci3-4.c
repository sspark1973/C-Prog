/*
3 4 In the classic problem of the Towers of Hanoi, 
you have 3 rods and N disks of different sizes which can slide onto any tower.   
The puzzle starts with disks sorted in ascending order of size from top to bottom 
(e g , each disk sits on top of an even larger one)  

You have the following constraints: 
(A) Only one disk can be moved at a time 
(B) A disk is slid off the top of one rod onto the next rod 
(C) A disk can only be placed on top of a larger disk 

Write a program to move the disks from the first rod to the last using Stacks 
*/

#include <stdio.h>
#include <stdlib.h>

#define FROM_TO_USE 1
#define MAX_ELEMENTS 10

#define NumOfStack 4

typedef struct {
	int A[MAX_ELEMENTS];
	int top;
	char name;
} STACK;

void initStack(STACK *S, int n);
int pop(STACK *S);
void push(STACK *s, int x);
void hanoi(int n, STACK* from, STACK *by, STACK *to);
void printStack(STACK S);

STACK S1, S2, S3;

int pop(STACK *S)
{
	int element;
	if(S->top == -1) {
		printf("Stack Underflow\n");
		return 0;
	}

	element = S->A[S->top];
	S->top--;

	return element;
}

void push(STACK *S, int x)
{
	if(S->top == NumOfStack - 1) {
		printf("\n STACK overflow \n");
		return;
	}

	S->top++;
	S->A[S->top] = x;
}

void hanoi(int n, STACK* from, STACK *by, STACK *to)
{
	int x;
	
	if(n==1) {
		x = pop(from);
		push(to, x);
		printStack(S1);printStack(S2);printStack(S3);printf("\n");
		return;
	}

	if(n > 1) {
		hanoi(n-1, from, to, by);
		x = pop(from); push(to, x);
		printStack(S1);printStack(S2);printStack(S3);printf("\n");
		hanoi(n-1, by, from, to);
	}
}

void initStack(STACK *S, int n)
{
	int i;
	S->top = -1;
	for(i=0; i < n; i++)
		S->A[i] = 0;
}

void initStackN(STACK *S, int n)
{
	int i, value = n;
	S->top = -1;
	for(i=0; i < n; i++) {
		(S->top)++;
		S->A[i] = value--;
	}
}

void printStack(STACK S)
{
	int i;

	printf("%c : ", S.name);
	
	for(i = 0; i <= S.top; i++) {
		printf("%d ", S.A[i]);
	}

	printf("\n");
}

int main(int argc, char **argv)
{
	int n = NumOfStack;

	S1.name = 'A';
	S2.name = 'B';
	S3.name = 'C';

	initStackN(&S1, n);
	initStack(&S2, n);
	initStack(&S3, n);

	printStack(S1);printStack(S2);printStack(S3);printf("\n");
	hanoi(n, &S1, &S2, &S3);

	getchar();
	return 0;
}
	
