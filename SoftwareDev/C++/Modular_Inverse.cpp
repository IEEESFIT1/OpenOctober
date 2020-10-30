#include<iostream> 
using namespace std; 

int modInverse(int a, int m) 
{ 
	a = a%m; 
	for (int x=1; x<m; x++) 
	if ((a*x) % m == 1) 
		return x; 
} 

int main() 
{ 
	int a = 3, m = 11; 
	cout << modInverse(a, m); 
	return 0; 
} 

