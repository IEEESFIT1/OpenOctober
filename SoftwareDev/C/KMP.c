#include<stdio.h>
#include<conio.h>
#include<string.h>
char t[100],p[100];
int M ,N ,lps[100],j=0,i=0;
void computeLPSArray()
{
 int len = 0, i;
 lps[0] = 0;
 i = 1;
 while(i < M)
 {
 if(p[i] == p[len])
 {
 len++;
 lps[i] = len;
 i++;
 }
 else
 {
 if( len != 0 )
 len = lps[len-1];
 else
 {
 lps[i] = 0;
 i++;
 }
 }
 }
}
void KMPSearch()
{
 int j=0,i=0;
 M = strlen(p);
 N = strlen(t);
 computeLPSArray();
 while(i < N)
 {
 if(p[j] == t[i])
 {
 j++;
 i++;
 }
 if (j == M)
 {
 printf("Found patttern at index %d \n", i-j);
 j = lps[j-1];
 }
 else if(p[j] != t[i])
 {
 if(j != 0)
 j = lps[j-1];
 else
 i = i+1;
 }
 }
}
void main()
{
clrscr();
printf("\n Enter Text: ");
gets(t);
printf("\n Enter Pattern : ");
gets(p);
KMPSearch();
getch();
}
