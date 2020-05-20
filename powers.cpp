#include <iostream>
#include <vector>
// #include <cstring>
using namespace std;

int longestIncreasingSubsequence(vector<int> powers, int i, int j)
{
    int lengthOfSubarray = j - i + 1;
    vector<int> dp(lengthOfSubarray, 1);

    int result = -1;
    for (int k = i + 1; k <= j; k++)
    {
        for (int l = i; l < k; l++)
        {
            if (powers[l] <= powers[k])
                dp[k - i] = max(dp[k - i], dp[l - i] + 1);
            result = max(dp[k - i], result);
        }
    }
    return result;
}

int main()
{
    int testCases;
    int numSoldiers, numQueries;
    int typeOfQuery;
    int x, y;
    vector<int> powers;
    cin >> testCases;
    while (testCases--)
    {
        cin >> numSoldiers >> numQueries;
        powers.resize(numSoldiers);
        for (int i = 0; i < numSoldiers; i++)
            cin >> powers[i];
        while (numQueries--)
        {
            cin >> typeOfQuery;
            if (typeOfQuery == 1)
            {
                cin >> x >> y;
                // check for indexing
                powers[x - 1] += y;
            }
            else
            {
                cin >> x >> y;
                cout << longestIncreasingSubsequence(powers, x - 1, y - 1) << '\n';
            }
        }
    }
    return 0;
}