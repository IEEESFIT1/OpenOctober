#include <bits/stdc++.h> 
using namespace std; 
class LRUCache { 
	list<int> dq;  
	unordered_map<int, list<int>::iterator> ma; 
	int csize; 
public: 
	LRUCache(int); 
	void refer(int); 
	void display(); 
}; 
LRUCache::LRUCache(int n) 
{ 
	csize = n; 
}  
void LRUCache::refer(int x) 
{ 
	if (ma.find(x) == ma.end()) { 
		// cache is full 
		if (dq.size() == csize) { 
			int last = dq.back(); 
			dq.pop_back(); 
			ma.erase(last); 
		} 
	} 
	else
		dq.erase(ma[x]); 
	dq.push_front(x); 
	ma[x] = dq.begin(); 
}  
void LRUCache::display() 
{ 
	for (auto it = dq.begin(); it != dq.end(); 
		it++) 
		cout << (*it) << " "; 
	cout << endl; 
}  
int main() 
{ 
	int option,val,size;
	cout<<"Cache/memory Size";
	cin>>size;
	LRUCache ca(size);
	do
	{
		cout<<"\n****MAIN MENU****";
		cout<<"\n1.Insert a key";
		cout<<"\n2 Display the cache ";
		cout<<"\n3.Exit";
		cout<<"\nEnter your choice : ";
		cin>>option;
		switch(option)
		{
			case 1:
			{
				cout<<"Enter key x with in the LRU cache: ";
				cin>>val;
				ca.refer(val);
			}
				break;
			case 2:
				ca.display();
				break;
			case 3:break;
			default: break;
		}
	}while(option!=3);
	return 0; 
} 
