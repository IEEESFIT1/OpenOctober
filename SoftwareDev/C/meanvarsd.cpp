#include<stdio.h>
#include<math.h>
int main()
{ int i,n;
   float std_dev,sum=0,sumsqr=0,mean,value,variance=0.0,a[100];
   printf("Enter value of n : ");
   scanf("%d",&n);
   printf("\nEnter numbers : ");
   for(i=0;i<n;i++)
   { printf("\nNumber %d : ",i+1);
      scanf("%f",&a[i]);
      sum=sum+a[i];
   }
   mean=sum/n;
   sumsqr=0;
   for(i=0;i<n;i++)
   { value=a[i]-mean;
     sumsqr=sumsqr+value*value;
    }
     variance=sumsqr/n;
     std_dev=sqrt(variance);
     printf("\nMean of %d numbers = %f\n",n,mean);
     printf("\nVariance of %d numbers = %f\n",n,variance);
     printf("\nStandard deviation of %d numbers = %f\n",n,std_dev);
     return 0;
}
