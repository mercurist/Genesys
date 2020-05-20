#include <bits/stdc++.h> #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ff first
#define se second
#define pb push_back
#define nn 20
#define mt make_tuple
#define mp make_pair
#define ll long long int
#define db double
#define ldb long double
#define inf 1000000000000000000l
#define logn 2
#define mod 1000000007ll
#define mod1 mod
#define mod2 100000009ll
#define sqr(a) a * 1ll * a
#define nullp mp(-1, -1)
#define set0(a) memset(a, 0, sizeof a)
#define init(a) memset(a, -1, sizeof a)
#define cmp 1e-16

using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef pair<long double, long double> pdd;
template <class T>
using max_pq = priority_queue<T>;
template <class T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;
ll toint(const string &s)
{
    stringstream ss;
    ss << s;
    ll x;
    ss >> x;
    return x;
}
string tostring(ll number)
{
    stringstream ss;
    ss << number;
    r eturn ss.str();
}
template <class T>
T gcd(T a, T b) { return (b == 0) ? a : gcd(b, a % b); }
ll pow(ll a, ll p, ll m = mod)
{
    ll res = 1;
    while (p > 0)
    {
        if (p & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        p >>= 1;
    }
    return res;
}
const ldb pi = 3.141592653589793238462643383;
int ans;
int n, m;
int l[nn], r[nn];
string s[nn];
void bitmask(bool tight, int pos, int val)
{
    if (pos == n - 1)
    {
        if (tight)
            ans = min(ans, val + r[pos]);
        else
            ans = min(ans, val + l[pos]);
        return;
    }
    if (tight)
    {
        bitmask(0, pos + 1, val + m + 2);
        bitmask(1, pos + 1, val + 2 * r[pos] + 1);
    }
    else
    {
        bitmask(0, pos + 1, val + 2 * l[pos] + 1);
        bitmask(1, pos + 1, val + m + 2);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif cin >> n >> m;
    for (int i = n - 1; i >= 0; i--)
    {
        cin >> s[i];
    }
    int tmp = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < s[i].length(); j++)
        {
            if (s[i][j] == '1')
                l[i] = max(j, l[i]);
            if (s[i][m + 1 - j] == '1')
                r[i] = max(r[i], j);
        }
        if (l[i])
            tmp = i;
    }
    n = tmp + 1;
    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1)
    {
        cout << l[0] << endl;
        return 0;
    }
    ans = INT_MAX;
    bitmask(0, 1, 2 * l[0] + 1);
    bitmask(1, 1, m + 2);
    cout << ans << endl;
    return 0;
}