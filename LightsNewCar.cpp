#include <iostream>
#define ll long long int
#define mod 1000000007

using namespace std;

ll stringToInt( string s, ll m)
{
    ll result = 0;
    for(int i = 0; i < s.size(); i++)
    {
        result = (( result * 10)%m + s[i] - '0');
        result = result%m;
    }
    return result;
}

ll fastExponentiation( ll x, ll y, ll m)
{
    if ( y == 0)
        return 1;

    else
    {
        ll smallExponent = fastExponentiation( x, y/2, m);
        smallExponent = smallExponent%m;
        smallExponent = (smallExponent*smallExponent)%m;
        if (( y&1) == 1)                // if y is odd
            return (x * smallExponent)%m;
        else
            return smallExponent;
    }
}

int main()
{
    ll t;
    cin >> t;
    string a, b;
    while ( t--)
    {
        cin >> a >> b;
        ll x = stringToInt( a, mod);
        ll y = stringToInt( b, mod-1);
        cout << fastExponentiation( x, y, mod) << '\n';
    }
    return EXIT_SUCCESS;
}