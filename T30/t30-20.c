/*
20.Write a program to display the multiplication table of a given number.
*/

#include <stdio.h>

int main()
{
	int num, i;

	printf("Enter any number :\n");
	scanf("%d", &num);

	for(i=1; i <= 10; i++) {
		printf("%d * %i = %d\n", num, i, num*i);
	}

	return 0;
}

