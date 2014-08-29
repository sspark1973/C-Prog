/*
Given a sorted array of 0¡¯s and 1¡¯s. Find out the no. of 0¡¯s in it. Write recursive, iterative versions of the code.
*/

#include <stdio.h>

#define N 6

int array[N] = { 0, 0, 0, 1, 1, 1};

int find_zero_count(int arr[N], int start, int end)
{
	if(start == end) {
		if(arr[start] == 0)
			return 1;
		else
			return 0;
	}

	int mid = start + (end-1)/2;
	if(arr[mid] == 0) {
		return (end-1)/2 + 1 + find_zero_count(arr, mid+1, end);
	} else {
		return find_zero_count(arr, start, mid-1);
	}
}
	

int main()
{
	int num = find_zero_count(array, 0, 5);

	printf("Num of Zeros = [%d]\n", num);
	return 0;
}

