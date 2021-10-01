//C program to print pascal's triangle
#include<stdio.h>
int fact(int n)
{
	int i,f=1;
	for(i=1;i<=n;i++)
		f=f*i;
	return f;
}
int combination(int i,int j)
{
	return fact(i)/(fact(j)*fact(i-j));
}
int main()

{
	int n,i,j;
	printf("\nEnter number of rows\n");
	scanf("%d",&n);
	printf("\nPascals Triangle: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
			printf(" ");
		for(j=0;j<=i;j++)
			printf(" %d",combination(i,j));
		printf("\n");
	}
	return 0;
}
