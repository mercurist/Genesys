#include <bits/stdc++.h>
using namespace std;

int longestCommon(string s1, string s2)
{
    int l1 = s1.size();
    int l2 = s2.size();

    int dp[100][100];
    for (int i = 0; i <= l1; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= l2; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1])));
        }
    }

    return dp[l1][l2];
}

int dp[1000][1000][100];
int n;
int m;
int topDownLongestCommon(string s1, string s2, int i, int j, int k)
{
    if (i == n || j == m)
        return 0;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    int res = 0;
    if (s1[i] == s2[j])
        res = 1 + topDownLongestCommon(s1, s2, i + 1, j + 1, k);
    else
    {
        if (k > 0)
            res = 1 + topDownLongestCommon(s1, s2, i + 1, j + 1, k - 1);
        res = max(res, topDownLongestCommon(s1, s2, i, j + 1, k));
        res = max(res, topDownLongestCommon(s1, s2, i + 1, j, k));
    }

    dp[i][j][k] = res;
    return res;
}

int main()
{
    int k;
    memset(dp, -1, sizeof(dp));
    string s1, s2;
    cin >> s1 >> s2 >> k;
    n = s1.size();
    m = s2.size();

    cout << longestCommon(s1, s2) << '\n';
    cout << topDownLongestCommon(s1, s2, 0, 0, k);

    return 0;
}