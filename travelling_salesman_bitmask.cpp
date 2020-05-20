#include <bits/stdc++.h>

using namespace std;

const int n = 4;
int visited_overall = (1 << n) - 1;

int adjacency[n][n] =
    {
        0, 20, 42, 25,
        20, 0, 30, 34,
        42, 30, 0, 10,
        25, 34, 10, 0};

int tsp(int mask, int current_position)
{
    if (mask == visited_overall)
        return adjacency[current_position][0];

    int ans = INT_MAX;
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int new_answer = adjacency[current_position][city] + tsp((mask | (1 << city)), city);
            ans = min(ans, new_answer);
        }
    }

    return ans;
}

int main()
{
    cout << "minimum distance travelled = " << tsp(1, 0);
    return 0;
}