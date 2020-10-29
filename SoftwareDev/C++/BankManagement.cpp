#include<iostream>
using namespace std;
class XYZBank
{
private:
    long int acc_no, payee_ac;
    string name;
    float balance, dep, withd, transf;
public:
    void OpenAccount()
    {
        cout<<"***************Welcome to XYZ BANK!*****************\nEnter your Full Name: ";
        getline(cin, name);
        cout<<"\nEnter a 4-digit number of your choice: ";
        cin>>acc_no;
        cout<<"\nEnter the initial depositing amount (in INR): ";
        cin>>balance;
    }
    void displayAccount()
    {
        cout<<"\nName: "<<name;
        cout<<"\nAccount No.: 102796"<<acc_no;
        cout<<"\nAccount Balance (INR): "<<balance;
    }
    void amountDeposit()
    {
        cout<<"\nEnter the amount you want to deposit (INR): ";
        cin>>dep;
        balance+=dep;
        cout<<"\nSuccessfully deposited (INR) "<<dep<<" to your account";
        cout<<"\nYour total balance now is (INR): "<<balance;
    }
    void amountWithdraw()
    {
        cout<<"\nEnter the amount you want to withdraw (INR): ";
        cin>>withd;
        //This will execute only when balance is sufficient.
        if(withd<=balance)
        {
            balance-=withd;
            cout<<"\nSuccessfully withdrawn (INR) "<<withd<<" from your account";
            cout<<"\nYour total balance now is (INR): "<<balance;
        }
        else
            cout<<"\nSorry! You have insufficient balance in your account!";
    }
    void amountTransfer()
    {
        string payee;
        cout<<"\nEnter the name of the Payee: ";
        cin>>payee;
        cout<<"\nEnter the account number of Payee: ";
        cin>>payee_ac;
        cout<<"\nEnter the amount you want to transfer (INR): ";
        cin>>transf;
        //This too will execute if sufficient balance exists.
        if(transf<=balance)
        {
             balance-=transf;
             cout<<"\nSuccessfully transfered (INR) "<<transf<<" to "<<payee;
             cout<<"\nYour current balance is (INR): "<<balance;
        }
        else
            cout<<"\nSorry! You have insufficient balance in your account!";
    }
};
int main()
{
    XYZBank b;
    b.OpenAccount();
    int c;
    cout<<"\nNow that you've made your account, choose what action you want to do!";
    do
    {
        //Menu for the functions
        cout<<"\n\nSelect an option - \n1 Display Account Details\n2 Deposit Amount\n3 Withdraw Amount\n4 Transfer Amount\n5 Exit\n";
        cin>>c;
        switch(c)
        {
        case 1:
            b.displayAccount();
            break;
        case 2:
            b.amountDeposit();
            break;
        case 3:
            b.amountWithdraw();
            break;
        case 4:
            b.amountTransfer();
            break;
        case 5:
            cout<<"\nIt was nice helping you! Have a great day ahead!\n";
            break;
        default:
            cout<<"\nInvalid input!";
        }
    }while(c!=5);
    return 0;
}
