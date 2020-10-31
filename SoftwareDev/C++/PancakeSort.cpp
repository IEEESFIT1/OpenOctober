//C++ program to implement Pancake sort
#include<bits/stdc++.h>
using namespace std; 
void flip(int arr[] , int i){
	for(int j = 0 ; j <= (i / 2) ; j++)
	{
		int temp = arr[i-j] ; 
		arr[i-j] = arr[j] ; 
		arr[j] = temp ; 
	}
}
void sort(int arr[] , int n){
	int curr_size = n ; 
	while(curr_size > 0)
	{
		int max_index = max_element(arr , arr + curr_size) - arr; 
		if(max_index !=curr_size -1)
		{
		flip(arr, max_index); 
		flip(arr, curr_size -1) ;}
		curr_size-- ; 	
	}
}
int main()
{
	int n ; cin >> n ; 
	int a[n] ; 
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> a[i] ; 
	}
	sort(a , n); 
	for(int i = 0 ; i < n ; i ++)
	{
		cout << a[i] << " " ; 
	}
	return 0;
}
