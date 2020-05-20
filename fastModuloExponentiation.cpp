#include <iostream>
#define ll long long int

using namespace std;

ll fastModExp( int a, int b, int m)
{
    ll result = 1;
    while ( b > 0)
    {
        if ( b & 1)
            result = ( result * a)%m;
        a = (a*a)%m;
        b = b >> 1;
    }

    return result;
}

int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    cout << fastModExp( a, b, m);
    return EXIT_SUCCESS;
}