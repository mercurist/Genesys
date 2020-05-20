#include <iostream>
#include <map>
#include <list>
#include <queue>
#define N 36

using namespace std;

int board[37] = {0,
                 0, 13, 0, 0, 2, 0,
                 0, 0, 18, 0, 0, 0,
                 0, 0, 0, 0, -13, 11,
                 0, -14, 0, 0, 0, -8,
                 10, 0, 0, 0, 0, 0,
                 0, -2, 0, -22, 0, 0};

class graph
{
private:
    map<int, list<int>> adjacency_list;

public:
    void buildGraph()
    {
        int starting_position = 0, final_position = 36;
        // sample space for the die is 1,2,3,4,5,6

        for (int i = 0; i <= 35; i++)
        {
            if (board[i] != 0)
                continue;

            for (int j = 1; j <= 6; j++)
            {
                if (i + j <= 36)
                    adjacency_list[i].push_back(i + j + board[i + j]);
            }
        }
    }

    void bfs(int source)
    {
        bool *visited = new bool[37];
        for (int i = 0; i < 37; i++)
            visited[i] = false;
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
                if (visited[node] == false)
                {
                    BFSqueue.push(node);
                    visited[node] = true;
                }
            }
        }
    }

    void shortestPath(int source)
    {
        cout << '\n';
        bool visited[37];
        int parent[37];
        int distance[37] = {0};

        for (int i = 0; i < 37; i++)
        {
            visited[i] = false;
            parent[i] = -1;
        }
        queue<int> BFSqueue;

        BFSqueue.push(source);
        visited[source] = true;

        while (BFSqueue.empty() == false)
        {
            int front = BFSqueue.front();
            BFSqueue.pop();

            for (int node : adjacency_list[front])
            {
                if (visited[node] == false)
                {
                    BFSqueue.push(node);
                    visited[node] = true;
                    distance[node] = distance[front] + 1;
                    parent[node] = front;
                }
            }
        }

        vector<int> route;
        cout << distance[36] << '\n';
        int x = 36;
        while (x != 0)
        {
            route.push_back(x);
            x = parent[x];
        }

        cout << 0;
        for (int i = route.size() - 1; i >= 0; i--)
            cout << " -> " << route[i];
    }

    void print()
    {
        for (int i = 0; i <= 36; i++)
        {
            cout << '\n'
                 << i;
            for (int node : adjacency_list[i])
                cout << " -> " << node;
        }
    }
};

int main()
{
    graph g;
    g.buildGraph();
    // g.bfs(0);
    // g.shortestPath(0);
    g.print();
    return 0;
}