/*
Largest Sum Contiguous Subarray
Write an efficient C program to find the sum of contiguous subarray within a one-dimensional array of numbers 
      which has the largest sum.
*/


#include <stdio.h>

int max(int x, int y)
{
	return (x > y ? x : y);
}

/*
Following is another simple implementation suggested by Mohit Kumar. 
The implementation handles the case when all numbers in array are negative.

int a[] = {-3, 100, -4, -2, 9, -63, -200, 55};

*/
int maxSubArraySum2(int a[], int size) 
{
	int max_so_far = a[0], i;
	//int max_so_far = 0, i; // issue with first number is negative
	int curr_max = a[0];
	//int curr_max = 0; // issue with first number is negative

	for(i = 0; i < size; i++) {
		curr_max = max(a[i], curr_max + a[i]);
		max_so_far = max(max_so_far, curr_max);
	}

	return max_so_far;
}

/*
Kadane¡¯s Algorithm:

Initialize:
    max_so_far = 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_ending_here < 0)
            max_ending_here = 0
  (c) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
return max_so_far

int a[] = {-3, 100, -4, -2, 9, -63, -200, 55}; 

*/
int maxSubArraySum(int a[], int size)
{
	int i;
	int max_end = 0, max_so_far = 0;

	for(i=0; i < size; ++i) {
		max_end = max_end + a[i];
		if(max_end < 0)
			max_end = 0;

		if(max_so_far < max_end)
			max_so_far = max_end;
	}
	/* Algorithm doesn't work for all negative numbers */
	/*
	 It simply returns 0 if all numbers are negative. 
	 For handling this we can add an extra phase before actual implementation. 
	 The phase will look if all numbers are negative, if they are it will return maximum of them (or smallest in terms of absolute value). 
	 There may be other ways to handle it though. 
	 Above program can be optimized further, 
	 if we compare max_so_far with max_ending_here only if max_ending_here is greater than 0.
	*/
	for(i=0; i < size; ++i) {
		max_end = max_end + a[i];
		if(max_end < 0)
			max_end = 0;
		else if(max_so_far < max_end)
			max_so_far = max_end;
	}
	
	return max_so_far;
}


int main()
{
	//int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	//int a[] = {-3, 100, -4, -2, 9, -63, -200, 55};
	int a[] = {-3, -100, -4, -2, -9, -63, -200, -55};
	int n = sizeof(a)/sizeof(a[0]);

	int max_sum = maxSubArraySum(a, n);
	int max_sum2 = maxSubArraySum2(a, n);

	printf("Maximum contiguous max_sum[%d] max_sum2[%d]\n", max_sum, max_sum2);
	getchar();

	return 0;
}


