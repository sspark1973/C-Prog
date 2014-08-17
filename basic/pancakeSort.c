/*
Pancake sorting
Given an an unsorted array, sort the given array. 
You are allowed to do only following operation on array.

flip(arr, i): Reverse array from 0 to i 
Unlike a traditional sorting algorithm, 
which attempts to sort with the fewest comparisons possible, 
the goal is to sort the sequence in as few reversals as possible.

The idea is to do something similar to Selection Sort. 
We one by one place maximum element at the end and reduce the size of current array by one.

Following are the detailed steps. Let given array be arr[] and size of array be n.

1) Start from current size equal to n and reduce current size by one while it¡¯s greater than 1. 
Let the current size be curr_size. Do following for every curr_size
¡¦¡¦a) Find index of the maximum element in arr[0..curr_szie-1]. Let the index be ¡®mi¡¯
¡¦¡¦b) Call flip(arr, mi)
¡¦¡¦c) Call flip(arr, curr_size-1)

Total O(n) flip operations are performed in above code. The overall time complexity is O(n^2)

*/
#include <stdio.h>

int findMax(int *arr, int n)
{
	int mi, i;
	for(mi = 0, i = 0; i < n; ++i)
		if(arr[i] > arr[mi])
			mi = i;

	printf("%s arr[%d]=%d\n", __FUNCTION__, mi, arr[mi]);
	return mi;
}

void flip(int *arr, int i)
{
	int temp, start = 0;
	while(start < i) {
		temp = arr[start];
		arr[start] = arr[i];
		arr[i] = temp;
		start++;
		i--;
	}
}

void pancakeSort(int *arr, int n)
{
	int curr_size;
	
	for(curr_size = n; curr_size > 1; --curr_size) {

		int mi = findMax(arr, curr_size);

		if(mi != curr_size - 1) {
			flip(arr, mi);
			flip(arr, curr_size - 1);
		}
	}
}

void printArray(int arr[], int n)
{
	int i;
	for(i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = {23, 10, 20, 11, 12, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("%s number of array = %d\n", __FUNCTION__, n);

	pancakeSort(arr, n);

	puts("Sorted Array ");

	printArray(arr, n);

	return 0;
}
