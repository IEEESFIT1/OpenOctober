/* This program addresses the procedure and code to provide an alternate order merging of two linked lists in a new linked list */
#include <stdio.h>
#include <stdlib.h>

// Defining a structure for a node that has the data(in this question numerical) and the pointer that points to the next node.
struct Node
{
	int data; // Data that is to be stored in the node
	struct Node* next; // A pointer of the type struct Node* which points to the next node
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
	printf("\n");
}

//This function finds the length of the linked list.
// Inputs include 1. The head of the linked list
int len(struct Node* head)
{
	if(head == NULL)
	{
		return 0;
	}
	else
	{
		struct Node* temp = head;
		int count = 0;
		while(temp != NULL)
		{
			count = count + 1;
			temp = temp->next;
		}
		return count;
	}
}

// This is the function that inserts a node at a given position:
// Input description
// 1. The head of the linked list which is the main point of reference in a liked list.
// 2. The variable x which is the position where we want to insert the new node.
// 3. The variable n is the value/data we want to store in that node.
struct Node* insert(struct Node* head, int x, int n) // x is the position and n is the number to be inserted
{
	int count;
	struct Node* nn = NULL;
	struct Node* temp = head;
	struct Node* tempy = NULL;
	nn = (struct Node*)malloc(sizeof(struct Node)); // nn is a pointer of the type struct Node* which points to memory of size same
													// as that of struct Node.
	nn->data = n;
	if(x == 0) // If we want to insert in the 1st position
	{
		nn->next = temp;
		head = nn; // Very important step. Previously, I was traversing with head. That will change the pointer location in 
					// the memory
		return head;
	}
	else
	{
		if(x == len(head))
		{
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = nn;
			nn->next = NULL;
			return head;
		}
		else
		{
			for(count = 0; count <= x; count++)
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
			nn->next = temp;
			tempy->next = nn;
			return head;
		}
	}
}

// This is the function that merges two linked lists alternatively.
// Input description
// 1. The head of the 1st linked list.
// 2. The head of the second linked list.
struct Node* alternate(struct Node* head1, struct Node* head2)
{
	int i = 0, count;
	struct Node* head = NULL;
	head = (struct Node*)malloc(sizeof(struct Node));
	head->next = NULL;
	while(head1->next != NULL && head2->next != NULL)
	{
		if(i == 0)
		{
			head->data = head1->data;
			head1 = head1->next;
			i = i+1;
			continue;
		}
		if(i%2 == 1)//This gets executed alternatively.
		{
			head = insert(head, i, head2->data);
			head2 = head2->next;
			i = i+1;
		}
		else
		{
			head = insert(head, i, head1->data);
			head1 = head1->next;
			i = i+1;
		}
	}
	count = 0;
	if(head1->next == NULL)// If the linked list 1 gets exhausted
	{
		while(head2->next != NULL)
		{	
			if(count == 1)
			{
				head = insert(head, i, head1->data);
				i = i+1;
			}
			head = insert(head, i, head2->data);
			head2 = head2->next;
			i = i+1;
			count++;
		}
		head = insert(head, i, head2->data);
	}
	else// If the second linkedlist gets exhausted.
	{
		count = 0;
		if(head2->next == NULL)
		{
			while(head1->next != NULL)
			{	
				if(count == 1)
				{
					head = insert(head, i, head2->data);
					i = i+1;
				}
				head = insert(head, i, head1->data);
				head1 = head1->next;
				i = i+1;
				count++;
			}
			head = insert(head, i, head1->data);
		}
	}
	return head;//Returning the final head(merged linked list).
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
	
	//second linked list.
	//Initializing all the nodes with null.
	//There are 5 nodes including the head.
	struct Node* head2 = NULL; 
	struct Node* first2 = NULL;
	struct Node* second2 = NULL;
	struct Node* third2 = NULL;
	struct Node* fourth2 = NULL;
	struct Node* fifth2 = NULL;
	struct Node* headm = NULL;
	
	//Allocating memory to all the nodes using malloc function.
	head = (struct Node*)malloc(sizeof(struct Node));
	first = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));
	
	//Assigning values to the the data contents of all the nodes.

	head->data = 12;
	head->next = first;
	
	first->data = 15;
	first->next = second;
	
	second->data = 19;
	second->next = third;
	
	third->data = 31;
	third->next = fourth;
	
	fourth->data = 37;
	fourth->next = NULL;
	
	//Allocating memory to all the nodes using malloc function.
	head2 = (struct Node*)malloc(sizeof(struct Node));
	first2 = (struct Node*)malloc(sizeof(struct Node));
	second2 = (struct Node*)malloc(sizeof(struct Node));
	third2 = (struct Node*)malloc(sizeof(struct Node));
	fourth2 = (struct Node*)malloc(sizeof(struct Node));
	fifth2 = (struct Node*)malloc(sizeof(struct Node));
	
	//Assigning values to the the data contents of all the nodes.

	head2->data = 13;
	head2->next = first2;
	
	first2->data = 18;
	first2->next = second2;
	
	second2->data = 23;
	second2->next = third2;
	
	third2->data = 27;
	third2->next = fourth2;
	
	fourth2->data = 28;
	fourth2->next = fifth2;
	
	fifth2->data = 34;
	fifth2->next = NULL;
	
	// Printing the linked lists separetely.
	printll(head);
	printll(head2);
	headm = alternate(head, head2);
	printll(headm);
}
