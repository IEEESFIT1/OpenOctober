// Contributed by Kartikey Sharma
// Contributed to OpenOctober
#include <bits/stdc++.h>
using namespace std;

void partition(int a[], int l, int r, int& i, int& j)
{
    i = l - 1, j = r;
    int p = l - 1, q = r;
    int v = a[r];
 
    while (true) {
        while (a[++i] < v)
            ;
        while (v < a[--j])
            if (j == l)
                break;

        if (i >= j)
            break;
        swap(a[i], a[j]);
        if (a[i] == v) {
            p++;
            swap(a[p], a[i]);
        }
        if (a[j] == v) {
            q--;
            swap(a[j], a[q]);
        }
    }
    swap(a[i], a[r]);
    j = i - 1;
    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]);
    i = i + 1;
    for (int k = r - 1; k > q; k--, i++)
        swap(a[i], a[k]);
}
void mergesort(int a[], int l, int r)
{
    if (r <= l)
        return;
    int i, j;
    partition(a, l, r, i, j);
    mergesort(a, l, j);
    mergesort(a, i, r);
}
void printarr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d  ", a[i]);
    printf("\n");
}
int main()
{
    int a[] = { 4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4 };
    int size = sizeof(a) / sizeof(int);
    printarr(a, size);
    mergesort(a, 0, size - 1);
    cout<<"After mergesort: \n";
    printarr(a, size);
    return 0;
}
