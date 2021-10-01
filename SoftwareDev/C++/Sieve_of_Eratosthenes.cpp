#include <bits/stdc++.h>
using namespace std;
const int l = 200;
 
int main()
{
    int arr[l] = {0};
    for (int i = 2; i < l; i++)
    {
        for (int j = i * i; j < l; j+=i)
        {
            arr[j - 1] = 1;
        }
    }
    int n;cin>>n;
    assert(n<=l);
    int j=0;
    for (int i = 1; i < l && j<n; i++,j++)
    {
        if (arr[i - 1] == 0){
        	cout << i << " ";
        	j++;
		}       
    }
}
