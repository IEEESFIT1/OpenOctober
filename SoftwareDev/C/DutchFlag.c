// Implement Dutch FLag problem in C.
#include <stdio.h> 
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
void DutchFlag(int a[], int n) 
{ 
    int l = 0; 
    int h = n - 1; 
    int m = 0; 
    while (m <= h) { 
        switch (a[m]) { 
        case 0: 
            swap(&a[l++], &a[m++]); 
            break; 
        case 1: 
            m++; 
            break; 
        case 2: 
            swap(&a[m], &a[h--]); 
            break; 
        } 
    } 
} 
int main() 
{   
    int n;
    scanf("%d",&n);
    int a[n] ; 
    for(int i = 0 ; i<n ;i++)
        scanf("%d",&a[i]);
    DutchFlag(a,n); 
    for(int i = 0 ; i<n ;i++)
        printf("%d ",a[i]);
    printf("\n"); 
    return 0; 
} 
