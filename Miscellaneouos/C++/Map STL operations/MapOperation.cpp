#include <iostream>
#include <iterator>
#include <map>
using namespace std;
int main()
{
	//Declaration of map
	map<int, int> m;
	// Insertion in Map
	m.insert(pair<int, int>(3, 40));
	m.insert(pair<int, int>(4, 30));
	m.insert(pair<int, int>(5, 60));
	m.insert(pair<int, int>(6, 20));
	m.insert( make_pair(8, 100));
	m[1] = 20;  // inserts key = "1" with value = 20
	m[2] = 50;
	cout << "KEY 1 ELEMENT:";
	cout << m.at(1) ;  // prints value associated with key 1 ,
	// printing Map p
	map<int, int>::iterator i;
	cout << "\n\n\tKey\tElement\n";
	for (i = m.begin(); i != m.end(); ++i) {
		cout << '\t' << i->first
		     << '\t' << i->second << '\n';
	}
	cout << endl;
	// assigning the elements from m to m2
	map<int, int> m2(m.begin(), m.end());
	// print all elements of the map m2
	// printing Map m2
	cout << "\tKey\tElement\n";
	for (i = m2.begin(); i != m2.end(); ++i) {
		cout << '\t' << i->first
		     << '\t' << i->second << '\n';
	}
	cout << endl;
	// remove all elements up to element with key=3 in gquiz2
	cout << "\nMap m after removal of"
	     " elements less than key=3 : \n";

	m2.erase(m2.begin(), m2.find(3));
	cout << "\tKey\tElement\n";
	for (i = m2.begin(); i != m2.end(); ++i) {
		cout << '\t' << i->first
		     << '\t' << i->second << '\n';
	}
	cout << endl;
	// remove all elements with key = 4
	int num;
	num = m2.erase(4);
	cout << "\ngquiz2.erase(4) : ";
	cout << num << " removed \n";
	cout << "\tKey\tElement\n";
	for (i = m2.begin(); i != m2.end(); ++i) {
		cout << '\t' << i->first
		     << '\t' << i->second << '\n';
	}
	cout << endl;
	// lower bound and upper bound for map m key = 5
	cout << "m.lower_bound(5) : "
	     << "\tKEY = ";
	cout << m.lower_bound(5)->first << '\t';
	cout << "\tELEMENT = "
	     << m.lower_bound(5)->second << endl;
	cout << "m.upper_bound(5) : "
	     << "\tKEY = ";
	cout << m.upper_bound(5)->first << '\t';
	cout << "\tELEMENT = "
	     << m.upper_bound(5)->second << endl;
	return 0;
}
