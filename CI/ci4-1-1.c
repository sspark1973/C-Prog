/*
Sorted Array to Balanced BST
Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements.

Examples:

Input:  Array {1, 2, 3}
Output: A Balanced BST
     2
   /  \
  1    3 

Input: Array {1, 2, 3, 4}
Output: A Balanced BST
      3
    /  \
   2    4
 /
1

Algorithm
In the previous post, we discussed construction of BST from sorted Linked List. 
Constructing from sorted array in O(n) time is simpler as we can get the middle element in O(1) time. 
Following is a simple algorithm where we first find the middle node of list and make it root of the tree to be constructed.

1) Get the Middle of the array and make it root.
2) Recursively do same for left half and right half.
      a) Get the middle of left half and make it left child of the root
          created in step 1.
      b) Get the middle of right half and make it right child of the
          root created in step 1.
Following is C implementation of the above algorithm. The main code which creates Balanced BST is highlighted.
*/

#include <stdio.h>
#include <stdlib.h>

struct TNode {
	int data;
	struct TNode *left;
	struct TNode *right;
};

struct TNode* newNode(int data)
{
	struct TNode *new_node = (struct TNode*)malloc(sizeof(struct TNode));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

struct TNode* sortedArrayToBST(int arr[], int start, int end)
{
	if(start > end)
		return NULL;

	int mid = (start + end)/2;

	printf("start[%d] end[%d] mid[%d]\n", start, end, mid);

	struct TNode *root = newNode(arr[mid]);

	root->left = sortedArrayToBST(arr, start, mid-1);
	root->right = sortedArrayToBST(arr, mid+1, end);

	return root;
}

void preOrder(struct TNode *node)
{
	if(node == NULL)
		return;

	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);

	printf("\n");
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr) / sizeof(arr[0]);

	struct TNode *root = sortedArrayToBST(arr, 0, n-1);

	printf("\n PreOder Traversal of constructed BST : \n");
	preOrder(root);

	return 0;
}

