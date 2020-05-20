#include <bits/stdc++.h>

using namespace std;

class graph
{
    int number_of_vertices;
    list<int> *adjacency;
    int *indegree;

public:
    graph(int v)
    {
        number_of_vertices = v;
        adjacency = new list<int>[v];
        indegree = new int[v]{0};
    }

    void add_edge(int u, int v)
    {
        adjacency[u].push_back(v);
        indegree[v]++;
    }

    void topology()
    {
        // Kahn's algorithm
        queue<int> order;
        for (int i = 0; i < number_of_vertices; i++)
            if (indegree[i] == 0)
                order.push(i);

        while (order.empty() == false)
        {
            int node = order.front();
            order.pop();
            cout << node << " ";

            for (auto neighbour : adjacency[node])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                    order.push(neighbour);
            }
        }
    }
};

int main()
{
    graph g(6);

    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(0, 5);
    g.add_edge(5, 4);
    g.add_edge(1, 3);
    g.add_edge(2, 4);
    g.add_edge(3, 4);

    g.topology();

    return 0;
}