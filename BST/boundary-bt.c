/*
Print boundary (edge nodes or outside frame) of a binary tree

PrintLeftBoundary - O(h), where h is height of tree, log(n) nodes on left are visited once
PrintLeafBoundary - O(n), as each node is visited once
PrintRightBoundary - O(h), where h is height of tree, log(n) nodes on right are visited once.

O(n+2h) total time complexity 

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *right;
	struct node *left;
	int data;
} node;

node *newNode(int data)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

void printLeftBoundary(node *root)
{
	if(root == NULL) return;
//	if(root->left) {
	if(root) {		
		printf("%d ", root->data);
		printLeftBoundary(root->left);
//	} else if(root->right) {
	} else if(root) {
		printf("%d ", root->data);
		printLeftBoundary(root->right);
	}
}

void printLeafBoundary(node *root)
{
	if(root) {
		printLeafBoundary(root->left);

		if(root->left == NULL && root->right == NULL)
			printf("%d ", root->data);

		printLeafBoundary(root->right);
	}
}

void printRightBoundary(node *root)
{
	if(root == NULL)
		return;

//	if(root->right) {
	if(root) {
		printRightBoundary(root->right);
		printf("%d ", root->data);
//	} else if(root->left) {
	} else if(root) {
		printRightBoundary(root->left);
		printf("%d ", root->data);
	}
}

void printBoundary(node *root)
{
	if(root) {
		printf("%d ", root->data);
		printf("\nLeft\n");
		printLeftBoundary(root->left);
		printf("\nLeaf\n");
		printLeafBoundary(root);
		printf("\nRight\n");
		printRightBoundary(root->right);
	}
}

/*
		1
	 /	   \
    2		3
 /	 \	   /  \
4	  5   6    7 
                 \
                  8

*/


int main()
{
	node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);

	printBoundary(root);

	return 0;
}

