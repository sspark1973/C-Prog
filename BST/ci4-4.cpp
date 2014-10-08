/*
Given a binary search tree, 
design an algorithm which creates a linked list of all the nodes at each depth 
(eg, if you have a tree with depth D, you¡¯ll have D linked lists).
*/

#include <iostream>
#include <vector>

using namespace std;

struct CTree
{
	CTree(int val) : right(0), left(0), value(val) {}
	CTree *left, *right;
	int value;
};

void Insert(CTree* &node, int newVal)
{
	if(node == 0) {
		//cout << "Insert node == 0  : " << newVal << endl;
		node = new CTree(newVal);
	}
	else if( newVal < node->value ) {
		//cout << "Insert newVal < node->value : " << newVal << endl;
		Insert( node->left, newVal);
	} else {
		//cout << "Insert newVal > node->value : " << newVal <<  endl;
		Insert( node->right, newVal);
	}
}

int PreOrder(CTree* myTree)
{
	if(myTree == NULL)
		return 0;

	cout << myTree->value << " ";

	PreOrder(myTree->left);
	PreOrder(myTree->right);

	return 0;
}

typedef vector<CTree *> ListNodes;
vector<ListNodes> arrNodes;

void Traverse(CTree *node, int &level)
{
	if(node == 0) {
		level -= 1;
		return;
	}

	cout << node->value << " " << level << " size : " << arrNodes.size() << endl;

	if(arrNodes.size() == level) arrNodes.push_back( ListNodes() );
	arrNodes[level].push_back(node);

	level++;
	Traverse(node->left, level);
	level++;
	Traverse(node->right, level);
	level--;
}

int main()
{
	CTree *myTree = new CTree(10);
	Insert( myTree, 5);
	Insert( myTree, 15);
	Insert( myTree, 3);

	//PreOrder(myTree);

	int lev = 0;
	Traverse(myTree, lev);

	cout << "\nResult arrNodes-size : " << arrNodes.size() << endl ;

	for(int i = 0; i < arrNodes.size(); ++i ) {
		for(int j = 0; j < arrNodes[i].size(); ++j) {
			cout << arrNodes[i][j]->value << " ";
		}
		cout << endl;
	}

	return 0;
}


