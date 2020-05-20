#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
const int mxN = 30;
string s[mxN], ans;
vector<int> adj[26];
bool bad;
bool act[26], vis[26];

void dfs(int u)
{
    vis[u] = 1;
    act[u] = 1;
    for (int v : adj[u])
    {
        // if there is a cycle in the graph
        // basically what the following statement is saying is that
        // suppose we start a vertex denoted by v, then act[v] = 1;
        // and then we go to a neighbouring node, and in this node if we find act[v], this will be 1 and if we are having a node from u back to v.
        // in this instance, both v and u are different.
        if (act[v] && v ^ u)
            bad = 1;
        else
        {
            if (vis[v] == false)
                dfs(v);
        }
    }
    act[u] = 0;
    ans += (char)(u + 'A');
}

void solve()
{
    cin >> n >> m;
    set<char> t;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (char c : s[i])
            t.insert(c);
        if (i)
        {
            for (int j = 0; j < m; j++)
            {
                adj[s[i - 1][j] - 'A'].push_back(s[i][j] - 'A');
            }
        }
    }

    memset(vis, 0, 26);
    memset(act, 0, 26);
    ans = "";
    bad = 0;
    for (char c : t)
        if (vis[c - 'A'] == false)
            dfs(c - 'A');

    if (bad)
        ans = "-1";
    cout << ans << '\n';
    for (int i = 0; i < 26; i++)
        adj[i].clear();
}

int32_t main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}