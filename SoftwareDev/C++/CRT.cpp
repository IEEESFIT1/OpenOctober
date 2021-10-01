//C++ program on Chinese Remainder Theorem
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}
bool check(int b[], int n)
{
    for (int x = 0; x < n; x++)
    {
        for (int y = x + 1; y < n; y++)
            if (gcd(b[x], b[y]) != 1)
                return true;
    }
    return false;
}
int evaluate(int a[], int b[], int n)
{
    int Minv[n];
    int q, r, r1, r2, t, t1, t2;
    int total = 1;
    for (int k = 0; k < n; k++)
        total *= b[k];
    for (int k = 0; k < n; k++)
    {
        r1 = b[k];
        r2 = total / b[k];
        t1 = 0;
        t2 = 1;
        while (r2 > 0)
        {
            q = r1 / r2;
            r = r1 - q * r2;
            r1 = r2;
            r2 = r;
            t = t1 - q * t2;
            t1 = t2;
            t2 = t;
        }
        if (r1 == 1)
            Minv[k] = t1;
        if (Minv[k] < 0)
            Minv[k] = Minv[k] + b[k];
    }
    int x = 0;
    for (int k = 0; k < n; k++)
        x += (a[k] * total * Minv[k]) / b[k];
    return x%total;
}
int main()
{
    int n;
    cin>>n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin>>a[i]>>b[i];
    if (!check(b, n))
        cout<<"x = "<<evaluate(a, b, n)<<endl;
    else
        cout<<"The given equations has no solutions."<<endl;
    return 0;
}
