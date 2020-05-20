#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <unordered_map>

using namespace std;

class graph
{
    int number_of_vertices;
    list<int> *adjacency_list;

public:
    graph(int input)
    {
        number_of_vertices = input;
        adjacency_list = new list<int>[number_of_vertices];
    }

    void addEdge(int start, int end, bool isDirectional = false)
    {
        adjacency_list[start].push_back(end);
        if (isDirectional == false)
            adjacency_list[end].push_back(start);
    }

    void display()
    {
        for (int i = 0; i < number_of_vertices; i++)
        {
            cout << i;
            for (int node : adjacency_list[i])
                cout << " -> " << node;
            cout << '\n';
        }
    }

    void bfs(int source)
    {
        unordered_map<int, bool> visited;
        cout << '\n';
        queue<int> BFSqueue;
        BFSqueue.push(source);
        visited[source] = true;

        while (BFSqueue.empty() == false)
        {
            int front = BFSqueue.front();

            cout << front << " ";

            BFSqueue.pop();
            for (int node : adjacency_list[front])
            {
                if (visited.count(node) == 0)
                {
                    BFSqueue.push(node);
                    visited[node] = true;
                }
            }
        }
    }
};

int main()
{
    graph g(6);
    /*
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    */
    // g.addEdge(0, 1);         the same end vertex is added twice

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.display();
    g.bfs(0);

    return 0;
}