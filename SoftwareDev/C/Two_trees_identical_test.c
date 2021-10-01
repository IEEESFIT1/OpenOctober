/* This program addresses the procedure and code on how to check whether two trees are exactly identical. */
#include <stdio.h>
#include <stdlib.h>

// Defining a structure for a tree node that has the data(in this question numerical value) and 2 pointers that points to the left and right treenodes.
struct Treenode
{
	int data;
	struct Treenode* left;
	struct Treenode* right;	
};

// This function adds a newnode  if given the value to be stored.
// Input includes 1. The value to be stored in the treenode.
struct Treenode* Newnode(int data)
{
	//Allocating the memory to the new treenode using malloc function.
	struct Treenode* root = (struct Treenode*)malloc(sizeof(struct Treenode));
	root->data = data;
	root->left = root->right = NULL;// Initially the left node and right node pointers are initialized to NULL.
	return root;// Returning the root of the node.
} 

// This function inserts the newnode according to the constraints of a binary search tree
// Input includes 1. The value to be stored in the treenode.
// 2. The node at which we want to insert new treenode.
struct Treenode* insert(struct Treenode* root, int data)
{
	if(root == NULL)
	{
		root = Newnode(data);// If there is no node at that place.
	}
	else if(data <= root->data)// If data is less than the node at which it is to be entered, it goes to the left of that particular node.
	{
		root->left = insert(root->left, data);
	}
	else
	{
		root->right = insert(root->right, data);// If data is more than the node at which it is to be entered, it goes to the right of that particular node.
	}
	return root;
}

// This function checks two bst if they are same or not.
// Input include: 1. Tree node 1.
// 2. Tree node 2.
int checktrees(struct Treenode* root1, struct Treenode* root2)
{
	//Declaring the itervariables. 
	int i, j, k;
	if(root1 == NULL && root2 == NULL)// If both the trees do not have any branches and are NULL we directly declare that they are identical.
	{
		return 1;
	}
	if(root1 != NULL && root2 != NULL)// If both have branches we recursively check the left branches separately and right branches separately.
	{
		i = root1->data == root2->data;
		j = checktrees(root1->left, root2->left); // Recursive calls.
		k = checktrees(root1->right, root2->right); // Recursive calls
		return (i && j && k);
	}
	else
	{
		return 0; // Any other case returns 0.
	}
}

int main()
{
	// Initializing two tree nodes that will be checked eventually.
	struct Treenode* root1 = NULL;
	struct Treenode* root2 = NULL;
	int i = 1;
	int data;
	printf("Enter data for tree1: \n");// Dynamically taking the data.
	while(i)
	{
		printf("Enter data: \n");
		scanf("%d", &data);
		root1 = insert(root1, data);
		printf("Do you want to enter more data: (1:Yes 0:No)\n");
		scanf("%d", &i);
	}
	i = 1;
	printf("Enter data for tree2: \n");
	while(i)
	{
		printf("Enter data: \n");
		scanf("%d", &data);
		root2 = insert(root2, data);
		printf("Do you want to enter more data: (1:Yes 0:No)\n");
		scanf("%d", &i);
	}
	printf("Identical 1 Non identical 0: %d", checktrees(root1, root2)); // Checking if they are identical.
	
	
}
