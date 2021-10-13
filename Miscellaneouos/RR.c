#include<stdio.h>
#include<conio.h>
void main()
{
    int i, no_p, sum=0,count=0, y;
    int  quant, wt=0, tat=0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    clrscr();
    printf("Total number of process in the system: ");
    scanf("%d", &no_p);
    y = no_p;
    for(i=0; i<no_p; i++)
    {
       printf("\nEnter the Arrival and Burst time of P%d\n", i+1);
       printf("Arrival time is: ");
       scanf("%d", &at[i]);
       printf("\nBurst time is: ");
       scanf("%d", &bt[i]);
       temp[i] = bt[i];
    }
    printf("Enter the Time Quantum for the process: \t");
    scanf("%d", &quant);
    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for(sum=0, i = 0; y!=0; )
    {
       if(temp[i] <= quant && temp[i] > 0) // define the conditions
       {
	  sum = sum + temp[i];
	  temp[i] = 0;
	  count=1;
       }
       else if(temp[i] > 0)
       {
	  temp[i] = temp[i] - quant;
	  sum = sum + quant;
       }
       if(temp[i]==0 && count==1)
       {
	  y--; //decrement the process no.
	  printf("\nP%d \t\t %d \t\t\t %d \t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);
	  wt = wt+sum-at[i]-bt[i];
	  tat = tat+sum-at[i];
	  count =0;
       }
       if(i==no_p-1)
       {
	  i=0;
       }
       else if(at[i+1]<=sum)
       {
	  i++;
       }
       else
       {
	  i=0;
       }
   }
   avg_wt = wt * 1.0/no_p;
   avg_tat = tat * 1.0/no_p;
   printf("\nAverage Turn Around Time: \t%f", avg_wt);
   printf("\nAverage Waiting Time: \t%f", avg_tat);
   getch();
}
