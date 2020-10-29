// Contributed by Kartikey Sharma
// Contributed to OpenOctober
#include <bits/stdc++.h> 
using namespace std; 
  
void merge(int gArray[], int low, int mid1,  
           int mid2, int high, int destArray[])  
{  
    int i = low, j = mid1, k = mid2, l = low;  
    while ((i < mid1) && (j < mid2) && (k < high))  
    {  
        if(gArray[i] < gArray[j]) 
        { 
            if(gArray[i] < gArray[k]) 
            { 
                destArray[l++] = gArray[i++]; 
            } 
            else
            { 
                destArray[l++] = gArray[k++]; 
            } 
        } 
        else
        { 
            if(gArray[j] < gArray[k]) 
            { 
                destArray[l++] = gArray[j++]; 
            } 
            else
            { 
                destArray[l++] = gArray[k++]; 
            } 
        } 
    }  
    while ((i < mid1) && (j < mid2))  
    {  
        if(gArray[i] < gArray[j]) 
        { 
            destArray[l++] = gArray[i++]; 
        } 
        else
        { 
            destArray[l++] = gArray[j++]; 
        } 
    }  
    while ((j < mid2) && (k < high))  
    {  
        if(gArray[j] < gArray[k]) 
        { 
            destArray[l++] = gArray[j++]; 
        } 
        else
        { 
            destArray[l++] = gArray[k++]; 
        }  
    }  
    while ((i < mid1) && (k < high))  
    {  
        if(gArray[i] < gArray[k]) 
        { 
            destArray[l++] = gArray[i++]; 
        } 
        else
        { 
            destArray[l++] = gArray[k++]; 
        }  
    }  
    while (i < mid1)  
        destArray[l++] = gArray[i++];   
    while (j < mid2)  
        destArray[l++] = gArray[j++];   
    while (k < high)  
        destArray[l++] = gArray[k++];  
}  

void mergeSort3WayRec(int gArray[], int low, 
                      int high, int destArray[])  
{  
    if (high - low < 2)  
        return;  
    int mid1 = low + ((high - low) / 3);  
    int mid2 = low + 2 * ((high - low) / 3) + 1;  
    mergeSort3WayRec(destArray, low, mid1, gArray);  
    mergeSort3WayRec(destArray, mid1, mid2, gArray);  
    mergeSort3WayRec(destArray, mid2, high, gArray);  
    merge(destArray, low, mid1, mid2, high, gArray);  
} 
  
void mergeSort3Way(int gArray[], int n)  
{  
    if (n == 0)  
        return;   
    int fArray[n];  
    for (int i = 0; i < n; i++)  
        fArray[i] = gArray[i];  
    mergeSort3WayRec(fArray, 0, n, gArray); 
    for (int i = 0; i < n; i++)  
        gArray[i] = fArray[i];  
}  
  
int main() 
{ 
    int data[] = {45, -2, -45, 78, 30,  
                 -42, 10, 19, 73, 93}; 
    mergeSort3Way(data,10); 
    cout << "After 3 way merge sort: \n"; 
    for (int i = 0; i < 10; i++) 
    { 
        cout << data[i] << " "; 
    } 
    return 0; 
} 
