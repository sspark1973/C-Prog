/*
3 1 Describe how you could use a single array to implement three stacks 
*/

/*
SOLUTION
Approach 1: Divide the array in three equal parts and allow the individual stack to grow in that limited space 
(note: “[“ means inclusive, while “(“ means exclusive of the end point)  
» for stack 1, we will use [0, n/3) 
» for stack 2, we will use [n/3, 2n/3) 
» for stack 3, we will use [2n/3, n) 

This solution is based on the assumption that we do not have any extra information about the usage of space by individual stacks 
and that we can’t either modify or use any extra space   
With these constraints, we are left with no other choice but to divide equally 1 
*/
#include <stdio.h>
//#include <iostream>
#include <stdbool.h>

#define SINGLE_STACK_SIZE 300

const int stackSize = 300;
int buffer_size = 900;
//int* buf = new int[stackSize * 3];
int buffer[SINGLE_STACK_SIZE * 3];
// int buffer[stackSize * 3]; - Compile Error

int stackPointer[] = {-1, -1, -1};

int push(int stackNum, int value) 
{
	if(stackPointer[stackNum] == stackSize -1) {
		printf("Stack is Full!!\n");
		return -1;
	}
	int index = stackNum * stackSize + stackPointer[stackNum] + 1;
	stackPointer[stackNum]++;
	buffer[index] = value;

	return stackPointer[stackNum];
}

int pop(int stackNum)
{
	if(stackPointer[stackNum] == -1) {
		printf("Stack is Empty!!!");
		return -1;
	}
	int index = stackNum * stackSize + stackPointer[stackNum];
	stackPointer[stackNum]--;
	int value = buffer[index];
	buffer[index] = 0;
	return value;
}

int peek(int stackNum)
{
	int index = stackNum * stackSize + stackPointer[stackNum];
	return buffer[index];
}

bool isEmpty(int stackNum)
{
	return stackPointer[stackNum] == -1;
}

int main(int argc, char **argv)
{
	int i;

	printf("%d\n", sizeof(stackPointer)/sizeof(stackPointer[0]));
	for(i=0; i < sizeof(stackPointer)/sizeof(stackPointer[0]) ; i++) {
		printf("stack[%d] is Empty [%d]\n", i, isEmpty(i));
	}

	return 0;
}
