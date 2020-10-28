#include<stdio.h>
int main(){
long	int t,i,a[100000],n,c,j,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld",&n);
		c=n;
		p=0;
		for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]<=a[j])
				{p=p+1;
				c=c+p;
			//	printf("%d %d\n",i,j);
					break;
				}
				else
				{
					p=0;
				break;
			}
			
			}
		}
		printf("%ld\n",c);
	}
	return 0;
}
