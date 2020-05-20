#include <bits/stdc++.h>

using namespace std;

class graph
{
    map<int, list<int>> adjacency_list;

public:
    void addEdge(int u, int v, bool bidir = true)
    {
        adjacency_list[u].push_back(v);
        if (bidir == true)
            adjacency_list[v].push_back(u);
    }

    vector<int> single_source_shortest_path(int source)
    {
        vector<int> result;
        result.resize(adjacency_list.size());

        queue<int> traversal;
        map<int, bool> visited;
        traversal.push(source);
        visited[source] = true;
        result[source] = 0;

        while (traversal.empty() == false)
        {
            int node = traversal.front();
            traversal.pop();
            visited[node] = true;

            for (int neightbour : adjacency_list[node])
            {
                if (visited.count(neightbour) == 0)
                {
                    result[neightbour] = result[node] + 1;
                    traversal.push(neightbour);
                    visited[neightbour] = true;
                }
            }
        }

        return result;
    }
};

int main()
{
    graph g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 4);

    int source;
    cin >> source;
    vector<int> shortest_path = g.single_source_shortest_path(source);

    for (int i = 0; i < shortest_path.size(); i++)
        if (i != source)
            cout << "distance of " << i << " from " << source << " is " << shortest_path[i] << '\n';

    return 0;
}