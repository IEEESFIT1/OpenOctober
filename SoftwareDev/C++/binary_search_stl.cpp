#include<bits/stdc++.h>
using namespace std;

int main()
{
   vector<int> sortedarray = {2 , 5, 7, 8 , 15, 20 };
   vector<int> sortedarray2 = {2, 3, 4, 6 , 9 , 23 };
   vector<int> sortedarray3 = {2 , 5, 7, 7 , 15, 20 };
   cout<<"The position of element 7 found using lower_bound function :";
   cout<<"\nCase 1 : When element is present in array but only once ";
   cout<<lower_bound(sortedarray.begin() , sortedarray.end(), 7) - sortedarray.begin();
   cout<<"\nCase 2 : When element is present more than one times in the array ";
   cout<<lower_bound(sortedarray3.begin() , sortedarray3.end(), 7) - sortedarray3.begin();
   cout<<"\nCase 3 : When element is not present in the array ";
   cout<<lower_bound(sortedarray2.begin() , sortedarray2.end(), 7) - sortedarray2.begin();

   cout<<"The position of element 7 found using upper_bound function :";
   cout<<"\nCase 1 : When element is present in array but only once ";
   cout<<upper_bound(sortedarray.begin() , sortedarray.end(), 7) - sortedarray.begin();
   cout<<"\nCase 2 : When element is present more than one times in the array ";
   cout<<upper_bound(sortedarray3.begin() , sortedarray3.end(), 7) - sortedarray3.begin();
   cout<<"\nCase 3 : When element is not present in the array ";
   cout<<upper_bound(sortedarray2.begin() , sortedarray2.end(), 7) - sortedarray2.begin();
}
