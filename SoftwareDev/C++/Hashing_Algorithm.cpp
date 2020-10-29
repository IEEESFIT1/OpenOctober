// Contributed by Kartikey Sharma
// Contributed to OpenOctober
#include <bits/stdc++.h>
using namespace std;

long long Hash(string const& str)
{
    // P and M
    int p = 31;
    int m = 1e9 + 9;
    long long power_of_p = 1;
    long long hash_val = 0;
    
    for (int i = 0; i < str.length(); i++) {
        hash_val
            = (hash_val
               + (str[i] - 'a' + 1) * power_of_p)
              % m;
        power_of_p
            = (power_of_p * p) % m;
    }
    return hash_val;
}
 
int main()
{
	string s1,s2;
	cin>>s1>>s2;
    cout << "Hash of '" << s1 << "' = "<< Hash(s1)<<endl;
    cout << "Hash of '" << s2 << "' = "<< Hash(s2);
}
