/* This program addresses the procedure and code on inserting a node at a given position in a linked list */
#include <stdio.h>
#include <stdlib.h>

// Defining a structure for a node that has the data(in this question numerical) and the pointer that points to the next node.
struct Node
{
	int data; // The Data that is to be stored in the node.
	struct Node* next; // A pointer of the type struct Node* which points to the next node.
};

// This function prints the linked list by traversing through out the linked list untill the head is null, i.e end of the list.
// Input includes 1. The head of the linked list
void printll(struct Node* head)
{
	while(head != NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

// This is the function that inserts a node at a given position:
// Input description
// 1. The head of the linked list which is the main point of reference in a liked list.
// 2. The variable x which is the position where we want to insert the new node.
// 3. The variable n is the value/data we want to store in that node.
struct Node* insert(struct Node* head, int x, int n) 
{
	int count;
	struct Node* newn = NULL;
	struct Node* temp = head;
	struct Node* tempy = NULL;
	newn = (struct Node*)malloc(sizeof(struct Node)); // newn is a pointer of the type struct Node* which points to memory of size same as the struct node.
													
	newn->data = n;
	if(x == 0) // If we want to insert at the starting which refers to the value of x being equals to 0.
	{
		newn->next = temp;
		head = newn; // This steps changes the head as there is a node being inserted at the beginning of the linked list.
		return head; // The new head is returned which will be the new point of reference.
	}
	else
	{
		if(x == 6) // 6 here represents the end position of the linked list(Our linkedlist's size is 5).Which means this code block will insert the node at the end of the linked list.
		{
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newn;
			newn->next = NULL;
			return head;
		}
		else
		{
			for(count = 0; count <= x; count++) // This is where if the user enters any number/position x such that 0<x<n (n is the length of the list), the control comes to.
			{
				if(count == x-1)
				{
					tempy = temp;
				}
				else if(count == x)
				{
					break;
				}
				temp = temp->next;
			}
			newn->next = temp;
			tempy->next = newn;
			return head;
		}
	}
}

int main()
{
	//Initializing all the nodes with null.
	//There are 6 nodes including the head.
	struct Node* head = NULL; // head implies the 0th position in the linked list.
	struct Node* first = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	struct Node* fourth = NULL;
	struct Node* fifth = NULL;
	
	//Allocating memory to all the nodes using malloc function.
	head = (struct Node*)malloc(sizeof(struct Node));
	first = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));
	fifth = (struct Node*)malloc(sizeof(struct Node));

	//Assigning values to the the data contents of all the nodes.
	head->data = 1;
	head->next = first;
	
	first->data = 2;
	first->next = second;
	
	second->data = 3;
	second->next = third;
	
	third->data = 4;
	third->next = fourth;
	
	fourth->data = 5;
	fourth->next = NULL;
	
	fifth->data = 6;
	fifth->next = NULL;
	
	// We are trying to insert a node at the end so value of x is 6 & the value to be entered is 10.
	head = insert(head, 6, 10);
	printll(head);
	
	return(0);
}
