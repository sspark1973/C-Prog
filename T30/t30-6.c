/*
6. Write a program to find the greatest of three numbers.
*/

#include <stdio.h>

int main()
{
	int a, b, c;

	printf("Enter a, b, c:\n");
	scanf("%d %d %d", &a, &b, &c);

	if(a>b && a>c) {
		printf("a is greater than b and c\n");
	} else if(b>a && b>c) {
		printf("b is greater than a and c\n");
	} else if(c>a && c>b) {
		printf("c is greater than a and b\n");
	}

	/*
	7. Write a program to find the greatest among ten numbers.
	*/
	int ar[10];
	int i;
	int greatest;

	printf("Enter ten values:\n");

	for(i=0; i < 10; i++) {
		scanf("%d", &ar[i]);
	}

	greatest = ar[0];
	for(i=0; i<10; i++) {
		if(ar[i] > greatest) {
			greatest = ar[i];
		}
	}

	printf("\n Greatest of ten numbers is %d\n", greatest);

	return 0;
}



