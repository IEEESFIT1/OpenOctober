#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int foo(int k, int n){
    while(k < 0) {
        k += n;
    }
    return k % n;
}
int main() {
    int t,arr[100009], ar[100009];
    int n,i,k,q;
    cin >> n >>  k >> q;
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(i=0; i<n; i++) {
        ar[i] = arr[foo(i-k+n,n)];
    }
    while(q--) {
        int p;
        cin >> p;
        cout << ar[p] << endl;
    }
    return 0;
}
