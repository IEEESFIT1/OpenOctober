#include"bits/stdc++.h"
typedef  long long int ll;
using namespace std;
void solve()
{
    long long int x,y; cin>>x>>y; ll ans=-1; 
    for(unsigned long long  i=1;i*x<=1e18;i*=10ll)
    {
      ll a=i*x; ll rem=a%y;
      if(rem!=0) rem=y-rem;
      if (rem<i and a+rem<=1e18)
      {
        ans=a+rem; break;
      }
    }
    cout<<ans<<"\n";
}
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin); 
  //freopen("output.txt","w",stdout); 
  #endif
  ios_base::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int t; cin>>t; 
  while(t--)
  {
    solve(); 
  }
  return 0; 
}
