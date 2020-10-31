#include<bits/stdc++.h> 
using namespace std; 
#define MAX 500 

int lookup[MAX][MAX]; 

struct Query 
{ 
	int L, R; 
}; 

void preprocess(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		lookup[i][i] = i; 

	for (int i=0; i<n; i++) 
	{ 
		for (int j = i+1; j<n; j++) 
			if (arr[lookup[i][j - 1]] < arr[j]) 
				lookup[i][j] = lookup[i][j - 1]; 
			else
				lookup[i][j] = j; 
	} 
} 

void RMQ(int arr[], int n, Query q[], int m) 
{  
	preprocess(arr, n); 
	for (int i=0; i<m; i++) 
	{ 
		int L = q[i].L, R = q[i].R; 
		cout << "Minimum of [" << L << ", "
			<< R << "] is " << arr[lookup[L][R]] << endl; 
	} 
} 

int main() 
{ 
	int a[] = {7, 2, 3, 0, 5, 10, 3, 12, 18}; 
	int n = sizeof(a)/sizeof(a[0]); 
	Query q[] = {{0, 4}, {4, 7}, {7, 8}}; 
	int m = sizeof(q)/sizeof(q[0]); 
	RMQ(a, n, q, m); 
	return 0; 
} 

