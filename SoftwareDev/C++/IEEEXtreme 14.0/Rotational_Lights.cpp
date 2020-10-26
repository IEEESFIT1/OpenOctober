//Contributed by Kartikey Sharma
//Contributed to OpenOctober
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string rotate(string s, long long d)
{
	reverse(s.begin(), s.begin()+d);
	reverse(s.begin()+d, s.end());
	reverse(s.begin(), s.end());

  return s;
}
string concat(string a, long long b)
{
    string s2 = to_string(b);
    string s = a + s2;

    return s;
}
int main()
{
  	long long i,n,t,j,count=0;
  	cin>>n>>t;
  	long long num[n], a[t]={0};
  	string num_str;
  	for(i = 0; i<n; i++)
      	cin>>num[i];
  	for(i=0;i<n;i++)
     	a[num[i]]=1;
  	for(j=0;j<t;j++)
    	num_str = concat(num_str,a[j]);
	long long size1 = num_str.length();
  	string str2[size1];
  	for(i=0;i<size1;i++)
    	str2[i] = rotate(num_str, num_str.length()-i);
  	for(i=0;i<size1;i++)
    	for(j=i+1;j<size1;j++)
    	{
        	if(str2[i].compare(str2[j])== 0)
        	{
          		count++;
        	}
    	}
  	cout<<size1-count-1;
  	return 0;
}

