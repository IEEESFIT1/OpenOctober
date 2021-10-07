#include <stdio.h>

void main()
{
    int a[5],i,n,c=0;
    printf("enter 5 numbers in array\n");
    for (i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nenter number you want to search\t");
    scanf("%d",&n);
    for (i=0;i<5;i++)
    {
        if (a[i]==n)
        {
            printf("\n%d is located at location %d",n,i+1);
            c++;

        }
    }
    if (c==0)
    {
        printf("\n%d is not present",n);
    }
    else
    {
        printf("\n%d is present %d times",n,c);
    }

}
