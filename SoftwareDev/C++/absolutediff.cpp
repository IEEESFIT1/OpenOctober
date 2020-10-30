#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n][n];
    long long int d1=0; 
    long long int d2=0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (i == j) d1 += arr[i][j];
            if (i == n - j - 1) d2 += arr[i][j];
        }
    }
    cout << abs(d1 - d2) << endl; 
    return 0;
}
