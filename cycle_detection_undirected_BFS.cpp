#include <bits/stdc++.h>

using namespace std;

class graph
{
    int number_of_vertices;
    list<int> *adjacency;

public:
    graph(int v)
    {
        number_of_vertices = v;
        adjacency = new list<int>[v];
    }

    void add_edge(int u, int v, bool bidir = true)
    {
        adjacency[u].push_back(v);
        if (bidir == true)
            adjacency[v].push_back(u);
    }

    void isCyclic(int source)
    {
        bool *visited = new bool[number_of_vertices];
        for (int i = 0; i < number_of_vertices; i++)
            visited[i] = false;

        map<int, int> parent;

        queue<int> order;
        order.push(source);
        visited[source] = true;
        parent[source] = source;

        while (order.empty() == false)
        {
            int node = order.front();
            order.pop();

            for (auto neighbour : adjacency[node])
            {
                if (visited[neighbour] == true && parent[node] != neighbour)
                {
                    cout << "cyclic" << '\n';
                    return;
                }
                else if (visited[neighbour] == false)
                {
                    parent[neighbour] = node;
                    visited[neighbour] = true;
                    order.push(neighbour);
                }
            }
        }

        cout << "acyclic" << '\n';
    }
};

int main()
{
    graph g(6);

    // g.add_edge(0, 2);
    // g.add_edge(1, 2);
    g.add_edge(0, 5);
    g.add_edge(5, 4);
    g.add_edge(1, 3);
    g.add_edge(2, 4);
    g.add_edge(3, 4);

    g.isCyclic(0);

    return 0;
}