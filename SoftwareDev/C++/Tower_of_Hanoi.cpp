#include<iostream>		//the c++ standard library for stream input output
#include<cstdio>		//the c standard library for standard input output
#include<cstdlib>		//for the exit function
using namespace std;

class arr			//arr class that holds each stag
{
	public:
	int a[100],b[100],c[100];
	int topa,topb,topc;
}hanoi;

int moves=1;			//counts the no. of moves

void tower(int n,int src[],int dest[],int aux[],int *ts,int *td,int *ta)      //the tower function passes
{										//the arrs along with the top pointers
	void show (int);
	if(n==1)								//if one element is there in source arr ,
	{									//then it is moved to the destination arr,
		dest[++(*td)]=src[(*ts)];
		src[*ts]=-1;
		(*ts)--;
		int max;
		max=((*ts)>(*td)?(*ts):(*td));
		max=(max>(*ta)?max:(*ta));
		cout<<"	 Move "<<moves++<<" ";
		cout<<"\nrod A =>";
		for(int i=max;i>-1;i--)					//show the status of each arr
	{
		
		show(hanoi.a[i]);
		
	}
	cout<<"\nrod B =>";
	for(int i=max;i>-1;i--)					//show the status of each arr
	{
		
		show(hanoi.b[i]);
		
	}
	cout<<"\nrod C =>";
	for(int i=max;i>-1;i--)					//show the status of each arr
	{
		
		show(hanoi.c[i]);
		
	}
	
	cout<<"\n";
		return;
	}
	tower(n-1,src,aux,dest,ts,ta,td);					//else the
	tower(1,src,dest,aux,ts,td,ta);						//	problem is solved by
	tower(n-1,aux,dest,src,ta,td,ts);					//			recursive calls

}

void show(int a)					//the show function shows the current status of the arrs
{
	if(a==-1)
		cout<<"- ";
	else
		cout<<a<<" ";
}


int main()
{
	void tower(int ,int *,int *,int *,int *,int *,int *);		//function prototype
	void show(int);							//function prototype
	int n;
	cout<<"Enter the number of disks: ";
	cin>>n;
	for(int j=0;j<n;j++)					//feeds the elements in the arrs;
	{
		hanoi.a[j]=j+1;
		hanoi.b[j]=-1;
		hanoi.c[j]=-1;
	}
	hanoi.topa=n-1;						//topa,topb,topc,mean the top of each arr
	hanoi.topb=-1;
	hanoi.topc=-1;
	cout<<"Initially "<<"\n";
	cout<<"rod A =>";
	for(int j=n-1;j>-1;j--)					//show the status of each arr
	{
		
		show(hanoi.a[j]);
		
	}
	cout<<"\nrod B =>";
	for(int j=n-1;j>-1;j--)					//show the status of each arr
	{
		
		show(hanoi.b[j]);
		
	}
	cout<<"\nrod C =>";
	for(int j=n-1;j>-1;j--)					//show the status of each arr
	{
		
		show(hanoi.c[j]);
		
	}
	
	cout<<"\n";

tower(n,hanoi.a,hanoi.c,hanoi.b,&(hanoi.topa),&(hanoi.topc),&(hanoi.topb));	
}


