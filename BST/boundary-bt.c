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
	if(root->left) {
		printf("%d ", root->data);
		printLeftBoundary(root->left);
	} else if(root->right) {
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

	if(root->right) {
		printRightBoundary(root->right);
		printf("%d ", root->data);
	} else if(root->left) {
		printRightBoundary(root->left);
		printf("%d ", root->data);
	}
}

void printBoundary(node *root)
{
	if(root) {
		printf("%d ", root->data);
		printLeftBoundary(root->left);
		printLeafBoundary(root);
		printRightBoundary(root->right);
	}
}

int main()
{
	node *root = newNode(1000);
	root->left = newNode(500);
	root->right = newNode(1500);
	root->left->right = newNode(510);
	root->left->right->right = newNode(600);
	root->left->left = newNode(240);
	root->left->left->left = newNode(120);
	root->left->left->right = newNode(300);
	root->right->left = newNode(1300);
	root->right->left->right = newNode(1320);

	printBoundary(root);

	return 0;
}

