#include <iostream>
using namespace std;
template<class T>

void Qsort(T *arr, int low,int high)
{
    int pivot,i,j,temp;
    if(low < high)
    {
        pivot = arr[low];
        i = low+1;
        j = high;
        while(1)
        {
            while(pivot > arr[i] && i <= high)
                i++;
            while(pivot < arr[j] && j >= low)
                j--;
            if(i < j)
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            else
                break; 
        
        }
        arr[low] = arr[j];
        arr[j] = pivot;
        Qsort(arr,low,j-1);
        Qsort(arr,j+1,high);
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
    Qsort(arr,0,size-1);
    cout<<"\nAfter sorting in ascending order : \n";
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
