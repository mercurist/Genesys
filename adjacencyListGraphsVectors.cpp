/*
We use dynamic arrays( vector in C++) to represent adjacency list instead of linked lists. This vector implementation has its own advantages of cache friendliness. 
*/

#include <iostream>
#include <vector>

using namespace std;

void addEdge( vector<int> adjacency[], int u, int v)
{
    // both statements since the graph is not directed.
    adjacency[u].push_back(v);
    adjacency[v].push_back(u);      
}

void displayAdjacencyList( vector<int> adjacency[])
{
    for( int i = 0; i < 5; i++)
    {
        cout << "Adjacency list for vertex " << i << " is \n";
        cout << "head";
        for( auto x : adjacency[i])
        {
            cout << " -> " << x;
        }
        
        cout << "\n";
    }
}

int main()
{
    int V = 5;
    vector<int> adjacency[V];
    addEdge( adjacency, 0, 1);
    addEdge( adjacency, 0, 4);
    addEdge( adjacency, 1, 2);
    addEdge( adjacency, 1, 3);
    addEdge( adjacency, 1, 4);
    addEdge( adjacency, 2, 3);
    addEdge( adjacency, 3, 4);

    displayAdjacencyList( adjacency);

    return EXIT_SUCCESS;
}