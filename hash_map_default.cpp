#include <bits/stdc++.h>
using namespace std;

int main()
{
    string list[10];
    map<string, int> counts;

    for (int i = 0; i < 10; i++)
    {
        cin >> list[i];
        counts[list[i]]++;
    }

    for (auto x : counts)
        cout << x.first << "\t" << x.second << '\n';
    return 0;
}