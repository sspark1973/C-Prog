/*
Inorder Successor in Binary Search Tree
In Binary Tree, 
Inorder successor of a node is the next node in Inorder traversal of the Binary Tree. 
Inorder Successor is NULL for the last node in Inoorder traversal.

In Binary Search Tree, 
Inorder Successor of an input node can also be defined as the node with the smallest key greater than the key of input node. 
So, it is sometimes important to find next node in sorted order.

    20
   /  \
  8   22
 / \
4   12
   /  \
  10   14

In the above diagram, inorder successor of 8 is 10, inorder successor of 10 is 12 and inorder successor of 14 is 20.
*/

/*
Method 1 (Uses Parent Pointer) 
In this method, we assume that every node has parent pointer.

The Algorithm is divided into two cases on the basis of right subtree of the input node being empty or not.

Input: node, root // node is the node whose Inorder successor is needed.
output: succ // succ is Inorder successor of node.

1) If right subtree of node is not NULL, then succ lies in right subtree. Do following.
Go to right subtree and return the node with minimum key value in right subtree.
2) If right sbtree of node is NULL, then succ is one of the ancestors. Do following.
Travel up using the parent pointer until you see a node which is left child of it¡¯s parent. The parent of such a node is the succ.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
	struct node* parent;
};

struct node* insert(struct node* node, int data)
{
	if(node == NULL) {
		struct node* new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = data;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->parent = NULL;
		return new_node;
	} else {
		struct node *temp;

		if(data <= node->data) {
			temp = insert(node->left, data);
			node->left = temp;
			temp->parent = node;
		} else {
			temp = insert(node->right, data);
			node->right = temp;
			temp->parent = node;
		}

		return node;
	}
}		

struct node* minValue(struct node* node)
{
	struct node* current = node;

	while(current->left != NULL) {
		current = current->left;
	}

	return current;
}

/*
Method 2 (Search from root) 
Parent pointer is NOT needed in this algorithm. The Algorithm is divided into two cases on the basis of right subtree of the input node being empty or not.

Input: node, root // node is the node whose Inorder successor is needed.
output: succ // succ is Inorder successor of node.

1) If right subtree of node is not NULL, then succ lies in right subtree. Do following.
Go to right subtree and return the node with minimum key value in right subtree.
2) If right sbtree of node is NULL, then start from root and us search like technique. Do following.
Travel down the tree, if a node¡¯s data is greater than root¡¯s data then go right side, otherwise go to left side.
*/

struct node* inOrderSuccessor(struct node* root, struct node* n)
{
	if(n->right != NULL)
		return minValue(n->right);

	struct node *p = n->parent;

	while(p != NULL && n == p->right) {
		n = p;
		p = p->parent;
	}

	return p;
}

struct node* inOrderSuccessor2(struct node* root, struct node* n)
{
	if(n->right != NULL)
		return minValue(n->right);

	struct node *succ = NULL;

	while(root != NULL) {
		if(n->data < root->data) {
			succ = root;
			root = root-> left;
		} else if (n->data > root->data) {
			root = root->right;
		} else
			break;
	}

	return succ;
}

int main()
{
	struct node* root = NULL, *temp, *succ, *min;

	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 22);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 10);
	root = insert(root, 14);

	temp = root->left->right->left;

	succ = inOrderSuccessor2(root, temp);

	if ( succ != NULL )
		printf("\n Inorder Successor of %d is %d\n", temp->data, succ->data);
	else
		printf("\n Inorder Successor doesn't exit\n");

	getchar();
	return 0;
}



