#include <iostream>
using namespace std; 

int gcd(int a, int b) 
{ 
	if (a == 0) 
		return b; 
	return gcd(b % a, a); 
} 
 
int phi(unsigned int n) 
{ 
	unsigned int result = 1; 
	for (int i = 2; i < n; i++) 
		if (gcd(i, n) == 1) 
			result++; 
	return result; 
} 

int main() 
{ 
	int n; 
	for (n = 1; n <= 10; n++) 
		cout << "phi("<<n<<") = " << phi(n) << endl; 
	return 0; 
} 

