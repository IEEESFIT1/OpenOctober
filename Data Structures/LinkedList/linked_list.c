#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

node *linkedList(int n)
{
    int i;
    node *p, *head;

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            head = (node *)malloc(sizeof(node));
            p = head;
        }

        else
        {
            p->next = (node *)malloc(sizeof(node));
            p = p->next;
        }
        printf("Enter element %d of the linked list : ", i + 1);
        scanf("%d", &p->val);
    }

    p->next = NULL;
    return (head);
}

void elementsOfList(node *head)
{
    printf("The elements of the linked list are : \n");
    node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
}

node * insertBeginning(node *head, int element)
{
    node *new = (node *)malloc(sizeof(node));
    new->val = element;
    new->next = head;

    head = new;

    return (head);
}

node *insertEnd(node *head, int element) 
{
    node *p = head;
    node *new = (node *) malloc (sizeof(node));
    new ->val = element;

    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new;
    new->next = NULL;

    return (head);
}

node *insertMiddle(node *head, int element, int pos) 
{
    int i;
    node *p = head;
    node *new = (node *) malloc (sizeof(node));
    new->val = element;

    for (i=0; i<pos-2; i++) {
        p = p->next;
    }
    new->next = p->next;
    p->next = new;

    return (head);
}

node *deleteHead(node *head)
{
    node *p = head;
    head = head->next;
    free(p);

    return (head);
}

void deleteTail(node *head)
{
    node *p = head;

    while ((p->next)->next != NULL)
    {
        p = p->next;
    }
    p->next = NULL;
    free(p->next);
}

node *deleteMiddle(node *head, int pos)
{
    int i;
    node *p = head;

    for (i=0; i<pos-2; i++) 
    {
        p = p->next;
    }
    node *q = p;
    p = p->next;

    q->next = p->next;
    free(p);

    return (head);
}

int main()
{
    int choice, n, begin, end, middle, pos;
    node *head;
    char ans = 'y';

    while (ans=='y')
    {
        printf("MENU : \n");
        printf("1.Create a linked list.\n");
        printf("2.Display the linked list.\n");
        printf("3.Insert an element in the linked list.\n");
        printf("4.Delete an element from the linked list.\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter number of elements in linked list : ");
            scanf("%d", &n);

            head = linkedList(n);
            printf("\nLIST CREATED !!!\n");
        }

        else if (choice == 2)
        {
            elementsOfList(head);
            printf("\n");
        }

        else if (choice == 3)
        {
            int choice3;
            printf("1.\nInsert in the beginning.\n");
            printf("2.Insert in the end.\n");
            printf("3.Insert at a given position.\n");

            printf("Enter your choice : ");
            scanf("%d", &choice3);

            if (choice3 == 1)
            {
                printf("\nNumber to insert in the beginning : ");
                scanf("%d", &begin);
                n++;
                head = insertBeginning(head, begin);
                printf("\nINSERTED ELEMENT AT THE BEGINNING !!\n");
            }
            else if (choice3 == 2)
            {   
                printf("\nNumber to insert in the end : ");
                scanf("%d", &end);
                n++;
                head = insertEnd(head, end);
                printf("\nINSERTED ELEMENT AT THE END !!\n");
            }   
            else if (choice3 == 3)
            {
                printf("\nNumber to insert in the middle : ");
                scanf("%d", &middle);
                printf("\nEnter the position of the element to be inserted into : ");
                scanf("%d", &pos);
                head = insertMiddle(head, middle, pos);
                printf("\nINSERTED ELEMENT AT THE GIVEN POSITION !!\n");
            }

            else
            {
                printf("INVALID CHOICE !!");
            }
        }

        else if (choice == 4)
        {
            int choice4;
            printf("\n1.Delete element from the beginning (delete the head).\n");
            printf("2.Delete element from the end (delete the tail).\n");
            printf("3.Delete at a given position.\n");

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
                int pos;
                printf("Enter position of the element to be deleted : ");
                scanf("%d", &pos);
                head = deleteMiddle(head,pos);
            }

            else
            {
                printf("INVALID CHOICE !!");
            }
        }

        else
        {
            printf("INVALID CHOICE !!\n");
        }

        printf("Do you want to continue? (y/n) : ");
        scanf(" %c", &ans);
    }

    printf("\nTHANK YOU !!!");

    return 0;
}