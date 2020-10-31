#include<bits/stdc++.h> 
using namespace std; 

int getSum(int BITree[], int index) 
{ 
	int sum = 0; 
	while (index > 0) 
	{ 
		sum += BITree[index]; 
		index -= index & (-index); 
	} 
	return sum; 
} 

void updateBIT(int BITree[], int n, int index, int val) 
{  
	while (index <= n) 
	{ 
		BITree[index] += val; 
		index += index & (-index); 
	} 
} 

int getInvCount(int arr[], int n) 
{ 
	int invcount = 0; 
	int maxElement = 0; 
	for (int i=0; i<n; i++) 
		if (maxElement < arr[i]) 
			maxElement = arr[i]; 
	int BIT[maxElement+1]; 
	for (int i=1; i<=maxElement; i++) 
		BIT[i] = 0;  
	for (int i=n-1; i>=0; i--) 
	{ 
		invcount += getSum(BIT, arr[i]-1); 
		updateBIT(BIT, maxElement, arr[i], 1); 
	} 

	return invcount; 
} 

int main() 
{ 
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i]; 
	cout << "Number of inversions are : " << getInvCount(arr,n); 
	return 0; 
} 

