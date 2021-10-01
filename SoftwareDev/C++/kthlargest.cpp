#include <algorithm> 
#include <iostream> 
using namespace std; 
int kthSmallest(int arr[], int n, int k) 
{
    sort(arr, arr + n);  
    return arr[k - 1]; 
} 
int main() 
{ 
    int arr[10],k,n,i;
cout<<"size of array";
cin>>n;
for(i=0;i<n;i++)
{
cin>>arr[i];
}
cout<<"enter k";
cin>>k;
cout << "K'th smallest element is " << kthSmallest(arr, n, k); 
return 0; 
}
