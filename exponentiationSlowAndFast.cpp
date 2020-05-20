#include <iostream>

using namespace std;

int slowExponentiation( int a, int b)
{
    int result = 1;
    for( int i = 0;  i < b; i++)
        result *= a;

    return result;
}

int fastExponentiation( int a, int b)
{
    if ( b == 0)
        return 1;
    if ( b == 1)
        return a;
    
    int result = fastExponentiation( a, b/2);
    if (( b&1) == 0)                // if b is even
        return result * result;
    else
    {
        return a * result * result;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << "pow( a, b) = " << slowExponentiation( a, b);
    cout << "\npowFast( a, b) = " << fastExponentiation( a, b);
    return EXIT_SUCCESS;
}