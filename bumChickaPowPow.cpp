/*
your task is to evaluate a^(b^(exp)).
    0 <= a, b, n <= 10^5

exp = C(n, 0)^2 + C(n, 1)^2 + ... + C(n, n)^2
from simple maths, exp = C( 2n, n)
*/
#include <iostream>
#define mod 1000000007
#define ll long long int

using namespace std;

ll extendedGCD( ll i, ll m, ll &x, ll &y)
{
    if ( m == 0)
    {
        x = 1;
        y = 0;
        return i;
    }

    else
    {
        ll x1, y1;
        ll result = extendedGCD( m, i%m, x1, y1);
        x = y1;
        y = x1 - (i/m)*y1;
        return result;
    }
}

ll multiplicativeModuloInverse( ll i, ll m)
{
    // (i*x) % m = 1
    ll x, y;
    ll result = extendedGCD( i, m, x, y);
    if ( x < 0)
        x = m + x;
    return x;
}

ll binomialCoefficient( ll n, ll k, ll m)
{
    ll result = 1;
    if (k > n - k)
        k = n - k;

    for( ll i = 1; i <= k; i++)
    {
        result = (result * (n - i + 1)) %m;
        /* we know the property of modulo which says ~
            (a / b) % m = [(a % m) * ( b^(-1) % m)] % m. 
            where b^(-1) is the multiplicative modulo inverse of b with respect to m
        */
        /*
        result = (result * multiplicativeModuloInverse(i, m))%m;
        */
        result /= i;
    }

    return result;
}

ll fastModExp( ll B, ll intermediateExponent, ll m)
{
    if ( intermediateExponent == 0)
        return 1;

    else
    {
        ll smallPower = fastModExp( B, intermediateExponent/2, m);
        smallPower = smallPower % m;
        smallPower = (smallPower * smallPower) % m;
        
        if (( intermediateExponent & 1) == 1)
        {
            return (B * smallPower)%m;
        }
        else
        {
            return smallPower;
        }
    }

}

int main()
{
    ll t, a, b, n;
    cin >> t;
    while ( t--)
    {
        cin >> a >> b >> n;
        ll intermediateExponent = binomialCoefficient( 2*n, n, mod-2);
        b = b % (mod-1);
        a = a % mod;
        ll finalExponent = fastModExp( b, intermediateExponent, mod-1);
        ll finalResult = fastModExp( a, finalExponent, mod);

        cout << finalResult << '\n';
    }
    
    return EXIT_SUCCESS;
}