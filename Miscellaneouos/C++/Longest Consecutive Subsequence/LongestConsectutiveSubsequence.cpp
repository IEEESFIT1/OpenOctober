#include<bits/stdc++.h>
using namespace std;
int findLongestConSub(int a[], int n)
{
	int cnt, max = -1;
	sort(a, a + n);
	cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] - 1 == a[i - 1]) {
			cnt = cnt + 1;
		} else if (a[i] == a[i - 1])
			continue;
		else
		{
			if (max < cnt)
				max = cnt;
			cnt = 1;
		}
	}
	if (max < cnt)
		max = cnt;
	return max;
}
int main() {
	cout << "Enter the Test Cases:\n";
	int t;
	cin >> t;
	while (t--) {
		int n;
		cout << "Enter the no of elements to be entered:\n";
		cin >> n;
		int a[n];
		cout << "Enter Elements:\n";
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << "Longest Consecutive Subsequence :" << findLongestConSub(a, n) << endl;
	}
	return 0;
}

