#include <iostream>

using namespace std;

int factorial( int x)
{
    if ( x == 0 || x == 1)
    {
        cout << " factorial of " << x << " is " << 1 << '\n';
        return 1;
    }
    else
    {
        int temp = x * factorial( x-1);
        cout << " factorial of " << x << " is " << temp << '\n';
        return temp;
    }
    
}

int main()
{
    int x = 5;
    factorial(5);
    return EXIT_SUCCESS;
}