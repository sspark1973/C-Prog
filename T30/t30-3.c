/*
3. Write a program to swap two numbers using a temporary variable. 
Swapping interchanges the values of two given variables. 

Logic: 
	step1: temp=x;
	step2: x=y; 
	step3: y=temp; 

	Example: if x=5 and y=8, consider a temporary variable temp. 
		step1: temp=x=5; 
		step2: x=y=8; 
		step3: y=temp=5; 
		Thus the values of the variables x and y are interchanged.
*/

#include <stdio.h>

void swap(int *x, int *y); // temp buffer
void swap2(int *x, int *y); // without temp buffer
void swap3(int *x, int *y); // bitwise


int main()
{
	int x = 6, y = 9;

	printf("x:%d\t y:%d\t\n", x, y);

	swap(&x, &y);

	printf("x:%d\t y:%d\t\n", x, y);

	swap2(&x, &y);

	printf("x:%d\t y:%d\t\n", x, y);

	swap3(&x, &y);

	printf("x:%d\t y:%d\t\n", x, y);

	return 0;
}

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/*
4. Write a program to swap two numbers without using a temporary variable. 
Swapping interchang es the values of two given variables. 

Logic: 
	step1: x=x+y; 
	step2: y=x-y; 
	step3: x=x-y; 

	Example: if x=7 and y=4 
		step1: x=7+4=11; 
		step2: y=11-4=7; 
		step3: x=11-7=4;

	Thus the values of the variables x and y are interchanged.
*/

void swap2(int *x, int *y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

/*
5. Write a program to swap two numbers using bitwise operators.
*/
void swap3(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}


