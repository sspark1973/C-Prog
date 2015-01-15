/*
http://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/

Inorder predecessor and successor for a given key in BST
I recently encountered with a question in an interview at e-commerce company. The interviewer asked the following question:

There is BST given with root node with key part as integer only. The structure of each node is as follows:


You need to find the inorder successor and predecessor of a given key. In case the given key is not found in BST, then return the two values within which this key will lie.

Following is the algorithm to reach the desired result. Its a recursive method:

Input: root node, key
output: predecessor node, successor node

1. If root is NULL
      then return
2. if key is found then
    a. If its left subtree is not null
        Then predecessor will be the right most child of left subtree or left child itself.
    b. If its right subtree is not null
        The successor will be the left most child of right subtree or right child itself.
    return
3. If key is smaller then root node
        set the successor as root
        search recursively into left subtree
    else
        set the predecessor as root
        search recursively into right subtree
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int key;
	struct _node *left;
	struct _node *right;
} node;

node *newNode(int data) {
	node *temp = (node *)malloc(sizeof(node));

	temp->key = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

node *insert(node *root, int data) {

	if(root == NULL)
		return newNode(data);

	if(data < root->key)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);

	return root;
}
	
void preOrder(node *root) {
	if(root == NULL) return;

	printf("%d\t", root->key);
	preOrder(root->left);
	preOrder(root->right);
}

void findPreSuc(node *root, node *pre, node *suc, int key) {
	if(root == NULL) return;

	if(root->key == key) {
		if(root->left != NULL) {
			node *tmp = root->left;
			while(tmp->right)
				tmp = tmp->right;
			pre = tmp;
		}

		if(root->right != NULL) {
			node *tmp = root->right;
			while(tmp->left)
				tmp = tmp->left;
			suc = tmp;
		}
		return;
	}

	if(root->key > key) {
		suc = root;
		findPreSuc(root->left, pre, suc, key);
	} else {
		pre = root;
		findPreSuc(root->right, pre, suc, key);
	}
}

	
int main() {
	node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	preOrder(root);
	printf("\n");

	int key = 50;

	node *pre = NULL;
	node *suc = NULL;

	findPreSuc(root, pre, suc, key);

	if(pre != NULL)
		printf("Pre %d\n", pre->key);
	else
		printf("No Predecessor\n");

	if(suc != NULL)
		printf("Suc %d\n", suc->key);
	else
		printf("No Successor\n");

	return 0;
}
