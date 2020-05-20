#include <bits/stdc++.h>
using namespace std;

class graph
{
    int number_of_vertices;
    list<int> *adjacency_list;

public:
    graph(int v)
    {
        number_of_vertices = v;
        adjacency_list = new list<int>[number_of_vertices];
    }

    void add_edge(int u, int v, bool bidir = true)
    {
        adjacency_list[u].push_back(v);
        if (bidir == true)
            adjacency_list[v].push_back(u);
    }

    void depth_first_helper(int source, bool *visited, int &count)
    {
        visited[source] = true;
        count++;

        for (auto neighbour : adjacency_list[source])
        {
            if (visited[neighbour] == false)
                depth_first_helper(neighbour, visited, count);
        }
    }

    bool depth_first_traversal(int source)
    {
        bool *visited = new bool[number_of_vertices];
        for (int i = 0; i < number_of_vertices; i++)
            visited[i] = false;

        int count = 0;
        depth_first_helper(source, visited, count);
        return (count == number_of_vertices);
    }

    bool is_strongly_connected()
    {
        for (int i = 0; i < number_of_vertices; i++)
            if (depth_first_traversal(i) == false)
                return false;
        return true;
    }
};

int main()
{
    graph g(6);

    g.add_edge(0, 1, false);
    g.add_edge(1, 2, false);
    g.add_edge(2, 3, false);
    g.add_edge(3, 4, false);
    g.add_edge(4, 5, false);
    g.add_edge(5, 3, false);
    g.add_edge(3, 0, false);

    if (g.is_strongly_connected())
        cout << "strongly connected" << '\n';
    else
        cout << "not so much" << '\n';

    return 0;
}