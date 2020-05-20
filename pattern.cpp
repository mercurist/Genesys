#include <bits/stdc++.h>
using namespace std;

void naziPattern(int n)
{
    int c;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            cout << "*";
            for (c = 0; c < (n / 2) - 1; c++)
                cout << " ";
            for (c = 0; c <= (n / 2); c++)
                cout << "*";
            cout << '\n';
            continue;
        }

        if (i == n - 1)
        {
            cout << "*";
            for (c = 0; c <= (n / 2) - 1; c++)
                cout << "*";
            for (c = 0; c < (n / 2) - 1; c++)
                cout << " ";
            cout << "*";
            cout << '\n';
            continue;
        }

        if (i == n / 2)
        {
            for (c = 0; c < n; c++)
                cout << "*";
            cout << '\n';
            continue;
        }

        if (i > 0 && i < n / 2)
        {
            cout << "*";
            for (c = 0; c < (n / 2) - 1; c++)
                cout << " ";
            cout << "*\n";
        }

        if (i > n / 2 && i < n - 1)
        {
            cout << " ";
            for (c = 0; c < (n / 2) - 1; c++)
                cout << " ";
            cout << "*";
            for (c = 0; c < (n / 2) - 1; c++)
                cout << " ";
            cout << "*\n";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    naziPattern(n);
    return 0;
}