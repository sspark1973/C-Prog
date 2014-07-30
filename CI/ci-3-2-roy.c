/*
3.2 How would you design a stack which, 
in addition to push and pop, also has a function min which returns the minimum element? 
Push, pop and min should all operate in O(1) time
*/

#include <stdio.h>
#include <stdbool.h>


int max = 100;
int arr[100] = {0}; // ¿Ö arr[max]´Â ¿¡·¯°¡ ³ª´Âå°Éå±î?
int arrMin[100] = {0};


int top = -1;
int topMin = -1;
int MinNum = 0;

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
	if(top == max -1)
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
		//MinNum = x;
	} else {
		top++;
		arr[top] = x;

		int y = popMin();
		
		if(MinNum > x) {
			MinNum = x;
		}
		//printf("\n Min Number is %d\n", MinNum);
	}

}

int getMin()
{
	return MinNum;
}

int popMin()
{
	int x;
	
	//if(isEmpty()) {
	//	printf("Stack is Empty\n");
	//	return;
	//}

	x = arrMin[topMin];
	topMin--;
}

int pop()
{
	int x;
	
	if(isEmpty()) {
		printf("Stack is Empty\n");
		return;
	}

	x = arr[top];
	top--;
}

void displayStack()
{
	int i;
	for(i = 0; i <= top; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n Top is %d\n", top);
	printf("\n Min Number is %d\n", MinNum);

}

int main()
{
	push(10);
	push(20);
	push(30);
	push(40);

	displayStack();

	
	return 0;
}

