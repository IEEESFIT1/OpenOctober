#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define d 256

void rabinKarp(char *text, char *p, int q);

int main() 
{
char text[100],p[100];
int q;
printf("\n Enter the text: ");
fgets(text);
printf("\n Enter the pattern to be searched: ");
fgets(p);
printf("\n Enter the prime number: ");
scanf("%d",&q);
rabinKarp(text,p,q);
return 0;
}

void rabinKarp(char *text, char *p, int q)
{
int m,n,s=0,t=0,h,i,j;
m=strlen(p);
n=strlen(text);
h=pow(d,m-1);
h=h%q;
for(i=0; i<m; i++)
{
s=(d*s+p[i])%q;
t=(d*t+text[i])%q;
}
for(i=0; i<=(n-m); i++)
{
printf("\n t=%d shift=%d",t,i);
if(s==t)
{
for(j=0; j<m; j++)
{
if(text[i+j]!=p[j])
{
printf("\n Spurious hit at shift %d",i);
break;
}
}
if(j==m)
{
printf("\n Pattern is found at valid shift: %d",i);
}
}
if(i<(n - m))
{
t=(d*(t-text[i]*h) + text[i+m]) % q;
if(t<0){
t=t+q;
}
}
}
}

