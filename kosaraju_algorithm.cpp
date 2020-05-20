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

    void depth_first_helper(int source, bool *visited, int &count, list<int> *reversal)
    {
        visited[source] = true;
        count++;

        for (auto neighbour : reversal[source])
        {
            if (visited[neighbour] == false)
                depth_first_helper(neighbour, visited, count, reversal);
        }
    }

    bool kosaraju_algorithm()
    {
        bool *visited = new bool[number_of_vertices];
        for (int i = 0; i < number_of_vertices; i++)
            visited[i] = false;

        int count = 0;
        depth_first_helper(0, visited, count);
        if (count == number_of_vertices)
            return true;

        for (int i = 0; i < number_of_vertices; i++)
            visited[i] = false;

        // reversing the list
        list<int> *reverse_adjacency_list = reverse_edges();

        count = 0;
        depth_first_helper(0, visited, count, reverse_adjacency_list);
        if (count == number_of_vertices)
            return true;

        return false;
    }

    list<int> *reverse_edges()
    {
        list<int> *reverse_adjacency_list = new list<int>[number_of_vertices];

        for (int i = 0; i < number_of_vertices; i++)
        {
            for (auto neighbour : adjacency_list[i])
                reverse_adjacency_list[neighbour].push_back(neighbour);
        }

        return reverse_adjacency_list;
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
    // g.add_edge(3, 0, false);
    /*
    // BIDIRECTIONAL EDGES
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    // g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 5);
    g.add_edge(5, 3);
    // g.add_edge(3, 0);
*/

    if (g.kosaraju_algorithm())
        cout << "strongly connected" << '\n';
    else
        cout << "not so much" << '\n';

    return 0;
}