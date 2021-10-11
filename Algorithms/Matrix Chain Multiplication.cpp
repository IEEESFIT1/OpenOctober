#include <bits/stdc++.h> 
using namespace std; 

/* A naive recursive implementation that simply follows 
the above optimal substructure property */
class MatrixChainMultiplication 
{ 
	// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n 
	static int MatrixChainOrder(int p[], int i, int j) 
	{ 
		if (i+1 == j) 
			return 0; 
			
		int min = Integer.MAX_VALUE; 

		// place parenthesis at different places between first 
		// and last matrix, recursively calculate count of 
		// multiplications for each parenthesis placement and 
		// return the minimum count 
		for (int k=i+1; k<j; k++) 
		{ 
			int count = MatrixChainOrder(p, i, k) + 
						MatrixChainOrder(p, k, j) + 
						p[i]*p[k]*p[j]; 

			if (count < min) 
				min = count; 
		} 

		// Return minimum count 
		return min; 
	} 

	// Driver program to test above function 
	public static void main(String args[]) 
	{ 
		int arr[] = new int[]  {40, 20, 30, 10, 30};
		int n = arr.length; 
		System.out.println("Minimum number of multiplications is "+ 
						MatrixChainOrder(arr, 0, n-1)); 

	} 
} 