// C Program for inorder, Preorder And Postorder Traversals In BST!
#include <stdio.h>
#include <stdlib.h>

typedef struct BST_node
{
	int data;
	struct BST_node *left, *right;
} BST;

BST *insertData(int val, BST *node)
{
	// root node
	if (node == NULL)
	{
		node = (BST *)malloc(sizeof(BST));
		node->data = val;
		node->left = NULL;
		node->right = NULL;
	}
	// left subtree
	else if (val <= node->data)
	{
		node->left = insertData(val, node->left);
	}
	// right subtree
	else if (val > node->data)
	{
		node->right = insertData(val, node->right);
	}
	return node;
}

void inorder(BST *node)
{
	if(node != NULL)
	{
		// Traversing Left Subtree of the node
		inorder(node->left);
		// Visiting the node
		printf("%d ",node->data);
		// Traversing Right subtree
		inorder(node->right);
	}
}

void preorder(BST *node)
{
	if(node != NULL)
	{
		// Visiting the node
		printf("%d ",node->data);
		// Traversing Left Subtree of the node
		preorder(node->left);
		// Traversing Right subtree
		preorder(node->right);
	}
}

void postorder(BST *node)
{
	if(node != NULL)
	{
		// Traversing Left Subtree of the node
		postorder(node->left);
		// Traversing Right subtree
		postorder(node->right);
		// Visiting the node
		printf("%d ",node->data);
	}
}

int main()
{
	// generating the above BST example
	BST *root = NULL;
	root = insertData(10, root);
	root = insertData(7, root);
	root = insertData(14, root);
	root = insertData(4, root);
	root = insertData(9, root);
	root = insertData(26, root);

	printf("Inorder Traversal of the BST : ");
	inorder(root);
	printf("\n");

	printf("Preorder Traversal of the BST : ");
	preorder(root);
	printf("\n");

	printf("Postorder Traversal of the BST : ");
	postorder(root);
	printf("\n");

	return 0;
}
