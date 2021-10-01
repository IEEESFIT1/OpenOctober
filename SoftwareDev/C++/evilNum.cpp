//C++ code to check if number is evil
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, cnt=0;
    cout<<"Enter any number:";
    cin>>n;
    while((n != 1) && (n != 0))
    {
        if((n%2) == 1)
        {
            cnt++;
        }
        n = n/2;
    }
    if(n==1)
    {
        cnt++;
    }
    if((cnt%2) == 0)
    {
        cout<<"It is an evil number"<<endl;
    }
    else
    {
        cout<<"It is not an evil number"<<endl;
    }
    return 0;
}
