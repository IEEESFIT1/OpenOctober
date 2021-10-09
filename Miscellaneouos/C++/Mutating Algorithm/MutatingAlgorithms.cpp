#include<bits/stdc++.h>
using namespace std;
int main () {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  vector<int> v ;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  reverse(v.begin(), v.end());   // 6 5 4 3 2 1
  // print out content:
  cout << "Vector v contains: ";
  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';
  vector<int> v1 ;
  //allocate vector the space
  v1.resize(9);
  //Reverse copy the content of array in vector;
  reverse_copy (a, a + 9, v1.begin());
  cout << "Vector v1 contains: ";
  //print vector v1
  for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';
  //rotate vector b by 3
  rotate(v.begin(), v.begin() + 3, v.end());
  // print out content:
  cout << "Vector v After Rotating: ";
  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';
  next_permutation(a, a + 9);
  cout << "Next_Permuation on a: ";
  for (int i = 0; i < 9; ++i)
  {
    cout << ' ' << a[i];
  }
  cout << "\n";
  vector<int> v3 = { 10, 20, 30, 40};
  fill( v3.begin(), v3.end(), 5);
  cout << "Vector v3 contains: ";
  for (vector<int>::iterator it = v3.begin(); it != v3.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';
//MAKE HEAP FUNCTION
  vector<int> v4 = { 6,  23, 7, 30, 12};
  make_heap(v4.begin(), v4.end()); // Makes max heap
  cout << v4.front() << "\n";
  cout << v.front() << "\n";
  vector<int> v5(9);
  cout << "Vector v5 contains: ";
  merge( v3.begin(), v3.end(), v4.begin(), v4.end(), v5.begin() );
  for (vector<int>::iterator it = v5.begin(); it != v5.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';
  return 0;
}