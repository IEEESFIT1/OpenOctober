//Contributed by Kartikey Sharma
//Contributed to OpenOctober
#include <bits/stdc++.h> 
using namespace std; 

long long solve(string s) 
{
    long long n=s.size();
	long long m=0;
    vector<vector<long long> > dp(n, vector<long long> (n));
    for(long long i=0;i<n;i++) 
		dp[i][i]=1;   
    for (long long cl=2; cl<=n; cl++) 
	{
        for (long long i=0; i<n-cl+1; i++)
		{
            long long j = i+cl-1; 
            if (s[i] == s[j] && cl == 1) 
				dp[i][j] = 1; 
            else if (s[i] == s[j]) 
				dp[i][j] = dp[i+1][j-1] + 2; 
            else 
				dp[i][j] = max(dp[i][j-1], dp[i+1][j]-1); 
        } 
    }
    for(long long i=0;i<n-1;i++)
	{
       m = max( m, (long long)dp[0][i]+ (long long)dp[i+1][n-1] );
    } 
    return m;
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int ans=solve(s);
		cout<<ans<<endl;
	}
    return 0; 
} 
