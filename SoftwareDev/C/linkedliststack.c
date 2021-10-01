#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node * next;

}node;

void display(node *);
node * push(node *);
node * pop(node *);
void peep(node *); 


int main()
{
	int val,ch;
	
	node * top=NULL;
	
	while(1)
	{
		printf("\n 1)PUSH 2)POP 3)DISPLAY 4)PEEP 5)EXIT\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				top=push(top);
				break;
			case 2:
				top=pop(top);
				break;
			case 3:
				display(top);
				break;
			case 4:
				peep(top);
				break;
			case 5:
				exit(0);
				
		
		
		}
		
	
	
	}
	return 0;




}
void display(node * top)
{
	node * ptr;
	ptr=top;
	
	if(ptr==NULL)
	{
		printf("Linked list empty.");
	}
	else
	{
		printf("\nElements of the list are:");
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
	}

}

node * push(node * top)
{
	node * newnode=(node *)malloc(sizeof(node));
	printf("Enter the data:");
	scanf("%d",&newnode->data);
	
	newnode->next=top;
	top=newnode;
	
	return top;


}

node * pop(node * top)
{
	node * ptr;
	if(top==NULL)
	{
		printf("Stack is empty.");
	}
	else
	{
		ptr=top;
		top=ptr->next;
		printf("Popped element is %d",ptr->data);
		free(ptr);
	}
	
	return top;



}
void peep(node * top)
{
	if(top==NULL)
	{
		printf("Stack is empty.");
	
	}
	else
	{
		printf("The element at top is %d",top->data);
	}


}

