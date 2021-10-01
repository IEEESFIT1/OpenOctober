#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	long int n;
	int arr[1000001]={0};
	scanf("%d",&t);
	for(int i=0;i<t;i++){
	   
	    scanf("%ld",&n);
	    arr[n]++;
	    
	}
	 for(int j=0;j<1000001;j++){
	   while(arr[j]>0){
	       printf("\n%ld",j);
	       arr[j]--;
	   }
	}
	return 0;
}
