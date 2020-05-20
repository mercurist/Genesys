/*
you are given a linear equation
y = mx + c
and an array of n elements. Count the number of ordered pairs (i, j) where i!=j such that poll (Ai, Aj) satisfies the given linear equation
*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool isValid(vector<ll> elements, ll i, ll j, ll m, ll c)
{
    if (i == j)
        return false;

    return (elements[j] == (m * elements[i] + c));
}

ll bruteForce(vector<ll> elements, ll n, ll m, ll c)
{
    ll counter = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (isValid(elements, i, j, m, c))
                counter++;
        }
    }
    return counter;
}

// efficient solution by mallaining an unordered_map
ll findOrderedPairs(vector<ll> elements, ll n, ll m, ll c)
{
    ll counter = 0;
    unordered_map<ll, ll> frequency;
    for (ll i = 0; i < n; i++)
        frequency[elements[i]]++;

    for (ll i = 0; i < n; i++)
    {
        ll xCoordinate = i;
        ll yCoordinate = m * i + c;
        if (frequency.find(yCoordinate) != frequency.end())
            counter += frequency[yCoordinate];

        if (xCoordinate == yCoordinate)
            counter--;
    }

    return counter;
}

int main()
{
    ll m, c, n;
    vector<ll> elements;
    cin >> n >> m >> c;
    elements.resize(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> elements[i];
    }

    // cout << bruteForce(elements, n, m, c);
    cout << findOrderedPairs(elements, n, m, c);
    return EXIT_SUCCESS;
}