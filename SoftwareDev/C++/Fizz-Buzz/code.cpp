/*
    Author : MAYANK MOHAK
    Date   : 27/10/2020
    codechef: mayankmohak
    hackerrank: @mayankmohak
    !!happy coding!!
*/
#include<bits/stdc++.h>
using namespace std;
#define ll      long long int
using namespace std::chrono;

void bad_fizzbuzz(ll lb,ll ub)
{
    // // Start measuring time
    clock_t start = clock();

    for (ll i=lb; i<=ub; i++)
    {
        string str;
        cout<<i<<"->";
        // number divisible by 3 and 5 will
        // always be divisible by 15, print 
        // 'FizzBuzz' in place of the number
        if (i%5==0 && i%3 == 0)
            str = "FizzBuzz";

        // number divisible by 3? print 'Fizz'
        // in place of the number
        else if ((i%3) == 0)
            str = "Fizz";
         
        // number divisible by 5, print 'Buzz'  
        // in place of the number
        else if ((i%5) == 0)
            str = "Buzz";

        else // print the number
            cout<<i;
        
        cout<<str<<endl;
    }
    // Stop measuring time and calculate the elapsed time
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    
    printf("Time measured: %.3f seconds.\n", elapsed);
    
}

void good_fizzbuzz(ll lb,ll ub){
    // // Start measuring time
    clock_t start = clock();
    
    for (ll i=lb; i<=ub; i++){
        string str = "";
        bool divisibleby3 = i%3;
        bool divisibleby5 = i%5;
        cout<<i<<"->";
        // number divisible by 3 and 5 will
        // always be divisible by 15, print 
        // 'FizzBuzz' in place of the number
        if (!divisibleby3 && !divisibleby5)
            str = "FizzBuzz";

        // number divisible by 3? print 'Fizz'
        // in place of the number
        else if (!divisibleby3)
            str = "Fizz";
         
        // number divisible by 5, print 'Buzz'  
        // in place of the number
        else if (!divisibleby5)
            str = "Buzz";

        else // print the number
            cout<<i;
        
        cout<<str<<endl;
    }
    // Stop measuring time and calculate the elapsed time
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    
    printf("Time measured: %.3f seconds.\n", elapsed);
}

void advanced_fizbuzz(ll lb,ll ub){
    // if the numbers are in a sequence from 1 to 100000
    // why to go for checking it
    // There is a pattern

    // Start measuring time
    clock_t start = clock();
    
    ll count3 = lb + 3 - lb%3,count5 =lb + 5 - lb%5;
    for(ll i=lb ; i <= ub ; i++){
        string str;
        cout<<i<<"->";
        bool printed = false;
        if(i == count3){
            str = "Fizz";
            count3 += 3;
            printed = true;
        }
        if(i == count5){
            str += "Buzz";
            count5 += 5;
            printed = true;
        }

        if(not printed)
            cout<<i;

        cout<<str<<endl;
    }
    // Stop measuring time and calculate the elapsed time
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    
    printf("Time measured: %.3f seconds.\n", elapsed);
}

int main(){
    //lower and uper bound for fizz buzz
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ll lb,ub;
    cout<<" Enter the lower Bound: ";
    cin>>lb;

    cout<<"\nEnter the Upper Bound: ";
    cin>>ub;

//-----------------------------------------------------------------------------
    cout<<"bad_fizzbuzz"<<endl;
    bad_fizzbuzz(lb, ub);
//-----------------------------------------------------------------------------
    cout<<"normal_fizzbuzz"<<endl;
    good_fizzbuzz(lb, ub);
//-----------------------------------------------------------------------------
    cout<<"advanced_fizbuzz"<<endl;
    advanced_fizbuzz(lb, ub);

    return 0;
}

/*
	DIFFERENCE BETWEEN THREE ALGORITHMS:-
	This aproch defines the thinking capability of the coder.
	
	bad_fizzbuzz:-
	  -It checks divisibility 2 times each.
	  -Code looks like a noob code doing just what said.
	  -belive me everyone who can code do this.
	
	normal_fizzbuzz:- 
	  -It checks divisibility once so any change in checking can be done once only.
	  -Though it is not a smarter one coz it does same thing but it's quite good.
	
	advanced_fizzbuzz:-
	  -It takes benifite of what the question tells in a smarter way.
	  -It checks divisibility once and and that also outside loop.
	
	
*/
