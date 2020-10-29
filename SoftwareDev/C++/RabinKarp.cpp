/*
 * C++ Program to Implement Rolling Hash
 */
#include <iostream>
#include <string>
using namespace std;
const unsigned PRIME_BASE = 257;
const unsigned PRIME_MOD = 1000000007;
unsigned hash(const string& s)
{
    long long ret = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ret = ret * PRIME_BASE + s[i];
        ret %= PRIME_MOD;
    }
    return ret;
}
int rabin_karp(const string& needle, const string& haystack)
{
    long long hash1 = hash(needle);
    long long hash2 = 0;
    long long power = 1;
    for (int i = 0; i < needle.size(); i++)
        power = (power * PRIME_BASE) % PRIME_MOD;
    for (int i = 0; i < haystack.size(); i++)
    {
        hash2 = hash2*PRIME_BASE + haystack[i];
        hash2 %= PRIME_MOD;
    	if (i >= needle.size())
    	{
            hash2 -= power * haystack[i-needle.size()] % PRIME_MOD;
            if (hash2 < 0)
                hash2 += PRIME_MOD;
        }
    	if (i >= needle.size()-1 && hash1 == hash2)
            return i - (needle.size()-1);
    }
    return -1;
}
int main()
{
    string s1,s2;
    cout<<"Enter Original String: ";
    getline(cin,s1);
    cout<<"Enter String to find: ";
    cin>>s2;
    if(rabin_karp(s2, s1) == -1)
        cout<<"String not found"<<endl;
    else
        cout<<"String "<<s2<<" found at position "<<rabin_karp(s2, s1)<<endl;
        return 0;
}
