//Contributed by Kartikey Sharma
//Contributed to OpenOctober
#include <bits/stdc++.h>
using namespace std;

int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll w,h,a,b,m,c;
    cin>>w>>h>>a>>b>>m>>c;
    ll flag1=0,flag2=0;
	ll nea,neb;
	if(w%a==0)
    {
		nea=w/a;
	}
    else{
    	nea=(w/a)+1;
    	flag1=1;
	}
		
	if(h%b==0)
	{
		neb=h/b;
	}
	else
	{
		neb=h/b+1;
		flag2=1;
	}
	ll ans;
	ll req=nea*neb;
	if(req%10==0)
		ans=req/10*m;
	else
	{
		req+=(10-(req%10));
		ans=(req/10)*m;
	}
    if(flag1==1)
    	ans+=c*h;
    if(flag2==1)
    	ans+=c*w;
    	
    	
    cout<<ans<<endl;



	return 0;
}

