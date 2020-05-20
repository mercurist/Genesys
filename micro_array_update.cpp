#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k;
    int min = 1e7;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> list_one(n);
        for (int i = 0; i < n; i++)
        {
            cin >> list_one[i];
            if (list_one[i] < min)
                min = list_one[i];
        }

        if (min <= k)
            cout << k - min << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}