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

    void addEdge(int u, int v)
    {
        adjacency[u].push_back(v);
    }

    bool isCyclic()
    {
        bool *visited = new bool[number_of_vertices];
        bool *recursion_stack = new bool[number_of_vertices];

        for (int i = 0; i < number_of_vertices; i++)
        {
            visited[i] = false;
            recursion_stack[i] = false;
        }

        for (int i = 0; i < number_of_vertices; i++)
            if (isCyclicUtility(i, visited, recursion_stack))
                return true;
        return false;
    }

    bool isCyclicUtility(int v, bool *visited, bool *recursion_stack)
    {
        if (visited[v] == false)
        {
            visited[v] = true;
            recursion_stack[v] = true;

            list<int>::iterator itr;
            for (itr = adjacency[v].begin(); itr != adjacency[v].end(); itr++)
            {
                if (visited[*itr] == false && isCyclicUtility(*itr, visited, recursion_stack))
                    return true;

                else if (recursion_stack[*itr])
                    return false;
            }
        }

        recursion_stack[v] = false;
        return false;
    }
};

int main()
{

    return 0;
}