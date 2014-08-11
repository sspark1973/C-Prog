/*
19.4 Write a method which finds the maximum of two numbers. 
You should not use if-else or any other comparison operator.

EXAMPLE
Input: 5, 10
Output: 10
*/
#include <stdio.h>

int getMax(int a, int b)
{
	int c = a - b;
	int k = ( c >> 31 ) & 0x1;
	int max = a - k * c;

	return max;
}

int main()
{
	int a = 20;
	int b = 4;

	int c = getMax(a, b);

	printf("Max[%d] between a[%d] and b[%d]\n", c, a, b);
}
