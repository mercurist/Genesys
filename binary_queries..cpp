#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    int a, b, c;

    while (q--)
    {
        cin >> a;
        if (a == 0)
        {
            cin >> b >> c;
            if (numbers[c - 1] == 1)
                cout << "ODD" << '\n';
            else
                cout << "EVEN" << '\n';
        }
        else
        {
            cin >> b;
            numbers[b - 1] = 1 - numbers[b - 1];
        }
    }

    return 0;
}