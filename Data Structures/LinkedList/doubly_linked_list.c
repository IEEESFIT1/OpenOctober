#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node * next;
    struct node * prev;
}node;

node *doublyLinkedList(node *head, int n) {
    node *p;
    int i, element;

    for (i=0; i<n; i++)
    {
        if (i==0)
        {
            head = (node *) malloc (sizeof(node));
            head->prev = NULL;
            p = head;
        }

        else 
        {
            p->next = (node *) malloc (sizeof(node));
            (p->next)->prev = p;
            p = p->next;
        }
        printf("Enter element %d of the doubly linked list : ",i+1);
        scanf("%d", &element);
        p->val = element;
    }
    p->next = NULL;
    return (head);
} 

void printSpecificElement(node *head, int pos)
{
    int i;
    node *p = head;

    for (i=0; i<pos-1; i++) 
    {
        p = p->next;
    }
    printf("The element at position %d is %d\n", pos, p->val);
    printf("The element before this is %d\n", (p->prev)->val);
    printf("The element after this is %d\n", (p->next)->val);
}

node *printLinkedList(node *head)
{
    node *p = head;
    printf("The elements of the doubly linked list are : \n");
    while (p != NULL) 
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
    return (head);
}

node *printReverseLinkedList(node *head)
{
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    node *tail = p;

    printf("The elements of the doubly linked list in reverse order are : \n");
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->prev;
    }
    printf("\n");
    return (head);
}

node *insertStart(node *head)
{
    int elemins;
    printf("Enter element to be inserted : ");
    scanf("%d", &elemins);

    node *new = (node *) malloc (sizeof(node));
    new->val = elemins;
    new->next = head;
    head->prev = new;
    head = new;

    return (head);
}

void insertEnd(node *head)
{
    node *tail;
    node *p = head;
    int elemins;
    printf("Enter element to be inserted : ");
    scanf("%d", &elemins);

    while (p->next != NULL)
    {
        p = p->next;
    }
    tail = p;

    node *new = (node *) malloc (sizeof(node));
    new->val = elemins;
    new->prev = tail;
    tail->next = new;
    new->next = NULL;
}

void insertMiddle(node *head)
{
    node *p = head;
    int elemins, i, position;
    printf("Enter element to be inserted : ");
    scanf("%d", &elemins);
    printf("Enter position to insert the element at : ");
    scanf("%d", &position);

    node *new = (node *) malloc (sizeof(node));
    new->val = elemins;

    for (i=0; i<position-2; i++)
    {
        p = p->next;
    }
    node *q = p->next;
    p->next = new;
    q->prev = new;
    new->next = q;
    new->prev = p; 
}

node *deleteHead(node *head)
{
    node *p = head;
    node *q = p->next;
    q->prev = NULL;
    head = q;
    free(p);

    return (head);
}

void deleteTail(node *head)
{
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    node *tail = p;
    p = p->prev;
    
    p->next = NULL;
    free(tail);
}

node *deleteMiddle(node *head, int pos)
{
    int i;
    node *p = head;
    for (i=0; i<pos-1; i++)
    {
        p = p->next;
    }

    if (p->next != NULL && p->prev != NULL)
    {
        (p->prev)->next = p->next;
        (p->next)->prev = p->prev;

        free(p);
    }

    else if (p->next == NULL && p->prev != NULL)
    {
        (p->prev)->next = NULL;
        free(p);
    }

    else if (p->next != NULL && p->prev == NULL)
    {
        (p->next)->prev = NULL;
        head = p->next;
        free(p);
    }

    return (head);
}

int main() 
{
    node *head;
    int n, pos, choice;
    char ans = 'y';

    while (ans == 'y')
    {
        printf("MENU : \n");
        printf("1.Create a doubly linked list.\n");
        printf("2.Display the doubly linked list OR display an element of the list.\n");
        printf("3.Insert an element in the doubly linked list.\n");
        printf("4.Delete an element from the doubly linked list.\n");

        printf("Enter your choice : ");
        scanf(" %d", &choice);

        if (choice == 1)
        {
            printf("Enter number of elements in the doubly linked list : ");
            scanf("%d", &n);
            head = doublyLinkedList(head, n);
        }

        else if (choice == 2)
        {
            int choice2;
            printf("\n1.Display the list.\n");
            printf("2.Display in list in reverse order.\n");
            printf("3.Display a specific element in the doubly linked list.\n");

            printf("Enter your choice : ");
            scanf("%d", &choice2);

            if (choice2 == 1)
            {
                printLinkedList(head);
            }

            else if (choice2 == 2)
            {
                printReverseLinkedList(head);
            }

            else if (choice2 == 3)
            {
                printf("Which element do you want to print? : ");
                scanf("%d", &pos);
                printSpecificElement(head, pos);
            }

            else
            {
                printf("ILLEGAL CHOICE !!\n");
            }
        }

        else if (choice == 3)
        {
            int choice3;
            printf("\n1.Insert element in the beginning.\n");
            printf("2.Insert element in the end.\n");
            printf("3.Insert element at a given position.\n");

            printf("Enter your choice : ");
            scanf("%d", &choice3);

            if (choice3 == 1)
            {
                head = insertStart(head);
            }

            else if (choice3 == 2)
            {
                insertEnd(head);
            }

            else if (choice3 == 3)
            {
                insertMiddle(head);
            }
        }

        else if (choice == 4)
        {
            int choice4;
            printf("\n1.Delete element from the beginning (delete the head).\n");
            printf("2.Delete element from the end (delete the tail).\n");
            printf("3.Delete at a given position\n");

            printf("Enter your choice : ");
            scanf("%d", &choice4);

            if (choice4 == 1)
            {
                head = deleteHead(head);
            }

            else if (choice4 == 2)
            {
                deleteTail(head);
            }

            else if (choice4 == 3)
            {
                int position;
                printf("Enter position of element to be deleted : ");
                scanf("%d", &position);
                head = deleteMiddle(head, pos);
            }

            else
            {
                printf("ILLEGAL CHOICE !!\n");
            }
        }
        printf("Do you want to continue? (y/n) : ");
        scanf(" %c", &ans);
    }

    return 0;
}
