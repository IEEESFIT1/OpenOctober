#include<iostream>
using namespace std;
int i,j,k,r1,c1,r2,c2;
int a[10][10];
int b[10][10];
int sum[10][10];
int prod[10][10];

void input();
void add();
void multiply();
void display(int [10][10], int, int);

int main()
{
    int d;
    cout<<"Enter the no. of Rows and Columns of the 1st Matrix\n"<<endl;
    cin>>r1>>c1;
    cout<<"Enter the no. of Rows and Columns of the 2nd Matrix\n"<<endl;
    cin>>r2>>c2;
    cout<<"What operation would you like to do with these Matrices?\nEnter 1 for Addition\nEnter 2 for Multiplication\n";
    cin>>d;
    switch(d)
    {
    case 1:
        {
            if (r1!=r2||c1!=c2)
                cout<<"\nAddition of matrices of the given order isn't possible.\n";
            else
            {
                input();
                add();
                cout<<"First Matrix you entered: \n";
                display(a,r1,c1);
                cout<<"Second Matrix you entered: \n";
                display(b,r2,c2);
                cout<<"Sum of these two matrices: \n";
                display(sum,c1,r1);
            }
            break;
        }
    case 2:
        {
            if(c1!=r2)
                cout<<"\nMultiplication of matrices of the given order isn't possible.\n";
            else
            {
                input();
                multiply();
                cout<<"First Matrix you entered: \n";
                display(a,r1,c1);
                cout<<"Second Matrix you entered: \n";
                display(b,r2,c2);
                cout<<"Product of these two matrices: \n";
                display(prod,r1,c2);
            }
            break;
        }
    default:
        cout<<"Invalid input!";
    }
    return 0;
}
void input()
{
    int i,j;
    cout<<"\nEnter the elements of the First matrix: \n";
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"\nEnter the elements of the Second matrix: \n";
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        {
            cin>>b[i][j];
        }
    }
}
void add()
{
    int i, j;
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c1; j++)
        {
            sum[i][j] = a[i][j]+b[i][j];
        }
    }
}
void multiply()
{
    int i,j,k;
    for(i=0; i<r1; i++)
    {
        for(j=0; j<c2; j++)
        {
            prod[i][j]=0;
            for(k=0; k<c1; k++)
            {
                prod[i][j] = prod[i][j]+(a[i][k]*b[k][j]);
            }
        }
    }
}
void display(int m[10][10], int x, int y)
{
    int i, j;
    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            cout<<m[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
