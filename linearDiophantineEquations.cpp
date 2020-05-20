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
        y = x1 - ( a/b)*y1;
        return result;
    }
}

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c;

    int result = extendedGCD( a, b, x, y);
    
    cout << a << " * " << x << " + " << b << " * " << y << " = " << result;
    if (( c%result) == 0)
    {
        int factor = c/ result, X, Y;
        X = x*factor;
        Y = y*factor;
        cout << "\nthe solution to\t" << a << "*X + " << b << "*Y = " << c << " is represented as\n";
        cout << "\tX = " << X << '\n';
        cout << "\tY = " << Y << '\n';
        cout << "the given equation has infinitely many solutions some of which are represented here\n";
        for( int i = -2; i <= 2; i++)
        {
            cout << "\tX = " << (X-((b/result)*i)) << '\n';
            cout << "\tY = " << (Y+((a/result)*i)) << '\n' << '\n';
        }
    }

    else
    {
        cout << "\nthis linear diophantine equation has no integral solution";
    }
    
    return EXIT_SUCCESS;
}