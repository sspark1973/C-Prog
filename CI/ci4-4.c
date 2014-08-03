/*
4.4 Given a binary search tree, 
design an algorithm which creates a linked list of all the nodes at each depth 
(eg, if you have a tree with depth D, you¡¯ll have D linked lists).

textbook:
SOLUTION
We can do a simple level by level traversal of the tree, 
with a slight modification of the breath-first traversal of the tree.

In a usual breath first search traversal, 
we simply traverse the nodes without caring which level we are on. 

In this case, it is critical to know the level. 
We thus use a dummy node to indicate when we have finished one level and are starting on the next.


     10     level:   0 {10}
    /  \             1 {5, 15}
  5     15           2 {3, 6, 11}
 / \    /    
3   6 11    result: {{10}, {5,15}, {3,6,11}}     

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct sll {
	int data;
	struct sll* next;
};

struct node* newNode(int data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

int height(struct node *root)
{
	if(root == NULL)
		return 0;
	else {
		int lh = height(root->left);
		int rh = height(root->right);

		printf("lh[%d] rh[%d]\n", lh, rh);

		if(lh > rh)
			return(lh + 1);
		else
			return(rh + 1);
	}
}



void printList(struct sll *head)
{
	printf("%s \n", __FUNCTION__);

	struct sll *temp = head;
	int len = 0;

	while(temp != NULL) {
		len++;
		temp = temp->next;

	}

	printf("%x\n", head);
	
	while(temp != NULL) {
		//printf("%s 2 \n", __FUNCTION__);
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void push(struct sll **head_ref, int data)
{
	struct sll *node = 
		(struct sll*)malloc(sizeof(struct sll));

	if(node == NULL) {
		printf("NULL pointer\n");
	}

	node->data = data;
	//printf("%s node->data[%d]\n", __FUNCTION__, node->data);

	node->next = (*head_ref);
	(*head_ref) = node;

	//printList(*(head_ref));
}		
struct sll* printGivenLevel(struct node* root, int level)
{
	static struct sll *head = NULL;

	if(root == NULL)
		return head;

	if(level == 1) {
		//printf("%s data[%d]\n", __FUNCTION__, root->data); 
		push(&head, root->data);
	} else if(level > 1) {
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1);
	}

	//printf("%s head[%x]\n", __FUNCTION__, head); 
		

	return head;
}
	
		
void printLevelOrder(struct node* root)
{
	struct sll *head = NULL;

	int h = height(root);
	int i;

	printf("height[%d]\n", h);

	for(i=1; i <= h; i++)
		head = printGivenLevel(root, i);

	
	printf("printLevelOrder head[%x]\n", head);
	printList(head);
	printf("\n");
}

int main()
{
	struct node *root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(15);
	root->left->left = newNode(3);
	root->left->right = newNode(6);
	root->right->left = newNode(11);

	printf("Level Order Traversal of Binary Tree is n");

	printLevelOrder(root);
	getchar();

	return 0;
}

