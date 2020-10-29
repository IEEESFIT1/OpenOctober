// Contributed by Kartikey Sharma
// Contributed to OpenOctober
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    // ----------Vectors----------------
    int n;cin>>n;
	std::vector<int>v(n);
    for(int i=0;i<n;i++)
    	cin>>v[i];
    	
    int x;cin>>x;
    // Appending x to v
    v.push_back(x);
    
    // Summation
    long long ans= accumulate(v.begin(),v.end(),0);
    cout<<"Sum of elements is : "<<ans<<endl;
    
    // Elements in reverse
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();i++)
    	cout<<v[i]<<" ";
    cout<<endl;
    
    //------------MAPS--------------
    map<int,int>a;
    for(int i=0;i<n;i++)
    {
    	int x;cin>>x;
    	// inserting values in map
		a[i]=x;
	}
	
	//----------PAIR<INT,INT>--------
	vector<pair<int,int> >v1;
	for(int i=0;i<n;i++)
	{
		int x;cin>>x;
		// emplace_back() is a better function
		// to use in case of pairs to insert in
		// a vector
		v1.emplace_back(i,x);
	}
	
	//---------UNORDERED SETS---------
	unordered_set <string> stringSet ; 
    stringSet.insert("open") ; 
    stringSet.insert("october") ; 
    stringSet.insert("is") ; 
    stringSet.insert("fun") ;  
    string key = "slow" ; 
    if (stringSet.find(key) == stringSet.end()) 
        cout << key << " not found" << endl << endl ; 
    else
        cout << "Found " << key << endl << endl ; 
    key = "c++"; 
    if (stringSet.find(key) == stringSet.end()) 
        cout << key << " not found\n" ; 
    else
        cout << "Found " << key << endl ; 
    cout << "\nAll elements : "; 
    unordered_set<string> :: iterator itr; 
    for (itr = stringSet.begin(); itr != stringSet.end(); itr++) 
        cout << (*itr) << " " ;
	cout<<endl;
	
	return 0;
}
