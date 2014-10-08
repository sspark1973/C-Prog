/*

Binary Search Trees :
In a BST, 

the value held by a node¡¯s left child is less than or equal to its own value, and 
the value held by a node¡¯s right child is greater than or equal to its value. 

In effect, the data in a BST is sorted by value: 

All the descendants to the left of a node are less than or equal to the node, and 
all the descendants to the right of the node are greater than or equal to the node.

    20
   /  \
  8   22
 / \
4  12
  /  \
 10  14

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y)) 

typedef struct Node {
	int data;
	struct Node *right;
	struct Node *left;
} Node;

Node *findNode(Node *root, int value) {
	if(root == NULL) return NULL;
	int currval = root->data;
	if(currval == value) return root;
	if(currval < value) {
		return findNode(root->right, value);
	} else {
		return findNode(root->left, value);
	}
}

int treeHeight(Node *node) {
	if(node == NULL) return 0;
	return 1+ MAX(treeHeight(node->left), treeHeight(node->right));
}

void preOrderTraversal(Node *root) {
	if(root == NULL) return;
	printf("%d\t", root->data);

	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root) {
	if(root == NULL) return;
	inOrderTraversal(root->left);
	printf("%d\t", root->data);
	inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root) {
	if(root == NULL) return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	printf("%d\t", root->data);
}

// Page 73
Node *findLowestCommonAncestor(Node *root, int value1, int value2) {
	while(root != NULL) {
		int value = root->data;

		if(value > value1 && value > value2) {
			root = root->left;
		} else if(value < value1 && value < value2) {
			root = root->right;
		} else {
			return root;
		}
	}
	return NULL;
}

int traverse(Node *node, int count, Node arr[]) {
	if(node == NULL)
		return count;
	if(arr != NULL)
		arr[count] = *node;
	count++;
	count = traverse(node->left, count, arr);
	count = traverse(node->right, count, arr);
	return count;
}

#define SIZE_ARRAY 7

Node* heapifyBinaryTree(Node *root) {
	int size = traverse(root, 0, NULL);
	Node nodeArray[SIZE_ARRAY] = {0};
	traverse(root, 0, nodeArray);

	return nodeArray;
}

Node *newNode(int value) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = value;
	node->right = NULL;
	node->left = NULL;

	return node;
}

int main() 
{
	Node *root = newNode(20); 
	root->left = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right = newNode(22);

	int height = treeHeight(root);
	printf("Tree Height : %d\n", height);

	printf("preOrderTraversal :\n");
	preOrderTraversal(root);
	printf("\n");

	printf("inOrderTraversal :\n");
	inOrderTraversal(root);
	printf("\n");

	printf("postOrderTraversal :\n");
	postOrderTraversal(root);
	printf("\n");

	Node *anNode = findLowestCommonAncestor(root, 4, 14);
	printf("findLowestCommonAncestor 4 and 14 is : %d\n", anNode->data);

	int count = traverse(root, 0, NULL);
	printf("traverse count = %d\n", count);

	Node *newRoot = heapifyBinaryTree(root);
		

	return 0;
}

