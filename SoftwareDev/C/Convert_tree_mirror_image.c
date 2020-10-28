/* This program addresses the procedure and code to convert a tree into its mirror image */
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

//This function finds out the maximum number of nodes till the leaf node (i.e a node without any children).
int height(struct Treenode* root)
{
	int l, r;
	if(root == NULL)// This is the case when there are no nodes in bst.
	{
		return 0;
	}
	else
	{
		l = height(root->left); //Recursive calls to find the height of left sub-tree.
		r = height(root->right); // Recursive calls to find the height of right sub-tree.
		
		if(l >= r) // Return the one that's greater with 1 added to the number, i.e height = max(len(left sub tree), len(right sub tree))+1
		{
			return l+1; 
		}
		else
		{
			return r+1;
		}
	}
}

// This function calulates the mirror of the tree.
// Inputs 1. The root node.
struct Treenode* mirror(struct Treenode* root)
{
	if(root == NULL)
	{
		//Do nothing
	}
	else
	{
		struct Treenode* temp = NULL;
		temp = root->left;
		root->left = root->right;
		root->right = temp;
		root->left = mirror(root->left);// recursively calls till root becomes null.
		root->right = mirror(root->right);// recursively calls till root becomes null.
		return root;
	}
}

void printlevel(struct Treenode* root, int level)
{
	if(root == NULL)
	{
		return;
	}
	else if(level == 1)
	{
		
		printf("  %d  ", root->data);
	}
	else
	{
		printlevel(root->left, level-1);
		printlevel(root->right, level-1);
	}
}

void printlevelorder(struct Treenode* root) // The Breadth first traversal
{
	int i;
	int h = height(root);
	for(i = 1; i <= h; i++)
	{
		printlevel(root, i);
		printf("\n");
	}
}

void inOrder(struct Treenode* root) // This is used to correctly visualize that its getting reversed. 
{ 
  if (root == NULL)  
    return; 
    
  inOrder(root->left); 
  printf("%d ", root->data); 
  inOrder(root->right); 
} 

int main()
{
	// Initializing two tree nodes that will be checked eventually.
	struct Treenode* root = NULL;
	int i = 1;
	int data;
	printf("Enter data for tree: \n");// Dynamically taking the data.
	while(i)
	{
		printf("Enter data: \n");
		scanf("%d", &data);
		root = insert(root, data);
		printf("Do you want to enter more data: (1:Yes 0:No)\n");
		scanf("%d", &i);
	}
	
	inOrder(root); 

	//printlevelorder(root);
	printf("\n");
	
	root = mirror(root);
	//printlevelorder(root);
	inOrder(root); 

}
