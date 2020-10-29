/* his program addresses the procedure and code on counting how many times a given value occurs in a linked list */
#include <stdio.h>
#include <stdlib.h>

// Defining a structure for a node that has the data(in this question numerical) and the pointer that points to the next node.
struct Node
{
	int data; // Data that is to be stored in the node
	struct Node* next; // A pointer of the type struct Node* which points to the next node
};

//This function finds the count of how many times a given value occurs in a linked list.
// Inputs include 1. The head of the linked list.
// 2. x is the variable which is to be checked.
int count(struct Node* head, int x)
{
	
	// Setting the initial value of the count variable to zero.
	int count = 0;
	// Creating a temporary node called temp that can be traversed instead of head just because we don't want to lose the head.
	struct Node* temp = NULL;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp = head;
	
	while(temp != NULL)
	{
		if(temp->data == x) //This statement checks whenever the data is matched by the key given by us.
		{
			count++;
		}
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
	
	second->data = 2;
	second->next = third;
	
	third->data = 4;
	third->next = fourth;
	
	fourth->data = 5;
	fourth->next = NULL;
	
	//Printing the the count of how many times a given value of 2 occurs in a linked list.
	printf("%d", count(head, 2));
	
		return(0);

}
