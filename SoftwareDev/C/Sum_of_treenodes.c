/* This program addresses the procedure and code to check whether the given sum = sum(root down to the leaf keys) */
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
	struct Treenode* root = (struct Treenode*)malloc(sizeof(struct Treenode));
	root->data = data;
	root->left = root->right = NULL;
	return root;
} 

// This function inserts the newnode according to the constraints of a binary search tree.
// Input includes 1. The value to be stored in the treenode.
// 2. The node at which we want to insert new treenode.
struct Treenode* insert(struct Treenode* root, int data)
{
	if(root == NULL)
	{
		root = Newnode(data);
	}
	else if(data <= root->data)
	{
		root->left = insert(root->left, data);
	}
	else
	{
		root->right = insert(root->right, data);
	}
	return root;
}
// This function the sum as per the given requirement in the question.
// Input includes 1. The root.
// 2. The s variable represents the sum which is to be checked with.
int sum(struct Treenode* root, int s)
{
	int i, j;
	if(root == NULL && s == 0)//The is the base case 1 which is when there is no tree i.e root is NULL and sum is 0
	{
		return 1;//Which means its true as the sum is 0 and the root value is null. 
	}
	else if(root == NULL && s < 0 || root == NULL && s > 0)// Base case 2, where in if the root value is NULL and the sum is either less or greater than zero, its false as if the root is NULL, sum should also be 0.
	{
		return 0;
	}
	else//Executed whenever the root value is not NULL
	{
		i = sum(root->left, s-root->data);// Recursilvely calling the function by decreasing the value of the keys from the sum.
		j = sum(root->right, s-root->data);
		if(i == 1 || j == 1)//If at the last if we get the base case1 
		{
			return 1;// It's true (i.e given sum is equal to the sum of the keys of either left sub tree or right subtree.)
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	struct Treenode* root = NULL;
	int i = 1;
	int data;
	printf("Enter data for tree: \n");//Dynamic input.
	while(i)
	{
		printf("Enter data: \n");
		scanf("%d", &data);
		root = insert(root, data);
		printf("Do you want to enter more data: (1:Yes 0:No)\n");
		scanf("%d", &i);
	}
	printf("\nSum yes or no: %d", sum(root, 21));
}
