#include <iostream>
#include <cstdlib>

using namespace std;

bool isPrimeButNaive( int x)
{
    for( int i = 2; i < x; i++)
    {
        if (( x%i) == 0)
            return false;
    }
    return true;
}

// based on the principle that the number of divisors of N less than sqrt(N) is the same as the number of divisors of N greater than sqrt(N)
bool isPrimeRoot( int x)
{
    for( int i = 2; i*i <= x; i++)
    {
        if (( x%i) == 0)
            return false;
    }
    return true;
}

// only checking for the odd numbers thereby reducing the no of checks by half
bool isPrimeRootInHalf( int x)
{
    if ( x == 1)        return true;
    if ( x == 2)        return true;
    if (( x % 2) == 0)  return false;
    for( int i = 3; i*i <= x; i++)
    {
        if (( x % i) == 0)
        return false;
    }
    return true;
}

int main()
{
    int x;
    cin >> x;
    if ( isPrimeRootInHalf(x))
        cout << "prime";
    else
        cout << "not prime";
    
    return EXIT_SUCCESS;
}