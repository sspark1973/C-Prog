/*
Lowest Common Ancestor in a Binary Search Tree.
Given values of two nodes in a Binary Search Tree, 
write a c program to find the Lowest Common Ancestor (LCA). 
You may assume that both the values exist in the tree.

The function prototype should be as follows:

 struct node *lca(node* root, int n1, int n2)
 n1 and n2 are two given values in the tree with given root.
BST_LCA

For example, 
consider the BST in diagram, LCA of 10 and 14 is 12 and LCA of 8 and 14 is 8.

    20
   /  \
  8   22
 / \
4   12
   /  \
  10   14


Following is definition of LCA from Wikipedia:
Let T be a rooted tree. The lowest common ancestor 
between two nodes n1 and n2 is defined as the lowest node in T 
that has both n1 and n2 as descendants 
(where we allow a node to be a descendant of itself).

The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 
that is located farthest from the root. 
Computation of lowest common ancestors may be useful, 
for instance, as part of a procedure for determining the distance 
between pairs of nodes in a tree: 
the distance from n1 to n2 can be computed as the distance from the root to n1, 
plus the distance from the root to n2, 
minus twice the distance from the root to their lowest common ancestor. (Source Wiki)

Solutions:
If we are given a BST where every node has parent pointer, 
then LCA can be easily determined by traversing up using parent pointer 
and printing the first intersecting node.

We can solve this problem using BST properties. 
We can recursively traverse the BST from root. 
The main idea of the solution is, 
while traversing from top to bottom, 
the first node n we encounter with value between n1 and n2, 
i.e., n1 < n < n2 or same as one of the n1 or n2, 
is LCA of n1 and n2 (assuming that n1 < n2). So just recursively traverse the BST in, 
if node's value is greater than both n1 and n2 then our LCA lies in left side of the node, 
if it's is smaller than both n1 and n2, then LCA lies on right side. 
Otherwise root is LCA (assuming that both n1 and n2 are present in BST)

Time complexity of above solution is O(h) where h is height of tree. 
Also, the above solution requires O(h) extra space in function call stack for recursive function calls.

*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node *newNode(int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));

	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

struct node *lca(struct node *root, int n1, int n2)
{
	if(root == NULL) return NULL;

	if(root->data > n1 && root->data > n2)
		return lca(root->left, n1, n2);

	if(root->data < n1 && root->data < n2)
		return lca(root->right, n1, n2);

	return root;
}

int main()
{
	struct node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	int n1 = 10, n2 = 14;
	struct node *t = lca(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);
	
	n1 = 14, n2 = 8;
	t = lca(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);

	n1 = 10, n2 = 22;
	t = lca(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);

	getchar();
	return 0;
}
	


