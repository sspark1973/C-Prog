#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node *left;
	struct _node *right;
} node;

node *newNode(int data) {
	node* temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
}

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

int maxDepth(node *root) {
	if(root == NULL) return 0;
	
	int lh = maxDepth(root->left);
	int rh = maxDepth(root->right);

	return 1 + MAX(lh, rh);
}

int main() {
	node *root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Hight of tree is %d\n", maxDepth(root));

	return 0;
}
