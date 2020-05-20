#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[7] = {13, 27, 35, 40, 49, 55, 59};
    int b[7] = {17, 35, 39, 40, 55, 58, 60};

    map<int, int> counts;

    for (int i = 0; i < 7; i++)
        counts[b[i]]++;

    int result = 0;
    for (int i = 0; i < 7; i++)
        result += counts[a[i]];

    cout << result;
    return 0;
}