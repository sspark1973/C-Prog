/*

Connect n ropes with minimum cost
There are given n ropes of different lengths, 
we need to connect these ropes into one rope. 
The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.

For example if we are given 4 ropes of lengths 4, 3, 2 and 6. We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6 and 5.
2) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
3) Finally connect the two ropes and all ropes have connected.

Total cost for connecting all ropes is 5 + 9 + 15 = 29. 
This is the optimized cost for connecting ropes. 
Other ways of connecting ropes would always have same or more cost. 

For example, if we connect 4 and 6 first (we get three strings of 3, 2 and 10), 
then connect 10 and 3 (we get two strings of 13 and 2). Finally we connect 13 and 2. 
Total cost in this way is 10 + 13 + 15 = 38.

We strongly recommend to minimize the browser and try this yourself first.
If we observe the above problem closely, 
we can notice that the lengths of the ropes which are picked first are included more than once in total cost. 

Therefore, the idea is to connect smallest two ropes first and recur for remaining ropes. 

This approach is similar to Huffman Coding. We put smallest ropes down the tree so that they can be repeated multiple times rather than the longer ropes.

Following is complete algorithm for finding the minimum cost for connecting n ropes.
Let there be n ropes of lengths stored in an array len[0..n-1]
1) Create a min heap and insert all lengths into the min heap.
2) Do following while number of elements in min heap is not one.
・・a) Extract the minimum and second minimum from min heap
・・b) Add the above two extracted values and insert the added value to the min-heap.
3) Return the value of only left item in min heap.

Following is C++ implementation of above algorithm.

!!! DON'T UNDERSTAND

*/

#include <iostream>
using namespace std;




struct MinHeap
{
	unsigned size;
	unsigned capacity;
	int *harr;
};

struct MinHeap *createMinHeap(unsigned capacity)
{
	struct MinHeap *minHeap = new MinHeap;
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->harr = new int[capacity];
	return minHeap;
}

void swapMinHeapNode(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void minHeapify(struct MinHeap *minHeap, int idx)
{
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if(left < minHeap->size && minHeap->harr[left] < minHeap->harr[smallest])
		smallest = left;

	if(right < minHeap->size && minHeap->harr[right] < minHeap->harr[smallest])
		smallest = right;

	if(smallest != idx) {
		swapMinHeapNode(&minHeap->harr[smallest], &minHeap->harr[idx]);
		minHeapify(minHeap, smallest);
	}
}	

void buildMinHeap(struct MinHeap *minHeap)
{
	int n = minHeap->size - 1;
	int i;
	for(i = (n-1)/2; i >= 0; --i)
		minHeapify(minHeap, i);
}

int isSizeOne(struct MinHeap *minHeap)
{
	return (minHeap->size == 1);
}

struct MinHeap *createAndBuildMinHeap(int len[], int size)
{
	struct MinHeap *minHeap = createMinHeap(size);
	for(int i = 0; i < size; ++i)
		minHeap->harr[i] = len[i];

	minHeap->size = size;
	buildMinHeap(minHeap);

	for(int i = 0; i < size; ++i) {
		cout << "minHeap->harr" << "[" << i << "] = " << minHeap->harr[i] << endl;
	}
	
	return minHeap;
}

int extractMin(struct MinHeap *minHeap)
{
	int temp = minHeap->harr[0];
	minHeap->harr[0] = minHeap->harr[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);
	return temp;
}

void insertMinHeap(struct MinHeap *minHeap, int val)
{
	++minHeap->size;
	int i = minHeap->size - 1;

	while(i && (val < minHeap->harr[(i - 1)/2])) {
		minHeap->harr[i] = minHeap->harr[(i - 1)/2];
		i = (i - 1) / 2;
	}

	minHeap->harr[i] = val;
}

int minCost(int len[], int n)
{
	int cost = 0;

	struct MinHeap * minHeap = createAndBuildMinHeap(len, n);

	while(!isSizeOne(minHeap)) {
		int min = extractMin(minHeap);
		int sec_min = extractMin(minHeap);

		cost += (min + sec_min);

		insertMinHeap(minHeap, min + sec_min);
	}

	return cost;
}

int main()
{
	int len[] = {4, 3, 2, 6};
	int size = sizeof(len) / sizeof(len[0]);

	cout << "Total cost for connecting ropes is " << minCost(len, size) << endl;
	
	return 0;
}

