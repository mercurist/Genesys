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
        adjacency_list = new list<int>[v];
    }

    void add_edge(int u, int v)
    {
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }

    int thisComponent(int i, bool *visited)
    {
        int count = 1;
        queue<int> order;
        order.push(i);

        while (order.empty() == false)
        {
            int node = order.front();
            order.pop();
            visited[node] = true;

            for (auto neighbour : adjacency_list[node])
            {
                if (visited[neighbour] == false)
                {
                    order.push(neighbour);
                    count++;
                }
            }
        }

        return count;
    }

    void BFSkarwao(int n)
    {
        bool *visited = new bool[number_of_vertices];
        for (int i = 0; i < number_of_vertices; i++)
            visited[i] = false;

        vector<int> result;
        for (int i = 0; i < number_of_vertices; i++)
            if (visited[i] == false)
                result.push_back(thisComponent(i, visited));

        int selections = (n * (n - 1)) / 2;
        for (int i = 0; i < result.size(); i++)
        {
            int temp = (result[i] * (result[i] - 1)) / 2;
            selections -= temp;
        }

        cout << selections << '\n';
    }
};

int main()
{
    int n, p;
    cin >> n >> p;

    graph g(n);

    int u, v;
    for (int i = 0; i < p; i++)
    {
        cin >> u >> v;
        g.add_edge(u, v);
    }

    g.BFSkarwao(n);
    return 0;
}