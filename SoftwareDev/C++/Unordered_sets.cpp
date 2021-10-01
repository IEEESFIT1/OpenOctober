// Contributed by Kartikey Sharma
// Contributed to OpenOctober
#include <bits/stdc++.h>
using namespace std;

class fruits
{ 
  public:
  string name;
  string color;
  bool operator==(const fruits &f) const 
  {
    return (this->name == f.name);
  }
};

class fruits_hash
{
  public:
  size_t operator() (const fruits & f) const
  {
    return f.name.length();
  }
};

int main() {
  fruits f1 {"Apple", "red"};
  fruits f2 {"Banana", "yellow"};
  unordered_set <fruits, fruits_hash> my_fruits;
  my_fruits.insert(f1);
  my_fruits.insert(f2);
  for (auto i: my_fruits)
    cout<< "Name: " << i.name << ", Color: " << i.color <<endl;

  return 0;
}
