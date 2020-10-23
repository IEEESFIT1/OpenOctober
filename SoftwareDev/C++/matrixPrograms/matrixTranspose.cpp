#include<iostream>
using namespace std;
class Transpose
{
private:
    int a[10][10];
    int i,j,temp,n;
public:
    void input()
    {
        cout<<"Enter the order of the Square matrix:\n";
        cin>>n;
        cout<<"Enter "<<n*n<<" elements: \n";
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<"The matrix before Transpose looks like: \n";
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                cout<<a[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }
    void calculate()
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i<j)
                {
                    temp=a[i][j];
                    a[i][j]=a[j][i];
                    a[j][i]=temp;
                }
            }
        }
    }
    void displayTranspose()
    {
        cout<<"The matrix after Transpose looks like: \n";
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                cout<<a[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }
};
int main()
{
    Transpose t;
    t.input();
    t.calculate();
    t.displayTranspose();
    return 0;
}
