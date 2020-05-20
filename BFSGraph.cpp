/*
Program to implement BFS traversal of a graph from a given source vertex.
BFS( int s) traverses vertices reachable from s.
*/

#include <iostream>
#include <list>

using namespace std;

/*
this class is used to represent adjacency list using linked lists. here, we may also choose to opt for a vector STL based implementation because of its cache friendliness.
*/

class Graph
{
private:
    int V;                      // no of vertices
    list<int> *adjacency;       // dynamic array of lists
public:
    Graph( int x);
    void addEdge( int v, int w);
    void BFS( int s);
};

Graph:: Graph( int x)
{
    this -> V = x;
    adjacency = new list<int> [V];
}

void Graph :: addEdge( int v, int w)
{
    adjacency[v].push_back(w);
}

void Graph :: BFS( int s)
{
    bool *visited = new bool[V];
    for( int i =0; i < V; i++)
        visited[i] = false;

    list<int> queue;
    visited[s] = true;
    queue.push_back(s);

    list<int> :: iterator itr;

    while ( queue.empty() == false)
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for( itr = adjacency[s].begin(); itr != adjacency[s].end(); itr++)
        {
            if ( visited[*itr] == false)
            {
                visited[*itr] = true;
                queue.push_back(*itr);
            }
        }
    }
}

int main()
{
    int testCases, noOfEdges, noOfNodes, first, second;
    cin >> testCases;
    while ( testCases--)
    {
        cin >> noOfNodes >> noOfEdges;
        Graph g( noOfNodes);
        for( int i = 0; i < noOfEdges; i++)
        {
            cin >> first >> second;
            g.addEdge( first, second);
        }
        g.BFS(0);
    }

    return EXIT_SUCCESS;
}