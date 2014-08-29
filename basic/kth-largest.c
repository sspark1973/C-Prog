/*

Find k max elements in array of N size (C/C++)

*/

#include <stdio.h>

int arr[10] = { 12, 34, 21, 23, 234, 211, 3421, 1234, 2341, 2331, 122221 };

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void minHeapify(int a[], int size, int i)
{
	int l = 2*i;
	int r - 2*i + 1;
	int smallest = i;

	if(l < size && a[l] < a[smallest])
		smallest = l;
	
	if(r < size && a[r] < a[smallest])
		smallest = r;

	if(smallest != i) {
		swap(&a[i], &a[smallest]);
		minHeapify(a, size, smallest);
	}
}

void buildMinHeap(int a[], int size)
{
	int i;
	for(i = size / 2; i >= 0; i--)
		minHeapify(a, size, i);
}

int kthLargest(int a[], int size, int k) 
{
	int minHeap[k];

	int i;

	for(i = 0; i < k; i++)
		minHeap[i] = a[i];

	buildMinHeap(minHeap, k);

	for(i = k; i < size; i++) {
		if(a[i] > minHeap[0]) {
			minHeap[0] = a[i];
			minHeapify(minHeap, k, 0);
		}
	}

	return minHeap[0];
		
}

void find_k_max(int *arr, int size, int k)
{
	int kth = kthLargest(arr, size, k);

	printf("kth = [%d]\n", kth);
}

int main()
{
	int k;
	
	printf("Choose K : \n");
	scanf("%d", &k);

	find_k_max(arr, 10, k);

	return 0;
}
