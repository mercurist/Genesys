#include <bits/stdc++.h>
using namespace std;


void sequences(int n, int a, int b, int k, int &count)
{
    if ( a > n)
        return;
    if ( a < 0)
        return;
    if ( k == 0)
    {
        count++;
        return;
    }
    int range = abs(a-b);
    for(int i = 1; i < range; i++)
    {
        sequences(n, a+i, b, k-1, count);
        sequences(n, a-i, b, k-1, count);
    }
}

int main()
{
    int n,a,b,k, count= 0;
    cin >> n >> a >> b >> k;

    sequences( n, a, b, k, count);

    cout << count << '\n';
    return EXIT_SUCCESS;
}