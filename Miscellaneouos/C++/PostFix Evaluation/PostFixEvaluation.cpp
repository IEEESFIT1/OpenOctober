#include<bits/stdc++.h>
using namespace std;
int evaluatePostfix(string &str)
{
	stack<int> s;
	for (int i = 0; i < str.length(); i++) {
		char c = str.at(i);
		// cout<<c<<" ";
		if (isdigit(c))
			s.push(c - '0');
		else {
			int val1 = s.top();
			s.pop();
			int val2 = s.top();
			s.pop();
			switch (c) {
			case '+': s.push(val2 + val1); break;
			case '-': s.push(val2 - val1); break;
			case '*': s.push(val2 * val1); break;
			case '/': s.push(val2 / val1); break;
			}
		}
	}
	return s.top();
}
int main() {
	cout << "Enter the No of TestCase:";
	int t;
	cin >> t;
	cin.ignore(INT_MAX, '\n');
	while (t--)
	{
		string str;
		cout << "Enter PostFix Expression";
		cin >> str;
		cout << evaluatePostfix(str) << endl;
	}
	return 0;
}