#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> a)
{
    int n = a.size();
    for(int i = 0; i < n - 1; ++i)
    {
        int index = i, minimumElement = a[i];
        for(int j = i + 1; j < n; ++j)
        {
            if(minimumElement > a[j])
            {
                minimumElement = a[j];
                index = j;
            }
        }
        swap(a[index], a[i]);
        cout << "Iteration " << i << ": ";
        for(auto it: a)
            cout << it << " ";
        cout << endl;
    }
    cout << "\nAfter Selection Sort: ";
    for(auto it: a)
        cout << it << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    selectionSort(a);
    return 0;
}