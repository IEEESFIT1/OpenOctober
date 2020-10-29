#include<stdio.h>
main()
{
int i,j,rows,col,trace=0;
 printf("Enter number of rows and columns of a matrix\n");
 scanf("%d %d",&rows,&col);
int a[rows][col];
 if(rows==col)
 { printf("Enter Matrix elements \n");
    for(i=0;i<rows;i++)
    {
       for(j=0;j<col;j++)
      {
     scanf("%d",&a[i][j]);
      }
    }
    printf("Given /matrix is\n");
        for(i=0;i<rows;i++)
         {
         for(j=0;j<col;j++)
         {
           printf("%d\t",a[i][j]);
           }
    printf("\n");
           }
         for(i=0;i<rows;i++)
         {
          trace+=a[i][i];
         }
       printf("Trace of above matrix is %d\n",trace);
       }
  else
 { printf("Trace is not possible \n");
 }
}
