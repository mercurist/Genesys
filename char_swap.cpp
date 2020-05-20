#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    cin >> k;
    string s, t;
    while (k--)
    {
        cin >> n;
        cin >> s >> t;

        int flag = 0;
        int p, q, mismatch = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[i])
            {
                mismatch++;
                if (mismatch == 1)
                    p = i;
                if (mismatch == 2)
                    q = i;
                if (mismatch > 2)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1 || mismatch == 1)
        {
            cout << "No" << '\n';
            continue;
        }

        if (mismatch == 0)
        {
            cout << "Yes" << '\n';
            continue;
        }

        if (mismatch == 2 && (s[p] == s[q]) && (t[p] && t[q]))
        {
            cout << "Yes" << '\n';
        }
    }
    return 0;
}