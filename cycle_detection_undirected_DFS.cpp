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

    bool isCyclicDFSHelper(int node, map<int, bool> &visited, int parent)
    {
        visited[node] = true;

        for (auto neighbour : adjacency[node])
        {
            if (visited[neighbour] == false)
            {
                if (isCyclicDFSHelper(neighbour, visited, node))
                    return true;
            }
            else if (neighbour != parent)
                return true;
        }

        return false;
    }

    bool isCyclicDFS()
    {
        map<int, bool> visited;

        for (int i = 0; i < number_of_vertices; i++)
            if (visited[i] == false)
                if (isCyclicDFSHelper(visited[i], visited, visited[i]))
                    return true;

        return false;
    }
};

int main()
{
    graph g(6);

    g.add_edge(0, 2);
    // g.add_edge(1, 2);
    g.add_edge(0, 5);
    g.add_edge(5, 4);
    g.add_edge(1, 3);
    g.add_edge(2, 4);
    g.add_edge(3, 4);

    if (g.isCyclicDFS())
        cout << "cyclic" << '\n';
    else
    {
        cout << "acyclic";
    }

    return 0;
}