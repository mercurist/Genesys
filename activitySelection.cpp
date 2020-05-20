#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct compare
{
    bool operator()(pair<int, int> left, pair<int, int> right)
    {
        return left.second <= right.second;
    }

} cmp;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases, numberOfActivity, startTime, endTime, result;
    cin >> testCases;
    while (testCases--)
    {
        result = 0;
        vector<pair<int, int>> activity;
        cin >> numberOfActivity;
        for (int i = 0; i < numberOfActivity; i++)
        {
            cin >> startTime >> endTime;
            activity.push_back(make_pair(startTime, endTime));
        }

        sort(activity.begin(), activity.end(), cmp);
        if (numberOfActivity == 0)
        {
            cout << result << '\n';
            continue;
        }

        int prevFinish = activity[0].second;
        result++;
        for (int i = 1; i < numberOfActivity; i++)
        {
            if (activity[i].first >= prevFinish)
            {
                result++;
                prevFinish = activity[i].second;
            }
        }

        cout << result << '\n';
    }

    return 0;
}