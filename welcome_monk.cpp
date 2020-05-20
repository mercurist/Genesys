#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> list_one(n), list_two(n);
    for (int i = 0; i < n; i++)
        cin >> list_one[i];
    for (int i = 0; i < n; i++)
        cin >> list_two[i];

    for (int i = 0; i < n; i++)
        cout << list_two[i] + list_one[i] << " ";

    return 0;
}
