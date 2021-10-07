#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include<string.h>
#define MAX 50

void bfs(int adj[][MAX], int visited[], int start) {

    int queue[MAX], rear = -1, front = -1, i;
    queue[++rear] = start;
    visited[start] = 1;
    while (rear != front) {
        start = queue[++front];
        printf("%c-", start + 65);
        for (i = 0; i < MAX; i++) {
            if (adj[start][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }

    }
}

void dfs(int adj[][MAX], int visited[], int start) {
    int stack[MAX];
    int top = -1, i;
    printf("%c-", start + 65);
    visited[start] = 1;
    stack[++top] = start;
    while (top != (-1)) {
        start = stack[top];
        for (i = 0; i < MAX; i++) {
            if (adj[start][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
                printf("%c-", i + 65);
                visited[i] = 1;
                break;
            }
        }
        if (i == MAX)
            top--;
    }
}

void main() {
    int a, n;
    int visited[MAX] = {
        0
    };
    int adj[MAX][MAX], i, j;
    clrscr();
    printf("\nEnter the number of nodes : ");
    scanf("%d", & a);
    printf("\nEnter the adjacency matrix : ");
    for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++) {
            scanf("%d", & adj[i][j]);
        }
    }
    printf("\nEnter the starting node number : ");
    scanf("%d", & n);
    printf("\nDFS traversal is : ");
    dfs(adj, visited, n);

    memset(visited, 0, sizeof(visited));
    printf("\nBFS traversal is: ");
    bfs(adj, visited, n);
    getch();
}
