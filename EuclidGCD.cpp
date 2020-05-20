#include <iostream>

using namespace std;

int GreatestCD( int a, int b)
{
    if ( b == 0)
        return a;
    else
    {
        return GreatestCD( b, a%b);
    }
}

int greatestCD( int a, int b)
{
    if ( a == 0)
        return b;
    else
    {
        return greatestCD( b%a, a);
    }
}

int GCDButBruteForce( int a, int b)
{
    int flag;
    for(int i = 1; i <= min(a, b); i++)
    {
        if (( (a % i) == 0) && (b %i)== 0)
        {
            flag = i;
        }
    }
    return flag;
}

int LCM( int a, int b)
{
    return ( a* b)/ (GreatestCD(a, b)); 
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "\ngcd of " << a << " and " << b << " is " << GCDButBruteForce( a, b);
    cout << "\nlcm of " << a << " and " << b << " is " << LCM( a, b);
    return EXIT_SUCCESS;
}