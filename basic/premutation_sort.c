/*
Q : The input is a sequence x1,x2,...,xn of integers in an arbitrary order, and another sequence 
a1,a2,..,an of distinct integers from 1 to n (namely a1,a2,...,an is a permutation of 
1, 2,..., n). Both sequences are given as arrays. Design an 0(n logn) algorithm to order 
the first sequence according to the order imposed by the permutation. In other words, for 
each i, Xi should appear in the position given in ai. 
For example, 
if x = 17(x1), 5(x2), 1(x3),9(x4), and 
a =  3(a1), 2(a2), 4(a3), 1(a4), 
then the outcome should be x = 9, 5, 17, 1. 

The algorithm should be in-place, so you cannot use an additional array.
*/
#include <stdio.h>

void display(int x[], int size)
{
	int i;
	for(i = 0; i < size; ++i)
		printf("%d\t", x[i]);

	printf("\n");
}

int *permutation_sort(int x[], int a[], int size)
{
   int c;
   for(c=0; c<size; c++) {
      int goingTo = a[c] - 1;
	  int valueToMove = x[c];

	  if(a[c] < 0) {
	  	continue;
	  }
	  int loop = 0;

	  while(c != goingTo) {
	  	int temp = x[goingTo];
		x[goingTo] = valueToMove;
		valueToMove = temp;
		temp = a[goingTo] - 1;
		a[goingTo] = -a[goingTo];
		goingTo = temp;
		printf("loop[%d] ", loop++);
		display(x, size);
	  }
	  x[c] = valueToMove;
   }

   for(c=0; c < size; c++) {
   	  a[c] = abs(a[c]);
   }

   return a;
}

int main()
{
   int x[] = {5, 12, 14, 27, 3, 2, 13, 17, 7, 21};
   int a[] = {4, 7, 3, 10, 8, 2, 5, 9, 6, 1};
   int *result, i;

   int size = sizeof(x)/sizeof(x[0]);

   printf("size of void pointer = %d\n", sizeof(void*));

   result = permutation_sort(x, a, size);

   for(i=0; i<size; ++i) {
   	  printf("%d\t", result[i]);
   }
   printf("\n");

   return 0;
}
