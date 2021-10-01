//Contributed by Kartikey Sharma
//Contributed to OpenOctober
#include<bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long c,n,p,w;
  	cin>>c>>n>>p>>w;
  	long long pac[n],filled=0,i,j,tables=0;
  	memset(pac,0,sizeof(pac));
  	long long remain = w,nt;
  	if(w<c)
    	cout<<"0";
  	else
  	{
    	for(i=0;i<n;i++)
      	{
        	if(w-filled >=p)
          	{
            	pac[i] = p;
            	filled +=p;
          	}
          	else
          	{
            	pac[i] = w - filled;
	            filled = w;
	        }
	    }
	    for(i=n-1;i>=0;i--)
	    {
	    	nt=0;
	      	if(pac[i]>c || remain<c)
	        	break;
	      	else
      		{
        		nt += pac[i];
          		for(j=i-1;j>=0;j--)
          		{
            		if(nt==c)
              			break;
            		else
            		{
              			if(pac[j]<c-nt)
              			{
                			pac[j]=0;
                			nt+=pac[j];
              			}
              			else
              			{
                			pac[j] -= c - nt;
                			nt = c;
              			}
            		}
          		}
          	tables++;
          	remain-=c;
      	}
    }
    cout<<tables;
  }


  return 0;
}

