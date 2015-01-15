/*
How to determine if a binary tree is height-balanced?
A tree where no leaf is much farther away from the root than any other leaf. 
Different balancing schemes allow different definitions of ¡°much farther¡± and different amounts of work to keep them balanced.

Consider a height-balancing scheme where following conditions should be checked to determine if a binary tree is balanced.
An empty tree is height-balanced. A non-empty binary tree T is balanced if:
1) Left subtree of T is balanced
2) Right subtree of T is balanced
3) The difference between heights of left subtree and right subtree is not more than 1.

The above height-balancing scheme is used in AVL trees. The diagram below shows two trees, 
one of them is height-balanced and other is not. 
The second tree is not height-balanced because height of left subtree is 2 more than height of right subtree.

To check if a tree is height-balanced, get the height of left and right subtrees. 
Return true if difference between heights is not more than 1 and left and right subtrees are balanced, otherwise return false

Time Complexity: O(n)

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int data)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));

	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

int max(int a, int b)
{
	return (a >= b) ? a : b;
}

int height(struct node *node)
{
	if(node == NULL)
		return 0;

	return 1 + max(height(node->left), height(node->right));
}

bool isBalanced(struct node *root)
{
	int lh;
	int rh;

	if(root == NULL)
		return true;

	lh = height(root->left);
	rh = height(root->right);

// The abs function returns the absolute value of a number (makes it positive) as an integer. - stdlib.h
	if( abs(lh-rh) <= 1 &&
		isBalanced(root->left) &&
		isBalanced(root->right))
		return true;

	printf("lh[%d] rh[%d] root->left[%d] root->right[%d]\n", lh, rh, isBalanced(root->left), isBalanced(root->right));
	return 0;
}

bool isBalanced2(struct node *root, int *height)
{
	int lh = 0, rh = 0;

	int l = 0, r = 0;

	if(root == NULL) {
		*height = 0;
		return 1;
	}

	l = isBalanced2(root->left, &lh);
	r = isBalanced2(root->right, &rh);

	*height = (lh > rh ? lh : rh) + 1;

	printf("lh[%d] rh[%d] l[%d] r[%d]\n", lh, rh, l, r);

	if((lh - rh >= 2) || (rh - lh >= 2))
		return 0;
	else
		return l&&r;
		
}

int main()
{
	struct node *root = newNode(8);
	int height = 0;
	root->left = newNode(2);
	root->right = newNode(10);
	root->left->right = newNode(4);
	root->left->left = newNode(3);
	root->left->right->right = newNode(7);
	root->right->left = newNode(9);

	if(isBalanced2(root, &height))
		printf("Tree is balanced\n");
	else
		printf("Tree is not balanced\n");

	getchar();
	return 0;
}
	

