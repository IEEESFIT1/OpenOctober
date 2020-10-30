#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

const int MAX = 100000000;
const int LMT = 10000;
bool isprime[MAX];

void sieve()  
{
    memset(isprime, true, sizeof(isprime));

    int i, k, j;
    isprime[1] = false;
    for (i = 4; i <= MAX; i+=2)
    {
        isprime[i] = false;
    }
    for (i = 3; i <= LMT; i+=2)
    {
        if(isprime[i])
            for (j = i*i, k = i<<1; j <= MAX; j+=k)
            {
                isprime[j] = false;
            }
    }
}

int abso(int a)  
{
    return a>0?a:-a;
}
int gcd(int a,int b) 
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int pollard_rho(int n)  
{
    if(n%2==0)
        return 2;

    int x = rand_r(0)%n+1;
    int c = rand_r(0)%n+1;
    int y = x;
    int g = 1;
    while(g==1)
    {
        x = ((x*x)%n + c)%n;    
        y = ((y*y)%n + c)%n;
        y = ((y*y)%n + c)%n;
        g = gcd(abso(x-y),n);
    }
    return g;
}

int factors[MAX/100], total;

void factorize(int n)   
{
    if(n == 1)
        return;

    if(isprime[n])      
    {
        factors[total++] = n;
        return;
    }
    int divisor = pollard_rho(n);   
    factorize(divisor);
    factorize(n/divisor);
}

int main()  
{
    srand(time(NULL));
    sieve();

	int n;
    scanf("%d",&n);

    total = 0;
    factorize(n);

    for (int i = 0; i < total; ++i)
    {
        printf("%d ",factors[i] );
    }
    printf("\n");
	return 0;
}
