/*
1. Write a program to find factorial of the given number. 

Recursion: A function is called'recursive 'if a statement within the body of a function calls the same function. 
It is also called'circular definition '. Recursion is thus a process of defining something in terms of itself.

*/

#include <stdio.h>
#include <stdlib.h>

int fact(int n);

int main()
{
	int x, i;

	printf("Enter a value for x!\n");
	scanf("%d", &x);

	i = fact(x);

	printf("\n Factorial of %d is %d\n", x, i);

	unsigned int a = 6;
	int b = -20;

	(a + b > 6) ? puts("> 6") : puts("<= 6");
	printf("\n (a+b) = %d\n", a+b);

	char *ptr;
	if((ptr = (char *)malloc(0)) == NULL)
		{}
	else
		puts("Got a null pointer");
		puts("Got a valid pointer");

	printf("\n");

	a = 5;
	b = 7;
	int c;
	c = a+++b;

	printf("a+++b = [%d]\n", c);
	return 0;
}

int fact(int n)
{
	if(n < 2)
		return(1);
	else {
		return(n*fact(n-1));
	}
}


