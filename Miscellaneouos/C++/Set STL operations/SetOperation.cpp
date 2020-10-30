#include <iostream>
#include <iterator>
#include <set>
using namespace std;
int main()
{
	// empty set container
	set<int, greater<int> > s1;
	// insert elements in random order
	s1.insert(10);
	s1.insert(1);
	s1.insert(4);
	s1.insert(3);
	s1.insert(2);
	s1.insert(7);
	s1.insert(8);
	// only one 1 will be added to the set
	s1.insert(1);
	s1.insert(10);

	// printing set s1
	set<int, greater<int> >::iterator i;
	cout << "\nSet s1 is : \n";
	for (i = s1.begin();
	        i != s1.end(); ++i)
	{
		cout << ' ' << *i;
	}
	cout << endl;
	// copying the elements from s1 to s2
	set<int> s2(s1.begin(), s1.end());
	// printing s2
	cout << "\nSet s2 : \n";
	for (i = s2.begin();
	        i != s2.end(); ++i)
	{
		cout << ' ' << *i;
	}
	cout << endl;
	// remove all elements up to 4 in s2
	cout
	        << "\ns2 after removal of elements less than 30 :\n";
	s2.erase(s2.begin(), s2.find(4));
	for (i = s2.begin();
	        i != s2.end(); ++i) {
		cout << ' ' << *i;
	}
	// remove element with value 10 in s2
	int num;
	num = s2.erase(10);
	cout << "\ns2.erase(10) : " << num << " removed\n";
	for (i = s2.begin(); i != s2.end(); ++i)
	{
		cout << ' ' << *i;
	}
	cout << endl;
	// lower bound and upper bound of set s1
	cout << "s1.lower_bound(4) : " << *s1.lower_bound(4) << endl;
	cout << "s1.upper_bound(4) : " << *s1.upper_bound(4) << endl;
	// lower bound and upper bound of set s2
	cout << "s1.lower_bound(7) : " << *s1.lower_bound(7) << endl;
	cout << "s1.upper_bound(7) : " << *s1.upper_bound(7) << endl;
	// to clear the elements in set s1
	s1.clear();
	//to check whether the set is empty of not
	if (s1.empty())
		cout << "s1 is empty\n";
	else
		cout << "S1 is not empty\n";
	return 0;
}
