#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

typedef struct node {
    int data;
    struct node * next;
}
node;

void display(node * );
node * insert_beg(node * );
node * insert_end(node * );
node * delete_beg(node * );
node * delete_end(node * );

void main() {
    struct node * start = NULL;
    int ch;
    clrscr();
    while (1) {
        printf("\nMenu:\t1.Insert_beg\t2.Insert_end\t3.Delete_beg\t4.Delete_end\t5.Exit");
        printf("\nEnter your choice:");
        scanf("%d", & ch);
        switch (ch) {
        case 1:
            start = insert_beg(start);
            display(start);
            break;
        case 2:
            start = insert_end(start);
            display(start);
            break;
        case 3:
            start = delete_beg(start);
            display(start);
            break;
        case 4:
            start = delete_end(start);
            display(start);
            break;
        case 5:
            exit(0);
        }
    }
}

void display(node * start) {
    node * ptr;
    ptr = start;
    if (ptr == NULL) {
        printf("\nEmpty List");
        return;
    }
    printf("Elements of the list:\n");
    while (ptr -> next != start) {
        printf("\t%d", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\t%d", ptr -> data);
    printf("\n");
}

node * insert_beg(node * start) {
    node * ptr;
    node * newnode = malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d", & newnode -> data);
    ptr = start;
    if (start == NULL) {
        start = newnode;
        newnode -> next = start;
        return start;
    }
    while (ptr -> next != start) {
        ptr = ptr -> next;
    }
    ptr -> next = newnode;
    newnode -> next = start;
    start = newnode;
    return start;
}

node * insert_end(node * start) {
    node * ptr;
    node * newnode = (node * ) malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d", & newnode -> data);
    if (start == NULL) {
        start = newnode;
    } else {
        ptr = start;
        while (ptr -> next != start) {
            ptr = ptr -> next;
        }
        ptr -> next = newnode;
    }
    newnode -> next = start;
    return start;
}

node * delete_beg(node * start) {
    node * ptr;
    if (start == NULL)
        printf("List empty!!Cant delete");
    else {
        ptr = start;
        while (ptr -> next != start) {
            ptr = ptr -> next;
        }
        if (ptr == start) {
            start = NULL;
        } else {
            ptr -> next = start -> next;
            ptr = start;
            start = start -> next;
        }
        free(ptr);
    }
    return start;
}

node * delete_end(node * start) {
    node * ptr, * preptr;
    if (start == NULL)
        printf("List empty!!Cant delete");
    else {
        ptr = start;
        while (ptr -> next != start) {
            preptr = ptr;
            ptr = ptr -> next;
        }
        if (ptr == start) {
            start = NULL;
        } else {
            preptr -> next = start;
        }
        free(ptr);
    }
    return start;
}
