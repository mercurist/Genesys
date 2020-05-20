#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        float x = a.second / a.first;
        float y = b.second / b.first;
        return x >= y;
    }
} cmp;

int main()
{
    int n, capacity, weight, price;
    cin >> n >> capacity;
    vector<pair<int, int>> grocery;
    for (int i = 0; i < n; i++)
    {
        cin >> weight >> price;
        grocery.push_back(make_pair(weight, price));
    }

    int result = 0;
    // sorting in descending order
    sort(grocery.begin(), grocery.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        if (capacity >= grocery[i].first)
        {
            capacity -= grocery[i].first;
            result += grocery[i].second;
        }
        else
        {
            result += (grocery[i].second * capacity) / grocery[i].first;
            break;
        }
    }
    cout << result << '\n';
    return 0;
}