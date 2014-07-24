/*
2. Write a program to check whether the given number is even or odd.
*/

#include <stdio.h>

int main()
{
	int a;
	printf("Enter a:\n");
	scanf("%d", &a);

	if(a%2 == 0)
		printf("The given number is EVEN\n");
	else
		printf("The given number is ODD\n");

	return 0;
}

