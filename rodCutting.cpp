#include <bits/stdc++.h>
using namespace std;

int memo[100];
// Exponential Time Complexity = O(totalLen^(k))
int maxProfit(int arr[], int totalLen)
{
    int best = 0;
    if (totalLen <= 0)
        return 0;

    // if (memo[totalLen] != -1)
    // return memo[totalLen];
    for (int len = 1; len <= totalLen; len++)
    {
        int netProfit = arr[len] + maxProfit(arr, totalLen - len);
        best = max(best, netProfit);
    }

    // memo[totalLen] = best;
    return best;
}

int maxProfitWithMemo(int arr[], int totalLen)
{
    int best = 0;
    if (totalLen <= 0)
        return 0;

    if (memo[totalLen] != -1)
        return memo[totalLen];
    for (int len = 1; len <= totalLen; len++)
    {
        int netProfit = arr[len] + maxProfit(arr, totalLen - len);
        best = max(best, netProfit);
    }

    memo[totalLen] = best;
    return best;
}

int maxProfitBottomUp(int arr[], int totalLen)
{
    int dp[100];
    dp[0] = 0;
    for (int len = 1; len <= totalLen; len++)
    {
        int best = 0;
        for (int cut = 1; cut <= len; cut++)
        {
            best = max(best, arr[cut] + dp[len - cut]);
        }
        dp[len] = best;
    }
    return dp[totalLen];
}

int main()
{
    memset(memo, -1, sizeof(memo));
    int priceOfEachLen[100];
    memset(priceOfEachLen, -1, sizeof(priceOfEachLen));
    int totalLen;
    cin >> totalLen;
    for (int i = 0; i < totalLen; i++)
        cin >> priceOfEachLen[i + 1];

    // cout << maxProfit(priceOfEachLen, totalLen) << '\n';
    // cout << maxProfitWithMemo(priceOfEachLen, totalLen) << '\n';
    cout << maxProfitBottomUp(priceOfEachLen, totalLen) << '\n';

    return 0;
}