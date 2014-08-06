/*
Write a C program to print all permutations of a given string
A permutation, also called an ¡°arrangement number¡± or ¡°order,¡± 
is a rearrangement of the elements of an ordered list S 
into a one-to-one correspondence with S itself. 

A STRING of length n has n! permutation.
Source: Mathword(http://mathworld.wolfram.com/Permutation.html)

Below are the permutations of string ABC.
ABC, ACB, BAC, BCA, CAB, CBA

Here is a solution using backtracking.
*/
#include <stdio.h>


void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n)
{
	int j;
	if(i == n)
		printf("%s\n", a);
	else {
		for(j = i; j <= n; j++) {
			swap((a+i), (a+j));
			//printf("i[%d] j[%d] \n", i, j);
			permute(a, i+1, n);
			//printf("i[%d] j[%d] \n", i, j);
			swap((a+i), (a+j));
			//printf("i[%d] j[%d] \n\n", i, j);
		}
	}
}

int main()
{
	char a[] = "ABC";
	permute(a, 0, 2);
	getchar();
	return 0;
}

