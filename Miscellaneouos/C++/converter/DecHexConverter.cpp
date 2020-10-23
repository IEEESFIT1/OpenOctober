#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
class Converter
{
private:
    int n,m,temp;
    long int deci=0, rem, val, len;
    char hexa[100], hexd[10];
public:
    void decToHex()
    {
        int i=0,j;
        cout<<"Enter a decimal number: ";
        cin>>n;
        m=n;
        while(n!=0)
        {
            temp=0;
            temp=n%16;
            if(temp<10)
            {
                hexa[i]=temp + 48;
                i++;
            }
            else
            {
                hexa[i]=temp + 55;
                i++;
            }
            n=n/16;
        }
        cout<<"\nHexadecimal equivalent of "<<m<<": ";
        for(j=i-1; j>=0; j--)
        {
            cout<<hexa[j];
        }
    }
    void hexToDec()
    {
        int i;
        cout<<"Enter Hexadecimal String: ";
        cin>>hexd;
        strrev(hexd);
        len=strlen(hexd);
        for(i=0; i<len; i++)
        {
            switch(hexd[i])
            {
            case '0':
                val=0;
                break;
            case '1':
                val=1;
                break;
            case '2':
                val=2;
                break;
            case '3':
                val=3;
                break;
            case '4':
                val=4;
                break;
            case '5':
                val=5;
                break;
            case '6':
                val=6;
                break;
            case '7':
                val=7;
                break;
            case '8':
                val=8;
                break;
            case '9':
                val=9;
                break;
            case 'a':
            case 'A':
                val=10;
                break;
            case 'b':
            case 'B':
                val=11;
                break;
            case 'c':
            case 'C':
                val=12;
                break;
            case 'd':
            case 'D':
                val=13;
                break;
            case 'e':
            case 'E':
                val=14;
                break;
            case 'f':
            case 'F':
                val=15;
                break;
            }
            rem=val;
            deci=deci+rem*pow(16,i);
        }
        cout<<"Decimal equivalent is: "<<deci;
    }
    void execute()
    {
        int d;
        cout<<"Which conversion would you like to perform? \nEnter 1 for Decimal to Hexadecimal\nEnter 2 for Hexadecimal to Decimal\n";
        cin>>d;
        switch(d)
        {
        case 1:
            decToHex();
            break;
        case 2:
            hexToDec();
            break;
        default:
            cout<<"Invalid input!";
        }
    }

};
int main()
{
    Converter c;
    c.execute();
    return 0;
}
