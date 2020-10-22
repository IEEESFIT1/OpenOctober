/* Program for evaluation of Postfix Expression
* using Stack ADT- Array in C
*
*  @author Pranav Yadav
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 50
// size of stack should be predefined in source itself

float postfix_eval[size];
char postfix[size];
int top = -1;

/* push() is used to insert an Element
   at the top of the stack
*/
void push(float val)
{
	if (top == size - 1)
	{
		printf("\nStack Overflow !!\n");
	}
	else
	{
		top++;
		postfix_eval[top] = val;
	}
}

/* pop() is used to delete an element from stack ADT */
float pop()
{

	if (top == -1)
		return 0.0;
	else
	{
		return postfix_eval[top--];
	}
}

/* evaluate() is used to evaluate the
   postfix expression entered by user
*/
void evaluate()
{
	int i = 0;
	float a, b, temp, val;

	while (postfix[i] != '\0')
	{
	  /*isalpha() is a predefined function in ctype.h library, 
	    which is used to check whether a character
	    is alphabet or not
	  */
		if (isalpha(postfix[i]))
		{
			printf("\nEnter value of %c : ", postfix[i]);
			scanf("%f", &val);
			
			push(val);
			
		}
		else
		{
			b = pop();
			a = pop();
			switch (postfix[i])
			{
			case '+':
				temp = a + b;
				push(temp);
				break;
			case '-':
				temp = a - b;
				push(temp);
				break;
			case '*':
				temp = a * b;
				push(temp);
				break;
			case '/':
				temp = a / b;
				push(temp);
				break;
			case '%':
				temp = (int)a % (int)b;
				push(temp);
				break;
			}
		}
		
		i++;
	}
}

int main()
{
	int choice;
	float total;
	
	/* loop used to repeatedly get input from user and 
	  to drive the menu driven program
	*/
	while (1)
	{
		printf("\n\t\tMenu\n1. Evaluate Postfix Expression\n2. Exit\n");
		printf("———————————————————————");
		printf("\nEnter your choice : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter Postfix expression : ");
			//getchar(); // It is compiler specific
			
			fgets(postfix,45,stdin);
			
			printf("\nPostfix Expression : ");
			printf("%s\n", postfix);
			
			evaluate();
			
			total = postfix_eval[top];
			
			printf("\nPostfix Evaluation = %.2f\n", total);
			break;
		case 2:
			exit(0);
		default:
			printf("Invalid choice!!\n");
		}
	}
	return 0;
}