#include<bits/stdc++.h>
using namespace std;
void reverse(char *str, int len)
{
	stack<char> s;
	for (int i = 0; i < len; i++) {
		s.push(str[i]);
	}
	int i = 0;
	while (!s.empty()) {
		str[i] = s.top();
		i++;
		s.pop();
	}
}
int main() {
	long long int t;
	cout << "Enter the Test Cases:\n";
	cin >> t;
	while (t--) {
		char str[100000];
		cout << "Enter the String\n";
		cin >> str;
		long long int len = strlen(str);
		reverse(str, len);
		cout << str;
		cout << endl;
	}
	return 0;
}