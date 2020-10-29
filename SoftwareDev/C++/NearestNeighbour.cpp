//C++ program on nearest neighbour algorithm
#include<iostream>
using namespace std;
int c = 0, cost = 1000;
int g[3][3 ] = { {1,2,3},{4,5,8},{6,7,10}};
void swap(int *x, int *y) {
   int t;
   t = *x;
   *x = *y;
   *y = t;
}
void cal_sum(int *a, int n) {
   int i, s= 0;
   for (i = 0; i <= n; i++) {
      s+= g[a[i %3]][a[(i+ 1) %3]];
   }
   if (cost >s) {
      cost = s;
   }
}
void permute(int *a,int i,int n) {
   int j, k;
   if (i == n) {
      cal_sum (a,n);
   } else {
      for (j = i; j <= n; j++) {
         swap((a + i), (a + j));
         cal_sum(a+1,n);
         swap((a + i), (a + j));
      }
   }
}
int main() {
   int i, j;
   int a[] = {1,2,3};//take array elements
   permute(a, 0,2);
   cout << "minimum cost:" << cost << endl;
   return 0;
}

