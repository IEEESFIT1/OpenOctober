#include<stdio.h>
#include<string.h>

char txt[100],p[100];
int m,n,lps[100],j=0,i=0,count=0,a=0;
void computeLPSarray()
{
  int len=0,i;
  lps[0]=0;
  i=1;
  while(i<m)
  {
   if(p[i]==p[len])
   {
	   len++;
	   lps[i]=len;
	   i++;
   }
   else
   {
	   if(len!=0)
	     len =lps[len-1];
	   else
	   {
	     lps[i]=0;
	     i++;
	   }
	}

  }
  printf("The prefix array: \n");
  printf("|");
  for(i=0;i<m;i++)
  	printf(" %d |",lps[i]);
  printf("\n");
}
void KMPsearch()
{
  int j=0,i=0;
  m=strlen(p);
  n=strlen(txt);
  computeLPSarray();
  while(i<n)
  {
  if(p[j]==txt[i])
  {
    j++;
    i++;
  }

  if (j==m)
  {
    printf("Pattern is found at index: %d\n",i-j);
    j=lps[j-1];
	count=count+1;
	a=count;
  }
  else if(p[j]!=txt[i])
  {
    if(j!=0)
   j=lps[j-1];
    else
   i=i+1;
  }
  }
  printf("Total number of valid shifts: %d",a);
}



int main()
{
printf("\nEnter the text: ");
 fgets(txt);
 printf("Enter the pattern: ");
 fgets(p);
 KMPsearch();
 return 0;
}

