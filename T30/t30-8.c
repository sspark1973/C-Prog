/*
8. Write a program to check whether the given number is a prime.
A prime number is a natural number that has only one and itself as factors. 

Examples: 2, 3, 13 are prime numbers.
*/

#include <stdio.h>

int main()
{
	int n, c=2;
	printf("Enter any number n:\n");
	scanf("%d", &n);

	for(c=2; c <= n-1; c++) {
		if(n%c == 0) {
			printf("n[%d] is not a prime number\n", n);
			break;
		}
	}

	if(c==n) {
		printf("n[%d] is a prime number\n", n);
	}

	return 0;
}
	

