/*
PROBLEM.Implement a function to perform a binary search on a sorted array
of integers to find the index of a given integer. Comment on the efficiency of this
search, and compare it with other search methods.
*/

#include <stdio.h>

#define ARR_MAX 10

int arr[ARR_MAX] = { 1, 5, 8, 11, 24, 39, 40, 45, 58, 66 }

int binarySearch(int array[], int target, int lower, int upper) {
	if(lower > upper) {
		printf("Error Limits Reversed.\n");
		return 0;
	}

	int range;

	while(true) {
		range = upper - lower;
		if(range < 0) {
			printf("Error 

int main()
{
	int target = 58;
	int lower = 0, upper = sizeof(arr) / sizeof(arr[0]) - 1;
	int index = binarySearch(arr, target, lower, upper);

	return 0;
}

