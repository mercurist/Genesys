#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

class graph
{
public:
    int v;
    list<pair<int, int>> *adjacency_list;

    graph(int v)
    {
        this->v = v;
        adjacency_list = new list<pair<int, int>>[v];
    }

    void add_edge(int u, int v, int weight)
    {
        adjacency_list[u].push_back(make_pair(v, weight));
        adjacency_list[v].push_back(make_pair(u, weight));
    }

    int find_min_weight_vertex(int *weight, bool *visited)
    {
        int index = -1;
        const int smallest = (1e9) + 1;
        for (int i = 0; i < v; i++)
        {
            if (visited[i] == false)
                if (weight[i] < smallest)
                    index = i;
        }

        return index;
    }

    void prims()
    {
        bool *visited = new bool[v];
        int *parent = new int[v];
        int *weight = new int[v];

        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
            weight[i] = inf;
        }

        // starting parameters
        parent[0] = -1;
        weight[0] = 0;

        /*

    flag can be used to indicate when there are some vertices left for visiting
    or we can use min_weight_vertex value to be -1 when there are no vertices left for visiting
        while (true)
        {
            int min_weight_vertex = find_min_weight_vertex(weight, visited);
            if (min_weight_vertex == -1)
                break 
            for (auto x : adjacency_list[min_weight_vertex] )
            {
                if (visited[x] == false )
                    x = pair
                    x.first = the destination vertex
                    x.second = weight

                    if (x.second < weight[x.first])
                    {
                        weight[x.first] = x.second
                        parent[x.first] = min_weight_vertex
                    }
            }

            visited[min_weight_vertex] = true

        }
        */

        for (int i = 0; i < v; i++)
        {
            int min_weight_vertex = find_min_weight_vertex(weight, visited);
            visited[min_weight_vertex] = true;

            for (auto neighbour : adjacency_list[min_weight_vertex])
            {
                if (visited[neighbour.first] == false)
                {
                    if (neighbour.second < weight[neighbour.first])
                    {
                        weight[neighbour.first] = neighbour.second;
                        parent[neighbour.first] = min_weight_vertex;
                    }
                }
            }
        }

        for (int i = 1; i < v; i++)
        {
            cout << i << " -- " << parent[i] << " with weight " << weight[i] << endl;
        }
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    graph g(n);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }

    g.prims();
    return 0;
}