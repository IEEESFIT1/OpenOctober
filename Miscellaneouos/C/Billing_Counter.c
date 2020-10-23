/* Program used by salesman at Billing
*  Counter in a supermarket, using Queue as Array
*
*  @author Pranav Yadav
*/

#include<stdio.h>
#include<stdlib.h>
#define size 15
// size must be predefined in source itself

// structure to store item details
typedef struct
{
	int item_id;
	char item_name[30];
	float price;
	int quantity;
} bill_queue;

// array of items, size is predefined
bill_queue bq[size];
int front = -1;
int rear = -1;
float total_amount = 0.0;

// insert() func is used to add items to list
void insert()
{
	if (rear == size - 1)
		printf("Queue Overflow !!!\n");
	else
	{
		if (front == -1)
		{
			front = 0;
		}
		
		// rear must be incremented before inserting new item to the list
		rear++;
		printf("Enter Item ID : ");
		scanf("%d", &bq[rear].item_id);
		printf("\nEnter Item Name : ");
		//getchar(); it is compiler specific
		fgets(bq[rear].item_name,30,stdin);
		
		printf("\nEnter Price of the Item : ");
		scanf("%f", &bq[rear].price);
		printf("\nEnter Quantity of Items : ");
		scanf("%d", &bq[rear].quantity);
		
		/*total_amount is calculated for every new inserted item 
		 and added to the previous bill amount
		 */
		total_amount += (bq[rear].price * bq[rear].quantity);
	}
}

/* delete() func is used to delete the
 items from front of the list
*/
void delete()
{
	if (front == -1 || front > rear)
	{
		printf("Your Cart is Empty: No items in Queue !!\n");
	}
	else
	{
		printf("Item deleted from queue is :-\n");
		printf("Item ID : %d", bq[front].item_id);
		printf("\nItem Name : %s", bq[front].item_name);

		front++;
		/*front is incremented to as item from front is deleted 
		 such that, front now (points) to next item
		*/
	}
}

// peek() func is used to check item in front of the list
void peek()
{
	if (front == -1 || front > rear)
	{
		printf("No items in Queue !!\n");
	}
	else
	{
		printf("Item at front of queue is :-\n");
		printf("Item ID : %d", bq[front].item_id);
		printf("\nItem Name : %s", bq[front].item_name);
		
	}
}

// display() func is used to display all items present in the list
void display()
{
	int i = 0;
	if (front == -1)
	{
		printf("No items in Queue!!\n");
	}
	else
	{
		printf("List of Items : \n");

		for (i = front; i <= rear; i++)
		{
			printf("Item ID : %d", bq[i].item_id);
			printf("\nItem Name : %s", bq[i].item_name);
			printf("\nPrice of the Item : %.2f", bq[i].price);
			printf("\nEnter Quantity of Items : %d", bq[i].quantity);
			printf("\n");
		}
	}
}

// driver function
int main()
{
	int choice;
	while (1)
	{
		printf("\t\tMenu\n");
		printf("———————————————\n");
		printf("1.Insert an Item \n");
		printf("2.Delete an Item\n");
		printf("3.Display an Item at front of Queue\n");
		printf("4.Display all Items\n");
		printf("5.Quit \n");
		printf("———————————————\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			insert();
			break;
		case 2:
			delete();
			break;
		case 3:
		    peek();
		    break;
		case 4:
			display();
			break;
		case 5:
			printf("\nTotal Bill Amount = %.2f  RS.", total_amount);
			printf("\nYou are Welcome !!\n");
			exit(0);
		default:
			printf("Invalid choice !!\n");
		}
	}

	return 0;
}
