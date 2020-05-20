#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define N 1000005

int p[N];
void sieve()
{
    for (int i = 0; i <= N; i++)
        p[i] = 1;
    for (int i = 2; i <= N; i++)
    {
        if (p[i])
        {
            for (int j = 2 * i; j <= N; j += i)
                p[j] = 0;
        }
    }
}
int segmented_sieve(ll a, ll b)
{
    sieve();
    bool pp[b - a + 1];
    memset(pp, 1, sizeof(pp));
    for (long long i = 2; i * i <= b; i++)
    {
        for (long long j = a; j <= b; j++)
        {
            if (p[i])
            {
                if (j == i)
                    continue;
                if (j % i == 0)
                    pp[j - a] = 0;
            }
        }
    }
    int result = 0;
    for (long long i = a; i < b; i++)
    {
        result += pp[i - a];
    }
    return result;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    cout << segmented_sieve(a, b) << '\n';
    return 0;
}