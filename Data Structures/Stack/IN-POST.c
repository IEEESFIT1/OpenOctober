#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char st[MAX];
int top = -1;
void push(char);
char pop();
void InfixtoPostfix(char source[], char target[]);
int getPriority(char);

void main() {
    char infix[100], postfix[100];
    clrscr();
    printf("\n Enter the infix expression : ");
    fgets(infix);
    InfixtoPostfix(infix, postfix);
    printf("\n The corresponding postfix expression is : ");
    puts(postfix);
    getch();
}
void InfixtoPostfix(char source[], char target[]) {
    int i = 0, j = 0;
    char x;
    strcat(source, ")");
    push('(');
    while (source[i] != '\0') {
        if (source[i] == '(') {
            push(source[i]);
        } else if (isdigit(source[i]) || isalpha(source[i])) {
            target[j] = source[i];
            j++;
        } else if (source[i] == '+' || source[i] == '-' || source[i] == '*' ||
            source[i] == '/' || source[i] == '%') {
            while (getPriority(st[top]) >= getPriority(source[i])) {
                x = pop();
                target[j] = x;
                j++;
            }
            push(source[i]);
        } else if (source[i] == ')') {
            while (st[top] != '(') {
                x = pop();
                target[j++] = x;
            }
            pop();
        } else {
            printf("\n INCORRECT ELEMENT IN EXPRESSION");
            exit(1);
        }
        i++;
    }
}

int getPriority(char op) {
    if (op == '/' || op == '*' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void push(char val) {
    if (top == MAX - 1)
        printf("\n STACK OVERFLOW");
    else {
        top++;
        st[top] = val;
    }
}

char pop() {
    char val = ' ';
    if (top == -1)
        printf("\n STACK UNDERFLOW");
    else {
        val = st[top];
        top--;
    }
    return val;
}
