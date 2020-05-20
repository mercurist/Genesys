#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool isConfigurationValid(ll *position, ll medium, ll N, ll C)
{
    bool lastAlloted = true; // allot the first cow at the first stall
    ll noOfAllotedCows = 1;
    ll distanceOfIncomingStall;

    for (ll i = 0; i < N - 1; i++)
    {
        if (lastAlloted == true)
        {
            distanceOfIncomingStall = position[i + 1] - position[i];
        }
        else
        {
            distanceOfIncomingStall += position[i + 1] - position[i];
        }

        if (distanceOfIncomingStall >= medium)
        {
            noOfAllotedCows++;
            lastAlloted = true;
        }
        else
        {
            lastAlloted = false;
        }

        if (noOfAllotedCows == C)
            return true;
    }

    return false;
}

bool isConfigurationValidAgain(ll *position, ll medium, ll N, ll C)
{
    ll cows = 1, pos = position[0];

    for (int i = 1; i < N; i++)
    {
        if (position[i] - pos >= medium)
        {
            cows++;
            if (cows == C)
                return 1;
            pos = position[i];
        }
    }

    return 0;
}

ll largestMinimumDistance(ll *position, ll minimumDistance, ll maximumDistance, ll N, ll C)
{
    ll result = -1;
    while (minimumDistance <= maximumDistance)
    {
        ll medium = (minimumDistance + maximumDistance) / 2;
        if (isConfigurationValid(position, medium, N, C))
        {
            if (medium > result)
                result = medium;
            minimumDistance = medium + 1;
        }
        else
        {
            maximumDistance = medium;
        }
    }

    return result;
}

ll bs(ll *position, ll N, ll C)
{
    int ini = 0, last = position[N - 1], ans = -1;
    while (last > ini)
    {
        int mid = (ini + last) / 2;
        if (isConfigurationValidAgain(position, mid, N, C))
        {
            if (mid > ans)
                ans = mid;
            ini = mid + 1;
        }
        else
        {
            last = mid;
        }
    }

    return ans;
}

int main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, N, C;
    cin >> t;
    while (t--)
    {
        cin >> N >> C;
        ll *position = new ll[N];

        for (ll i = 0; i < N; i++)
            cin >> position[i];

        sort(position, position + N);
        // calculate maximum and minimum distance between adjacent cows
        ll minimumDistance = position[1] - position[0];
        ll maximumDistance = position[1] - position[0];

        for (ll i = 1; i < N - 1; i++)
        {
            minimumDistance = min(minimumDistance, position[i + 1] - position[i]);
            maximumDistance = max(maximumDistance, position[i + 1] - position[i]);
        }

        cout << largestMinimumDistance(position, minimumDistance, maximumDistance, N, C) << '\n';
        // cout << bs(position, N, C) << '\n';
    }
    return EXIT_SUCCESS;
}