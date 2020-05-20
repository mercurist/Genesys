#include <iostream>
#include <map>
#include <unordered_map>
#include <list>

using namespace std;

template <typename T>
class graph
{
    unordered_map<T, list<T>> adjList;

public:
    void addEdge(T u, T v, bool bidir = true)
    {
        adjList[u].push_back(v);
        if (bidir == true)
            adjList[v].push_back(u);
    }

    void print()
    {
        for (auto everyRow : adjList)
        {
            cout << '\n';
            cout << everyRow.first;
            for (auto everyEdge : everyRow.second)
            {
                cout << " -> " << everyEdge;
            }
        }
    }
};

int main()
{
    graph<string> g;
    g.addEdge("delhi", "jaipur");
    g.addEdge("delhi", "gurgaon");
    g.addEdge("jaipur", "agra");
    g.addEdge("jaipur", "patna");
    g.addEdge("jaipur", "gurgaon");
    g.addEdge("agra", "patna");
    g.addEdge("patna", "gurgaon");

    g.print();

    return 0;
}
/*
15
30
..............................
...........#####..............
...........#...#..............
......######...######.........
....###.............####......
....##................###.....
....##.................###....
....##................###.....
....###...............##......
.....##.............###.......
......###.........####........
........#############.........
..............................
..............................
..............................
*/