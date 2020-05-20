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
        adjacency = new list<int>[number_of_vertices];
    }

    void addEdge(int u, int v, bool bidir = true)
    {
        adjacency[u].push_back(v);
        if (bidir == true)
            adjacency[v].push_back(u);
    }

    void depth_first_search(int source)
    {
        bool *visited = new bool[number_of_vertices];
        for (int i = 0; i < number_of_vertices; i++)
            visited[i] = false;

        int components = 0;
        depth_first_search_utility(source, visited);
        components++;

        for (int i = 0; i < number_of_vertices; i++)
            if (visited[i] == false)
            {
                components++;
                cout << '\n';
                depth_first_search_utility(i, visited);
            }

        cout << "\nthe graph has 2 components.";
    }

    void depth_first_search_utility(int source, bool *visited)
    {
        cout << source << " ";
        visited[source] = true;

        list<int>::iterator itr;
        for (itr = adjacency[source].begin(); itr != adjacency[source].end(); itr++)
            if (visited[*itr] == false)
                depth_first_search_utility(*itr, visited);
    }
};

int main()
{
    graph g(10);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 4);

    // disconnected graph

    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(6, 8);
    g.addEdge(6, 9);

    int source;
    cin >> source;

    g.depth_first_search(source);

    return 0;
}