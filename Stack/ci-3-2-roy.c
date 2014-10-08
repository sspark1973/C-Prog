/*
3.2 How would you design a stack which, 
in addition to push and pop, also has a function min which returns the minimum element? 
Push, pop and min should all operate in O(1) time
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_ELEM 100

typedef struct _stack {
	int arr[MAX_ELEM];
	int top;
} stack;

int arr[MAX_ELEM] = {0}; // ¿Ö arr[max]´Â ¿¡·¯°¡ ³ª´Âå°Éå±î?
int arrMin[MAX_ELEM] = {0};


int top = -1;
int topMin = -1;
//int MinNum = 0;

//#define TRUE 1
//#define FALSE 0

bool isEmpty()
{
	if(top == -1)
		return true;

	return false;
}

bool isFull()
{
	if(top == MAX_ELEM -1)
		return true;
	return false;
}

void push(int x)
{
	if(isFull()) {
		printf("Stack is Full\n");
		return;
	}

	if(isEmpty()) {
		top++; topMin++;
		arr[top] = x;
		arrMin[topMin] = x;
	} else {
		top++;
		arr[top] = x;

		int y = peekMin();
		int minNum;

		if(y > x)
			minNum = x;
		else
			minNum = y;
		
		topMin++;
		arrMin[topMin] = minNum;
		//printf("\n Min Number is %d\n", MinNum);
	}

}

int peekMin()
{
	int x;
	
	//if(isEmpty()) {
	//	printf("Stack is Empty\n");
	//	return;
	//}

	x = arrMin[topMin];
	return x;
	//topMin--;
}

int pop()
{
	int x, y;
	
	if(isEmpty()) {
		printf("Stack is Empty\n");
		return;
	}

	x = arr[top];
	top--;

	y = arrMin[topMin];
	topMin--;

	return x;
}

void displayStack()
{
	int i;
	for(i = 0; i <= top; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n Top is %d\n", top);
	//printf("\n Min Number is %d\n", MinNum);

}

int main()
{
	push(10);

	printf("Min [%d]\n", peekMin()); 
	push(20);
	push(30);
	push(40);

	push(20);
	push(5);
	printf("Min [%d]\n", peekMin());

	push(30);
	push(10);
	printf("Min [%d]\n", peekMin());
	pop();
	pop();
	pop();
	printf("Min [%d]\n", peekMin());

	
	return 0;
}

