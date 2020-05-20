#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

class edge
{
public:
    int src, dest, weight;
};

class graph
{
public:
    int v, e;
    edge *edges;

    graph(int v, int e)
    {
        this->v = v;
        this->e = e;
        edges = new edge[e];
    }

    void add_edge(int u, int v, int w, int count)
    {
        edges[count].src = u;
        edges[count].dest = v;
        edges[count].weight = w;
    }

    void bellman_ford(int source)
    {
        int distance[v];
        for (int i = 0; i < v; i++)
        {
            if (i == source)
                distance[i] = 0;
            else
                distance[i] = inf;
        }

        for (int i = 0; i < v - 1; i++)
        {
            for (int j = 0; j < e; j++)
            {
                // relaxation check
                if ((distance[edges[j].dest] > (distance[edges[j].src] + edges[j].weight)) and distance[edges[j].src] != inf)
                    distance[edges[j].dest] = (distance[edges[j].src] + edges[j].weight);
            }
        }

        bool contains_cycle = false;
        // check for negative weight cycles
        for (int j = 0; j < e; j++)
        {
            // relaxation check
            if ((distance[edges[j].dest] > (distance[edges[j].src] + edges[j].weight)) and distance[edges[j].src] != inf)
                contains_cycle = true;
        }

        if (contains_cycle)
        {
            cout << "the graph contains a cycle" << '\n';
            return;
        }
        else
        {
            for (int i = 0; i < v; i++)
            {
                if (i != source)
                {
                    cout << source << " to " << i << " at distance " << distance[i];
                    cout << '\n';
                }
            }
        }
    }
};

int main()
{
    int v, e;
    cin >> v >> e;
    graph g(v, e);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, w, i);
    }
    int source;
    cin >> source;
    g.bellman_ford(source);

    return 0;
}

/*
input
5 8
0 1 -1
0 2 4
1 2 3
3 2 5
4 3 -3
1 4 2
1 3 2
3 1 1
0
*/