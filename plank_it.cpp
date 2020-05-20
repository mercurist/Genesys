#include <bits/stdc++.h>

using namespace std;

bool isConfigurationValid(vector<int> heights, int n, int max_height)
{
    // cout << "checking for " << max_height << '\n';
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (heights[i] >= max_height)
            count++;
        else
            break;
    }

    // cout << count << '\n';
    return (count >= max_height);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int k, n;
    cin >> k;
    vector<int> heights;

    int max_height;
    while (k--)
    {
        cin >> n;
        heights.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }

        sort(heights.begin(), heights.end());

        int i = n - 1;
        max_height = heights[i];
        while (i != 0)
        {
            if (isConfigurationValid(heights, n, max_height))
            {
                cout << max_height << '\n';
                break;
            }
            i--;
            max_height--;
        }
    }
    return 0;
}