#include <iostream> 
using namespace std; 

int getSum(int Fenwick[], int index) 
{ 
	int sum = 0; 
	index = index + 1; 
	while (index>0) 
	{ 
		sum += Fenwick[index]; 
		index -= index & (-index); 
	} 
	return sum; 
} 

void updateBIT(int Fenwick[], int n, int index, int val) 
{ 
	index = index + 1; 

	while (index <= n) 
	{ 
	Fenwick[index] += val; 
	index += index & (-index); 
	} 
} 

int *constructBITree(int arr[], int n) 
{ 
	int *Fenwick = new int[n+1]; 
	for (int i=1; i<=n; i++) 
		Fenwick[i] = 0; 

	for (int i=0; i<n; i++) 
		updateBIT(Fenwick, n, i, arr[i]); 

	return Fenwick; 
} 

int main() 
{ 
	int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9}; 
	int n = sizeof(freq)/sizeof(freq[0]); 
	int *Fenwick = constructBITree(freq, n); 
	cout << "Sum of elements in arr[0..5] is "
		<< getSum(Fenwick, 5); 

	freq[3] += 6; 
	updateBIT(Fenwick, n, 3, 6);

	cout << "\nSum of elements in arr[0..5] after update is "
		<< getSum(Fenwick, 5); 

	return 0; 
} 

