#include<bits/stdc++.h>
using namespace std;
void nextLargerElement(long long arr[], int n) {
	stack<long long> m;
	vector<long long> v;
	m.push(arr[n - 1]);
	v.push_back(-1);
	for (long long i = n - 2; i >= 0; i--) {
		while (!m.empty() && m.top() <= arr[i] )
			m.pop();
		if (m.empty()) {
			v.push_back(-1);
		}
		else {
			v.push_back(m.top());
		}
		m.push(arr[i]);
	}
	reverse(v.begin(), v.end());
	for (long long i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}
int main() {
	cout << "Enter the No of testcase:";
	int t;
	cin >> t;
	while (t--) {
		int n;
		cout << "Enter the No of Elements";
		cin >> n;
		long long arr[n];
		cout << "Enter the elements"
		     for (int i = 0; i < n; i++)
			     cin >> arr[i];
		nextLargerElement(arr, n);
		cout << endl;
	}
	return 0;
}
