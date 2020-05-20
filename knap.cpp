#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weights, vector<int> values, int W, int N)
{
    int K[1005][1005];
    for (int i = 0; i <= N; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);

            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[N][W];
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        int w;
        cin >> n >> w;
        vector<int> weights(n);
        vector<int> values(n);
        for (int i = 0; i < n; i++)
        {
            cin >> weights[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> values[i];
        }

        cout << knapsack(weights, values, w, n) << '\n';
    }
    return 0;
}