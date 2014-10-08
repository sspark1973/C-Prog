/*
Given a sequence of non-negative integers find a subsequence of length 3 having maximum product with the numbers of the subsequence being in ascending order. 
Example: 
Input: 6 7 8 1 2 3 9 10 
Ouput: 8 9 10

*/


#include <stdio.h>


#define MAX_LEN 3

int arr[] = {6, 7, 8, 1, 2, 3, 9, 12};

int main()
{
   int maxProduct = 0;
   int subarr[MAX_LEN];
   int i, j, k;
   int arr_len = sizeof(arr)/sizeof(arr[0]);

   for(i=1; i < arr_len - 1; i++) {
   	int leftLowest = 0;
	int rightHighest = 0;

    for(j=0; j < i; j++) {
		if(arr[j] < arr[i] && arr[j] > leftLowest) {
			leftLowest = arr[j];
		}
    }

	for(k = i + 1; k < arr_len; k++) {
		if(arr[k] > arr[i] && arr[k] > rightHighest) {
			rightHighest = arr[k];
		}
	}

	int curProduct = arr[i]*leftLowest*rightHighest;

	if(curProduct > maxProduct) {
		maxProduct = curProduct;
		subarr[0] = leftLowest;
		subarr[1] = arr[i];
		subarr[2] = rightHighest;
	}
   }

   for(i=0; i < MAX_LEN; i++) {
   	printf("%d\t", subarr[i]);
   }
   printf("\n");
}
	

   
   
