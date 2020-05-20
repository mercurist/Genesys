#include <iostream>
#include <vector>
#define N 10000

using namespace std;

void multiply ( vector<int> &factorial, int x)
{
    int carry = 0, temp;
    for( int i = 0; i< factorial.size(); i++)
    {
        temp =  (factorial[i]*x)+ carry;
        factorial[i] = (temp % 10);
        carry = temp / 10;
    }

    if ( carry != 0)
    {
        factorial.push_back(carry);
    }
}

void largeFactorial( vector<int> &factorial, int x)
{
    if ( x == 0 || x == 1)
    {
        if ( factorial.empty() == true)
            factorial.push_back(1);
    }

    else
    {
        largeFactorial( factorial, x-1);
        multiply( factorial, x);
    }

}

void factorialDisplay( const vector<int> &factorial)
{
    int flag = 0;
    for( int i = factorial.size(); i >= 0; i--)
    {
        while ( flag == 0 && factorial[i] == 0)
            continue;
        
        flag = 1;
        cout << factorial[i];
    }
}

int main()
{
    int x;
    cin >> x;
    vector<int> factorial;
    factorial.clear();

    largeFactorial( factorial, x);
    // factorialDisplay( factorial);
    for( int i = factorial.size(); i >= 0; i--)
    {
        // while ( flag == 0 && factorial[i] == 0)
        //     continue;
        
        // flag = 1;
        cout << factorial[i];
    }
    
    return EXIT_SUCCESS;
}