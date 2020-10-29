//Contributed by Kartikey Sharma
//Contributed to OpenOctober
#include <bits/stdc++.h>
using namespace std;

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
	while(t--){
		int a,b,c,d;
		cin>>a>>b>>c;
		ll temp=a;
		vector<int> ans;
		while(temp--)
		{
			cin>>d;
			ans.pb(d);
		}
		sort(all(ans));
		ll res=0;
		int i=0;
		if(c==0)
		{
		    res=b*a;
		    cout<<res<<endl;continue;
		}
		while(c>0)
		{
			res+=(b-ans[i]);
			i++;c--;									
		}
		res+=accumulate(ans.begin()+i,ans.end(),0);
		cout<<res<<endl;
	}
	return 0;
}

