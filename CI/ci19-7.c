/*
19.7 You are given an array of integers (both positive and negative). 
Find the continuous sequence with the largest sum. Return the sum.
EXAMPLE
Input: {2, -8, 3, -2, 4, -10}
Output: 5 (i.e., {3, -2, 4} )

SOLUTION
A simple linear algorithm will work by keeping track of the current subsequence sum. 
If that sum ever drops below zero, 
that subsequence will not contribute to the subsequent maximal subsequence since it would reduce it by adding the negative sum.
1 public static int getMaxSum(int[] a) {
2 int maxsum = 0;
3 int sum = 0;
4 for (int i = 0; i < a.length; i++) {
5 sum += a[i];
6 if (maxsum < sum) {
7 maxsum = sum;
8 } else if (sum < 0) {
9 sum = 0;
10 }
11 }
12 return maxsum;
13 }
NOTE: If the array is all negative numbers, what is the correct behavior? 
Consider this simple array {-3, -10, -5}. 
You could make a good argument that the maximum sum is either: 
(A) -3 (if you assume the subsequence can¡¯t be empty) 
(B) 0 (the subsequence has length 0) or 
(C) MINIMUM_INT (essentially the error case). 

We went with option B (max sum = 0), but there¡¯s no ¡°correct¡± answer. 
This is a great thing to discuss with your interviewer to show how careful you are.
*/

#include <stdio.h>

int input[] = { 2, -8, 3, -2, 4, -10 }; 

int getMaxSum(int input[])
{
	int maxsum = 0;
	int sum = 0, i;

	printf("nmber of array[%d]\n", sizeof(input)/sizeof(input[0]));

	//for(i = 0; i < sizeof(input)/sizeof(input[0]); ++i) {
	for(i = 0; i < 6; ++i) {
		sum += input[i];

		if(maxsum < sum) {
			maxsum = sum;
		} else if (sum < 0) {
			sum = 0;
		}
	}
	return maxsum;
}

int main()
{
	int imax = 0;

	imax = getMaxSum(input);
	printf("the largest sum[%d]\n", imax);

	return 0;
}

