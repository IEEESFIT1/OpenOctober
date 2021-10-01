//Contributed by Kartikey Sharma
//Contributed to OpenOctober
#include <iostream>
using namespace std;

int main() 
{
    int n,cb,cp;
    cin>>n>>cb>>cp;
    long long sumb=0,sump=0;
    int a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        sumb+=a;
        sump+=b;
    }
    int fir,sec;
    if(sumb%10==0)
        fir=sumb/10;
    else
        fir=sumb/10 +1;
    
    if(sump%10==0)
        sec= sump/10;
    else
        sec=sump/10 +1;
    
    cout<<fir*cb + sec*cp;
    return 0;
}
