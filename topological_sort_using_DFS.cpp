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

    void add_edge(int u, int v)
    {
        adjacency[u].push_back(v);
    }

    list<int> depth_first_search(int source)
    {
        list<int> topology;
        bool *visited = new bool[number_of_vertices];
        for (int i = 0; i < number_of_vertices; i++)
            visited[i] = false;

        for (int i = 0; i < number_of_vertices; i++)
            if (visited[i] == false)
                depth_first_search_utility(i, visited, topology);

        return topology;
    }

    void depth_first_search_utility(int source, bool *visited, list<int> &topology)
    {
        visited[source] = true;

        list<int>::iterator itr;
        for (itr = adjacency[source].begin(); itr != adjacency[source].end(); itr++)
        {
            if (visited[*itr] == false)
                depth_first_search_utility(*itr, visited, topology);
        }

        topology.push_front(source);
    }
};

int main()
{

    graph g(9);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(0, 3);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 5);
    g.add_edge(5, 6);
    g.add_edge(2, 5);
    g.add_edge(2, 8);
    g.add_edge(8, 6);
    g.add_edge(7, 6);
    g.add_edge(2, 7);

    int source = 0;
    list<int> topology = g.depth_first_search(source);
    for (auto x : topology)
        cout << x << " ";

    return 0;
}