#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

ll LIS(vector<ll> powers, ll i, ll j)
{
    ll LS = j - i + 1;
    vector<ll> dp(LS, 1);
    ll result = 0;
    for (ll k = i + 1; k <= j; k++)
    {
        for (ll l = i; l < k; l++)
        {
            if (powers[l] < powers[k])
                dp[k - i] = max(dp[k - i], dp[l - i] + 1);
            result = max(dp[k - i], result);
        }
    }
    return result;
}

int main()
{
    ll tc;
    ll numSoldiers, numQueries;
    ll typeOfQuery;
    ll x, y;
    vector<ll> powers;
    cin >> tc;
    while (tc--)
    {
        cin >> numSoldiers >> numQueries;
        powers.resize(numSoldiers);
        for (int i = 0; i < numSoldiers; i++)
        {
            cin >> powers[i];
        }
        while (numQueries--)
        {
            cin >> typeOfQuery;
            if (typeOfQuery == 1)
            {
                cin >> x >> y;
                powers[x - 1] += y;
            }
            else
            {
                cin >> x >> y;
                cout << LIS(powers, x - 1, y - 1) << '\n';
            }
        }
    }
    return 0;
}