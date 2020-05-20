#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    int src;
    int dest;
    int weight;
};

class set_of_vertices
{
public:
    int rank;
    int parent;
};

int find(set_of_vertices *current_set, int i)
{
    if (current_set[i].parent == i)
        current_set[i].parent = find(current_set, current_set[i].parent);

    return current_set[i].parent;
}

void set_union(set_of_vertices *current_set, int v1, int v2)
{
    int v1_root = find(current_set, v1);
    int v2_root = find(current_set, v2);

    if (current_set[v1_root].rank < current_set[v2_root].rank)
    {
        current_set[v1_root].parent = v2_root;
    }
    else if (current_set[v1_root].rank > current_set[v2_root].rank)
    {
        current_set[v2_root].parent = v1_root;
    }
    else
    {
        current_set[v2_root].parent = v1_root;
        current_set[v1_root].rank++;
        // we can also set current_set[v1_root].parent = v2_root;
    }
}

bool comparator(edge e1, edge e2)
{
    return e1.weight < e2.weight;
}

void kruskals(edge *input, int number_of_vertices, int number_of_edges)
{
    // sort the input array on the basis of weights of the edges
    sort(input, input + number_of_edges, comparator);
    // initialise the output array which contains our minimum spanning tree
    edge *output = new edge[number_of_vertices - 1];

    set_of_vertices *current_set = new set_of_vertices[number_of_vertices];
    for (int i = 0; i < number_of_vertices; i++)
    {
        // assign the rank to 0
        current_set[i].rank = 0;
        // assign the parents of the elements which are initially in their individual set as the element themselves
        current_set[i].parent = i;
    }

    int counter = 0, i = 0;
    // count till the number of edges which should be (n-1) for our minimum spanning tree
    while (counter < number_of_vertices - 1)
    {
        // take the edge with minimum weight
        edge current_edge = input[i];
        // find the parent of source and destination vertices
        int source_parent = find(current_set, current_edge.src);
        int dest_parent = find(current_set, current_edge.dest);

        if (source_parent != dest_parent)
        {
            // this means that the two parent dont lie in the same set and we have to find the union of these two
            output[counter] = current_edge;
            set_union(current_set, source_parent, dest_parent);
            counter++;
        }

        i++;
    }

    for (int i = 0; i < number_of_vertices - 1; i++)
        cout << "source " << output[i].src << " -- "
             << " destination " << output[i].dest << " with weight " << output[i].weight << endl;
}

int main()
{
    int number_of_vertices, number_of_edges;
    cin >> number_of_vertices;
    cin >> number_of_edges;

    edge *input = new edge[number_of_edges];
    for (int i = 0; i < number_of_edges; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].src = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskals(input, number_of_vertices, number_of_edges);
    return 0;
}