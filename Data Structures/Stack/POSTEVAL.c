#include <stdio.h>
#include <string.h>
#include <conio.h>
#define size 50
float stack[size];

int top = -1;
void push(float val);
float pop();
float peep();
void display();

float evaluate(char * );

int main() {
    float ans;
    char postfix[50];
    int len = 0;
    clrscr();
    printf("\nEnter the postfix expression: ");
    gets(postfix);
    printf("\nThe postfix expression is: %s", postfix);
    ans = evaluate(postfix);
    printf("\nAnswer after evaluation = %0.2f", ans);
    getch();
}

float evaluate(char postfix[50]) {
    int i = 0;
    float val;
    float a, b;
    while (postfix[i] != '\0') {
        if (isalpha(postfix[i])) {
            printf("\nEnter the value of %c: ", postfix[i]);
            scanf("%f", & val);
            push(val);
        } else {
            b = pop();
            a = pop();
            switch (postfix[i]) {
            case '+':
                val = (a + b);
                break;
            case '-':
                val = (a - b);
                break;
            case '*':
                val = (a * b);
                break;
            case '/':
                val = (a / b);
                break;
            }

            push(val);
        }
        i++;
    }
    return pop();
}

void push(float val) {
    if (top == size - 1) {
        printf("\nStack Full!!\n");
    } else {
        top++;
        stack[top] = val;
    }
}

float pop() {
    if (top == -1) {
        printf("\nStack Empty!!\n");
        return -1;
    } else {
        return (stack[top--]);
    }
}

float peep() {
    if (top == -1) {
        printf("\nStack Empty!!\n");
        return -1;
    } else {

        return stack[top];
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("\nStack Empty!!\n");
    } else {
        printf("\nStack elements are:\n");
        for (i = top; i >= 0; i--) {
            printf("%0.2f\n", stack[i]);
        }
    }
}
