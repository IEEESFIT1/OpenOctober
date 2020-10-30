#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
    cout << "Enter the No of TestCases:\n";
    cin >> t;
    while (t--) {
        cout << "Enter the matrix \n";
        cin >> n;
        int a[n][n];
        cout << "Enter the Element\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}