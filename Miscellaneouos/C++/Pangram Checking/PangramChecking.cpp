//A pangram is a sentence containing every letter in the English Alphabet.
#include<bits/stdc++.h>
using namespace std;
bool checkPangram (string &str)
{
	map<int, int> m;

	for (int i = 0; i < str.length(); i++) {
		if (tolower(str[i]) >= 97  and tolower(str[i]) <= 122) {
			m[tolower(str[i])]++;
		}
	}
	if (m.size() == 26)
		return 1;
	else
		return 0;
}
int main() {
	int t;
	cout << "Enter the No of testcase:";
	cin >> t;
	cin.ignore(INT_MAX, '\n');
	while (t--) {
		cout << "Enter the String";
		string str;
		getline(cin, str);
		if (checkPangram(str) == true)
			cout << "The string is Pangram\n";
		else
			cout << "The string is not Pangram\n";
	}
	return 0;
}