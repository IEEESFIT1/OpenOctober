/*
# Time Complexity: Primality

    A prime is a natural number greater than  that has no positive divisors other than  and itself. Given  integers, determine the primality of each integer and print whether it is Prime or Not prime on a new line.

    Note: If possible, try to come up with an  primality algorithm, or see what sort of optimizations you can come up with for an  algorithm. Be sure to check out the Editorial after submitting your code!

    Function Description
        Complete the primality function in the editor below. It should return Prime if  is prime, or Not prime.
        primality has the following parameter(s):
        n: an integer to test for primality

    Input Format
        The first line contains an integer, , denoting the number of integers to check for primality.
        Each of the  subsequent lines contains an integer, , the number you must test for primality.

    Output Format
        For each integer, print whether  is Prime or Not prime on a new line.

    Sample Input
        3
        12
        5
        7

    Sample Output
        Not prime
        Prime
        Prime
*/
#include <bits/stdc++.h>

using namespace std;

// Complete the primality function below.
string primality(int n)
{
    if (n < 2)
        return "Not prime";
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return "Prime";

    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
            return "Not prime";
    }

    return "Prime";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int p_itr = 0; p_itr < p; p_itr++)
    {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = primality(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
