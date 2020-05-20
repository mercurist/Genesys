#include <iostream>
#define ll long long int

using namespace std;

ll fastModExp( ll a, ll b, ll m)
{
    ll result = 1;
    while ( b > 0)
    {
        if ( b & 1)
            result = ( result * a) % m;
        a = ( a * a) % m;
        b = b >> 1;
    }
    return result;
}

ll boringNomenclature( ll n, ll p)
{
    ll ans = -1;
    for( ll i = n+1; i <= (p-1); i++)
    {
        ll temp = fastModExp( i, p-2, p);
        ans = ( ans* temp) %p;
    }
    return (ans+p);
}

int main()
{
    ll t, n, p;
    cin >> t;
    while ( t--)
    {
        cin >> n >> p;
        if ( n >= p)
            cout << "0" << '\n';
        else
        {
            cout << boringNomenclature(n, p) << '\n';
        }
        
    }
    return EXIT_SUCCESS;
}