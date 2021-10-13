#include<stdio.h>
int n;
int G[10][10];
int X[10];
int m;
char colors[10];

void mColoring(int k)
{
    while(1)
    {
        Next_Value(k);
        if(X[k]==0) { return; }
        if(k==n)
            Write_X();
        else mColoring(k+1);
    }
}

int Next_Value(int k)
{
    int j;
    
    while(1)
    {
        X[k]=(X[k]+1)%(m+1);
        
        if(X[k]==0) return;
        for(j=1;j<=n;j++)
        {
            if((G[k][j]!=0) && (X[k]==X[j]))
                break;
        }
        if(j==(n+1))  return;
    }
}

int Write_X()
{
    int i;
    static int sno=1;
    printf("\nSolution %d : X={",sno++);
    for(i=1;i<=n;i++)
    {
        printf("%c ",colors[X[i]]);
    }
    printf("}");
    
}

int main()
{
    int i,j;
    printf("Enter the no. of nodes: ");
    scanf("%d",&n);
    printf("Enter the number of colors: ");
    scanf("%d",&m);
    printf("Enter the different colors: ");
    for(i=1;i<=m;i++)
        scanf(" %c",&colors[i]);
    printf("Enter the adjanceny matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&G[i][j]);
        }
    for(i=1;i<=n;i++)
        X[i]=0;
        
    mColoring(1);
    
    getch();
    
}

