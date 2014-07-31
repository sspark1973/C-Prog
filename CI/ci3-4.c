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

typedef struct {
	int A[MAX_ELEMENTS];
	int top;
	char name;
} STACK;

void initStack(STACK *S);
int pop(STACK *S);
void push(STACK *s, int x);
void hanoi(int n, STACK* from, STACK *to, STACK *use);
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
	if(S->top == MAX_ELEMENTS -1) {
		printf("\n STACK overflow \n");
		return;
	}

	S->top++;
	S->A[S->top] = x;
}

void hanoi(int n, STACK* from, STACK *to, STACK *use)
{
	int x;
	
	if(n==1) {
		x = pop(from);
		push(to, x);
		printStack(S1);printStack(S2);printStack(S3);printf("\n");
		return;
	}

	if(n > 0) {
		hanoi(n-1, from, use, to);
		x = pop(from); push(to, x);
		printStack(S1);printStack(S2);printStack(S3);printf("\n");
		hanoi(n-1, use, to, from);

	}
}

void initStack(STACK *S)
{
	int i;
	S->top = -1;
	for(i=0; i < MAX_ELEMENTS; i++)
		S->A[i] = i + 1;
}

void printStack(STACK S)
{
	int i;

	printf("%c : ", S.name);
	
	for(i = 0; i <= S.top; i++) {
		printf("%d\t", S.A[i]);
	}

	printf("\n");
}

int main(int argc, char **argv)
{
	int n = 3;

	S1.name = 'A';
	S2.name = 'B';
	S3.name = 'C';

	initStack(&S1); printStack(S1);
	initStack(&S1); printStack(S1);
	initStack(&S1); printStack(S1);

	hanoi(n, &S1, &S3, &S2);

	getchar();
	return 0;
}
	
