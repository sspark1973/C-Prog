/*
A tree, (NOT NECESSARILY BINARY), has nodes numbered 0 to N-1. An array has indices ranging from 0 to N-1. 
The indices denote the node ids and values denote the ids of parents. 
A value of -1 at some index k denotes that node with id k is the root. For ex:


3 3 3 -1 2
0 1 2 3 4
In the above, nodes with ids 0, 1 & 2 have 3 as parent. 3 is the root as its parent = -1 and 2 is the parent of node id 4. 

Given such an array, find the height of the tree.
*/

#include <stdio.h>

#define MAX_LEN 5

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

int countDepth(int *tree)
{
	int height[MAX_LEN], i;

	for(i = 0; i < MAX_LEN; i++) {
		height[i] = -1;
	}

	int maxHeight = -1;

	for(i = 0; i < MAX_LEN; i++) {
		if(height[i] == -1)
			maxHeight = MAX(maxHeight, findHeight(i, height, tree));
	}

	return maxHeight;
}

int findHeight(int i, int *height, int *tree)
{
	if(height[i] != -1)
		return height[i];

	if(tree[i] == -1)
		height[i] = 0;
	else
		height[i] = 1 + findHeight(tree[i], height, tree);

	return height[i];
}

int main()
{
	int tree[MAX_LEN] = {3, 3, 3, -1, 2};

	int depth = countDepth(tree);

	printf("Depth = %d\n", depth);

	return 0;
}

	

