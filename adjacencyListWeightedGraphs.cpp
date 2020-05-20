/*
We use dynamic arrays( vector in C++) to represent adjacency list instead of linked lists. This vector implementation has its own advantages of cache friendliness. 
*/

#include <iostream>
#include <vector>

using namespace std;

void addEdge( vector< pair< int, int>> adjacency[], int u, int v, int z)
{
    // both statements since the graph is not directed.
    adjacency[u].push_back(make_pair(v, z));
    adjacency[v].push_back(make_pair(u, z));      
}

void displayAdjacencyList( vector< pair< int, int>> adjacency[])
{
    for( int i = 0; i < 5; i++)
    {
        cout << "Adjacency list for vertex " << i << " is \n";
        cout << "head";
        for( auto x : adjacency[i])
        {
            cout << " -> " << x.first << ", " << x.second;
        }
        
        cout << "\n";
    }
}

int main()
{
    int V = 5;
    vector< pair< int, int>> adjacency[V];
    addEdge( adjacency, 0, 1, 10);
    addEdge( adjacency, 0, 4, 20);
    addEdge( adjacency, 1, 2, 30);
    addEdge( adjacency, 1, 3, 40);
    addEdge( adjacency, 1, 4, 50);
    addEdge( adjacency, 2, 3, 60);
    addEdge( adjacency, 3, 4, 70);

    displayAdjacencyList( adjacency);

    return EXIT_SUCCESS;
}