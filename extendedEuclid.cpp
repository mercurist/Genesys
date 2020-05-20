#include <iostream>

using namespace std;

int extendedGCD( int a, int b, int &x, int &y)
{
    if ( b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        int x1, y1;
        int result = extendedGCD( b, a%b, x1, y1);
        x = y1;
        y = x1 - (a/b)*y1;
        return result;
    }
}

int main()
{
    int a, b, x, y;
    cin >> a >> b;
    int result = extendedGCD(a, b, x, y);
    cout << a << " * " << x << " + " << b << " * " << y << " = " << result;
    return EXIT_SUCCESS;
}