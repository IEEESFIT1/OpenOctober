/* This program file adresses the procedure and code to find the length of a linked list */
#include <stdio.h>
#include <stdlib.h>

// Defining a structure for a node that has the data(in this question numerical) and the pointer that points to the next node.
struct Node
{
	int data; // Data that is to be stored in the node.
	struct Node* next; // A pointer of the type struct Node* which points to the next node.
};

//This function finds the length of the linked list.
// Inputs include 1. The head of the linked list
int len(struct Node* head)
{
	// Setting the initial value of the count variable to zero.
	int count = 0;
	// Creating a temporary node called temp that can be traversed instead of head just because we don't want to lose the head.
	struct Node* temp = NULL;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp = head;

	while(temp != NULL) // This while loops executes till the temp becomes NULL.
	{
		count = count + 1; // At each successful iteration the count variable increments by 1.
		temp = temp->next;
	}
	return count;
}

int main()
{
	//Initializing all the nodes with null.
	//There are 5 nodes including the head.
	struct Node* head = NULL; // head implies 0th position
	struct Node* first = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	struct Node* fourth = NULL;
	
	//Allocating memory to all the nodes using malloc function.
	head = (struct Node*)malloc(sizeof(struct Node));
	first = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));
	
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
	
	//Printing the length of the linked list by calling the length function which was defined previously.
	printf("%d", len(head));
	
	return(0);

}
