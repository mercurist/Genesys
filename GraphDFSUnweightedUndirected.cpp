#include <iostream>
#include <vector>

using namespace std;

void addEdge( vector<int> adjacency[], int u, int v)
{
    adjacency[u].push_back(v);
    adjacency[v].push_back(u);
}

void printGraph( vector<int> adjacency[], int V)
{
    for( int i = 0; i < V; i++)
    {
        cout << "adjacency list for vertex " << i << " is\n";
        cout << "head";
        for ( auto x : adjacency[i])
        {
            cout << " -> " << x;
        }

        cout << '\n';
    }

    cout << '\n';
}

void DFSUtility( int u, vector<int> adjacency[], vector<bool> &visited)
{
    visited[u]= true;
    cout << u << " ";
    for( int i = 0; i < adjacency[u].size(); i++)
    {
        if ( visited[ adjacency[u][i]] == false)
            DFSUtility(adjacency[u][i], adjacency, visited);;
    }
}

void DFSNoWeight( vector<int> adjacency[], int V)
{
    vector <bool> visited(V, false);
    for( int u = 0 ; u < V; u++)
    {
        if( visited[u] == false)
            DFSUtility(u, adjacency, visited);
    }
}

int main()
{
    int V = 5;
    /* 
    the following line may not work on all compilers.
    Use this instead - vector<int> *adjacency = new vector<int>[V];
    */
    vector<int> adjacency[V];
    addEdge(adjacency, 0, 1); 
    addEdge(adjacency, 0, 4); 
    addEdge(adjacency, 1, 2); 
    addEdge(adjacency, 1, 3); 
    addEdge(adjacency, 1, 4); 
    addEdge(adjacency, 2, 3);
    addEdge(adjacency, 3, 4);

    printGraph( adjacency, V);
    DFSNoWeight( adjacency, V);
    
    return EXIT_SUCCESS;
}