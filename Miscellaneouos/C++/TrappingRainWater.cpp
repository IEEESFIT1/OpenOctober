#include<bits/stdc++.h>
using namespace std;
int trappingRainWater(int a[], int n) {
	// Your code here
	int l[n], r[n], sum = 0;
	l[0] = a[0];
	r[n - 1] = a[n - 1];
	for (int i = 1; i < n; i++) {
		if (a[i] > l[i - 1])
			l[i] = a[i];
		else
			l[i] = l[i - 1];
	}
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] > r[i + 1])
			r[i] = a[i];
		else
			r[i] = r[i + 1];
		sum = sum + max((min(l[i], r[i]) - a[i]), 0);
	}
	return sum;
}
int main() {
	cout << "Enter Test Case No:"
	     int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << "Enter the total  blocks no:"
		     int a[n];
		cout << "Enter the hight of each block: ";
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << "water trapped is " << trappingRainWater(a, n) << " units" << endl;
	}
	return 0;
}

