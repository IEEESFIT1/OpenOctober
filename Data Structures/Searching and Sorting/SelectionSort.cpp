#include <iostream>
using namespace std;

template<class T>
void selectionSort(T *arr, int n)
{
    int i,j,temp,min;
    for(i=0;i<n;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j] < arr[min]) /* Finding minimum element from i+1 to n */
            {
                min = j;
            }
        }
        temp = arr[i]; /* Swapping the minimum element with arr[i] (present array element) */
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int size,i;
    cout<<"Enter the size of the array : ";
    cin>>size;
    int arr[size];
    cout<<"\nEnter "<<size<<" elements : ";
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"\nBefore sorting : \n";
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    selectionSort(arr,size);
    cout<<"\nAfter sorting in ascending order : \n";
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}

/*
    Time complexity 
    
    Best complexity    : O(n^2)
    Average complexity : O(n^2)
    Worst complexity   : O(n^2)
    
    Space complexity   : O(1)
*/

