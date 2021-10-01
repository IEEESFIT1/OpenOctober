//Mean and Median Calculation in C
#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b) 
{
   return( *(int*)a - *(int*)b );
}
int main()
{
    int n;
    printf("Enter the size of the array ");              
    scanf("%d",&n);
    int arr[n];
    int i;
    int sum = 0;
    int mean;
    int median;
    printf("\nEnter array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    mean = sum/n;
    qsort(arr,n,sizeof(int),cmp);           
    if(n%2 == 0)
        median = (arr[n/2-1]+arr[n/2])/2;
    else median = arr[n/2];
    printf("Mean : %d \nMedian : %d", mean, median);
    return 0;
}
