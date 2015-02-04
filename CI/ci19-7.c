/*
19.7 You are given an array of integers (both positive and negative). 
Find the continuous sequence with the largest sum. Return the sum.
EXAMPLE
Input: {2, -8, 3, -2, 4, -10}
Output: 5 (i.e., {3, -2, 4} )

SOLUTION

http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

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
(A) -3 (if you assume the subsequence can’t be empty) 
(B) 0 (the subsequence has length 0) or 
(C) MINIMUM_INT (essentially the error case). 

We went with option B (max sum = 0), but there’s no “correct” answer. 
This is a great thing to discuss with your interviewer to show how careful you are.
*/

#include <stdio.h>

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))



int a1[] = { 2, -8, 3, -2, 4, -10 }; // 5
int a2[] = {-2, -3, 4, -1, -2, 1, 5, -3}; //  7
int a3[] = {-3,-2,-1,-4,-5,-6}; // -1
int a4[] = { 3, 2, -8, 3, -2, 4, -10 }; // 5


int getMaxSum(int input[], int n)
{
	int maxsum = 0;
	int sum = 0, i;
	int *a = input;
	//int n = sizeof(input)/sizeof(input[0]); - Not working
	// printf("nmber of array[%d]/[%d]=[%d]\n", sizeof(a1), sizeof(a1[0]), n);

	//for(i = 0; i < sizeof(input)/sizeof(input[0]); ++i) {
	for(i = 0; i < n; ++i) {
		sum += a[i];

		if(maxsum < sum) {
			maxsum = sum;
		} else if (sum < 0) {
			sum = 0;
		}
	}
	return maxsum;
}

int getMaxSum2(int input[], int n)
{
	int maxsum = 0;
	int sum = 0, i;
	int *a = input;

	maxsum = a[0];
	sum = a[0];

	for(i = 0; i < n; ++i) {
		sum = MAX(a[i], sum + a[i]);
		maxsum = MAX(maxsum, sum);
	}
	return maxsum;
}

int getMaxSum3(int input[], int n)
{
	int maxsum = 0;
	int sum = 0, i;
	int *a = input;

	if(a[0] < 0) {
		maxsum = a[0];
		sum = a[0];
	} else {
		maxsum = 0;
		sum = 0;
	}

	for(i = 0; i < n; ++i) {
		sum = MAX(a[i], sum + a[i]);
		maxsum = MAX(maxsum, sum);
	}
	return maxsum;
}


int main()
{
	int imax;
	int len;

	// 배열을 넘겨서 함수에서 사이즈를 구할려면 원하는 값이 나오질 않는다.
	len = sizeof(a1)/sizeof(a1[0]);
	imax = getMaxSum(a1, len);
	printf("1.the largest sum[%d]\n", imax);

	imax = getMaxSum2(a1, len);
	printf("1.the largest sum2[%d]\n", imax);

	imax = getMaxSum3(a1, len);
	printf("1.the largest sum3[%d]\n", imax);

	len = sizeof(a2)/sizeof(a2[0]);
	imax = getMaxSum(a2, len);
	printf("2.the largest sum[%d]\n", imax);

	imax = getMaxSum2(a2, len);
	printf("2.the largest sum2[%d]\n", imax);

	imax = getMaxSum3(a2, len);
	printf("2.the largest sum3[%d]\n", imax);

	len = sizeof(a3)/sizeof(a3[0]);
	imax = getMaxSum(a3, len); // Wrong - start with nagative value
	printf("3.the largest sum[%d]\n", imax);

	imax = getMaxSum2(a3, len);
	printf("3.the largest sum2[%d]\n", imax);

	imax = getMaxSum3(a3, len);
	printf("3.the largest sum3[%d]\n", imax);

	len = sizeof(a4)/sizeof(a4[0]);
	imax = getMaxSum(a4, len);
	printf("4.the largest sum[%d]\n", imax);

	imax = getMaxSum2(a4, len);
	printf("4.the largest sum2[%d]\n", imax);

	imax = getMaxSum3(a4, len);
	printf("4.the largest sum3[%d]\n", imax);

	return 0;
}

