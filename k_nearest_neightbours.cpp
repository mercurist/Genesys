#include <bits/stdc++.h>
#define ll long long int
using namespace std;

pair<ll, ll> point_of_focus;
bool myCompare(pair<ll, ll> first_point, pair<ll, ll> second_point)
{
    ll distance_one = (first_point.first - point_of_focus.first) * (first_point.first - point_of_focus.first) + (first_point.second - point_of_focus.second) * (first_point.second - point_of_focus.second);

    ll distance_two = (second_point.first - point_of_focus.first) * (second_point.first - point_of_focus.first) + (second_point.second - point_of_focus.second) * (second_point.second - point_of_focus.second);

    return (distance_one < distance_two);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    ll test_cases, number_of_points, k;
    vector<pair<ll, ll>> points;

    cin >> test_cases;
    ll x, y;
    while (test_cases--)
    {
        points.clear();
        cin >> number_of_points;

        cin >> point_of_focus.first >> point_of_focus.second;
        cin >> k;

        for (int i = 0; i < number_of_points; i++)
        {
            cin >> x >> y;
            points.push_back(make_pair(x, y));
        }

        sort(points.begin(), points.end(), myCompare);

        for (int i = 0; i < k; i++)
            cout << points[i].first << " " << points[i].second << '\n';
    }
    return 0;
}