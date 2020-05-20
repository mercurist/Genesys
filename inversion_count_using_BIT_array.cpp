#include <iostream>
#include <cstring>
#define ll long long int

using namespace std;

ll a[200005];
ll BIT[200005] = {0};

void update(ll index, ll val, ll n)
{
    while (index <= n)
    {
        BIT[index] += val;
        index += index & -index;
    }
}

ll query(ll index)
{
    ll ans = 0;
    while (index > 0)
    {
        ans += BIT[index];
        index -= index & -index;
    }
    return ans;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n, ans;
    cin >> t;
    while (t--)
    {
        cin >> n;

        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        memset(BIT, 0, sizeof(BIT));

        cin.ignore();
        ans = 0;
        for (ll i = n; i >= 1; i--)
        {
            ans += query(a[i] - 1);
            update(a[i], 1, n);
        }

        cout << ans << '\n';
    }

    return EXIT_SUCCESS;
}