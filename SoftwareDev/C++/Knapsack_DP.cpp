// Contributed by Kartikey Sharma
// Contributed to OpenOctober
#include <bits/stdc++.h>
using namespace std;

int greedy_knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w]= max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
 
int main()
{
    cout << "Enter the number of items in a Knapsack :";
    int n, W;
    cin >> n;
    int val[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value and weight for item :" << i << ":";
        cin >> val[i];
        cin >> wt[i];
    }
    
    cout << "Enter the capacity of knapsack :";
    cin >> W;
    cout << "Maximum value possible: "<< greedy_knapsack(W, wt, val, n);
 
    return 0;
}
