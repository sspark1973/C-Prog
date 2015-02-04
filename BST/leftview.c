/*

http://www.geeksforgeeks.org/print-left-view-binary-tree/

refer to Boundary-bt.c

Given a Binary Tree, print left view of it. 
Left view of a Binary Tree is set of nodes visible when tree is visited from left side. 
Left view of following tree is 12, 10, 25.

          12
       /     \
     10       30
            /    \
          25      40 

The left view contains all nodes that are first nodes in their levels. 
A simple solution is to do level order traversal and print the first node in every level.

The problem can also be solved using simple recursive traversal. 
We can keep track of level of a node by passing a parameter to all recursive calls. 
The idea is to keep track of maximum level also. 
Whenever we see a node whose level is more than maximum level so far, 
we print the node because this is the first node in its level 
(Note that we traverse the left subtree before right subtree). Following is C implementation of this approach.

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

// Recursive function to print left view of a binary tree.
void leftViewUtil(struct node *root, int level, int *max_level)
{
    // Base Case
    if (root==NULL)  return;
 
    // If this is the first node of its level
    if (*max_level < level)
    {
        printf("%d\t", root->data);
        *max_level = level;
    }
 
    // Recur for left and right subtrees
    leftViewUtil(root->left, level+1, max_level);
	//printf("\nlevel=%d max=%d\n", level, *max_level);
    leftViewUtil(root->right, level+1, max_level);
}

// A wrapper over leftViewUtil()
void leftView(struct node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}


// http://www.geeksforgeeks.org/print-right-view-binary-tree-2/
// Recursive function to print left view of a binary tree.
/*
Right view of following tree is 1 3 7 8

          1
       /     \
     2        3
   /   \     /  \
  4     5   6    7
                  \
                   8
*/

void rightViewUtil(struct node *root, int level, int *max_level)
{
    // Base Case
    if (root==NULL)  return;
 
    // If this is the first node of its level
    if (*max_level < level)
    {
        printf("%d\t", root->data);
        *max_level = level;
    }
 
    // Recur for left and right subtrees
    rightViewUtil(root->right, level+1, max_level);
	printf("\nlevel=%d max=%d\n", level, *max_level);
    rightViewUtil(root->left, level+1, max_level);
}

// A wrapper over leftViewUtil()
void rightView(struct node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}


// Driver Program to test above functions
int main()
{
/*
			1
		 /	   \
	   2		     3
	 /	 \	   /  \
	4	  5   6    7
					\
					 8
*/					 

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);

    rightView(root); // 1, 3. 7, 8
    leftView(root);


/*
   12
  / 	\
10	 30
    /   \
  25     40 

*/
/*
  	struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
	
    leftView(root);
	rightView(root); 
*/
    return 0;
}

