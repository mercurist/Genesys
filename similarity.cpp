#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int n, count = 0;
    cin >> n;
    vector<int> numbers(n);

    map<int, list<int>> indices;

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        indices[numbers[i]].push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        for (auto itr : indices[numbers[i] - 1])
        {
            if (itr > i)
            {
                cout << "pair (" << i << ", " << itr << ")" << '\n';
                count++;
            }
        }

        for (auto itr : indices[numbers[i] + 1])
        {
            if (itr > i)
            {
                cout << "pair (" << i << ", " << itr << ")" << '\n';
                count++;
            }
        }
    }

    cout << count << '\n';

    return 0;
}