#include<bits/stdc++.h>
using namespace std;
bool IsOdd (int i) {
	return ((i % 2) == 1);
}
bool mypredicate (int i, int j) {
	return (i == j);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int myints[] = {3, 7, 2, 5, 6, 4, 9};
	// using default comparison: MIN AND MAX
	cout << "The smallest element is " << *min_element(myints, myints + 7) << '\n';
	cout << "The largest element is "  << *max_element(myints, myints + 7) << '\n';
	int *p = std::find (myints, myints + 7, 30);
	if (p != myints + 7)
		std::cout << "Element found in myints: " << *p << '\n';
	else
		std::cout << "Element not found in myints\n";
	//FIND OPERATION
	std::vector<int> myvector (myints, myints + 7);
	std::vector<int>::iterator it;
	it = find (myvector.begin(), myvector.end(), 4);
	if (it != myvector.end())
		std::cout << "Element found in myvector: " << *it << '\n';
	else
		std::cout << "Element not found in myvector\n";
	it = std::find_if (myvector.begin(), myvector.end(), IsOdd);
	std::cout << "The first odd value is " << *it << '\n';
	//SEARCH OPERATION
	std::vector<int> haystack;
	// set some values:        haystack: 10 20 30 40 50 60 70 80 90
	for (int i = 1; i < 10; i++) haystack.push_back(i * 10);
	// using default comparison:
	int needle1[] = {40, 50, 60, 70};
	// std::vector<int>::iterator it;
	it = std::search (haystack.begin(), haystack.end(), needle1, needle1 + 4);
	if (it != haystack.end())
		std::cout << "needle1 found at position " << (it - haystack.begin()) << '\n';
	else
		std::cout << "needle1 not found\n";
// using predicate comparison:
	int needle2[] = {20, 30, 50};
	it = std::search (haystack.begin(), haystack.end(), needle2, needle2 + 3, mypredicate);

	if (it != haystack.end())
		std::cout << "needle2 found at position " << (it - haystack.begin()) << '\n';
	else
		std::cout << "needle2 not found\n";
//EQUAL
	if ( std::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";
	return 0;
}