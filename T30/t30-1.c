/*
1. Write a program to find factorial of the given number. 

Recursion: A function is called'recursive 'if a statement within the body of a function calls the same function. 
It is also called'circular definition '. Recursion is thus a process of defining something in terms of itself.

*/

#include <stdio.h>

int fact(int n);

int main()
{
	int x, i;

	printf("Enter a value for x!\n");
	scanf("%d", &x);

	i = fact(x);

	printf("\n Factorial of %d is %d\n", x, i);
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


