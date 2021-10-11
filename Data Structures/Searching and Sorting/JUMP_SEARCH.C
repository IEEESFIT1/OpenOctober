#include <stdio.h>
#include <conio.h>

void main(){
  int a[50];
  int n,x,i,j;
  clrscr();
  printf("\nEnter number of elements: ");
  scanf("%d", &n);
  printf("\nEnter elements of the array: ");
  for (i = 0; i < n; i++) {
    scanf("\n %d", &a[i]);
  }
  printf("\nEnter element to be searched: ");
  scanf("%d", &x);

  for (i=0; i < n; i = i + sqrt(n)){
    if(m[i] <= x){
      for (j=i-sqrt(n); j<i; j++){
        if(m[j] == x){
          break;
        }
      }
    }
  }
  if (m[j] == x)
  printf("\n%d is present at %d",x,j );
  else
  printf("\n%d is not present in the array",x );
  getch();
}
