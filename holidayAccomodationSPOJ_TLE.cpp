/*                                          QUESTION~ HOLIDAY ACCOMODATION SPOJ
Here is a group of N people who want to travel around the world. They live in different cities, so they can travel to some other people's city and use someone's house temporary. Now they want to make a plan that choose a destination for each person. There are two rules should be satisfied:

    All the people should go to one of the other people's city.
    Two of them never go to the same city, because they are not willing to share a house.

They want to maximize the sum of all people's travel distance. The travel distance of a person is the distance between the city he lives in and the city he travels to. These N cities have N-1 highways connecting them. The travelers always choose the shortest path when traveling.
Given the highways' information, it is your job to find the best plan, that maximum the total travel distance of all people. Question
*/

#include <iostream>
#include <vector>

using namespace std;

void addEdge( vector<pair<int, int>> adjacency[], int source, int destination, int weight)
{
    adjacency[source].push_back(make_pair( destination, weight));
    adjacency[destination].push_back(make_pair( source, weight));
}

void DFSUtility( int u, vector<pair<int, int>> adjacency[], vector<bool> &visited, vector<int> &count)
{
    visited[u] = true;
    for( int i = 0; i < adjacency[u].size(); i++)
    {
        if ( visited[ adjacency[u][i].first] == false)
        {
            DFSUtility( adjacency[u][i].first, adjacency, visited, count);
            count[u] += count[adjacency[u][i].first];
        }
    }

    count[u]++;
}

vector<int> DFSWeighted( vector<pair<int, int>> adjacency[], int noOfCities)
{
    vector<int> count(noOfCities, 0);
    vector<bool> visited(noOfCities, false);
    for( int u = 0; u < noOfCities; u++)
    {
        if ( visited[u] == false)
            DFSUtility( u, adjacency, visited, count);
    }

    return count;
}

int DFSUtilityTwo(int u, vector<pair<int, int>> adjacency[], vector<bool> &visited, int noOfCities, vector<int> count)
{
    int result = 0;
    visited[u] = true;
    for( int i = 0; i < adjacency[u].size(); i++)
    {
        if ( visited[adjacency[u][i].first] == false)
        {
            result += 2 * adjacency[u][i].second * min(count[adjacency[u][i].first], noOfCities - count[adjacency[u][i].first]);
            result += DFSUtilityTwo( adjacency[u][i].first, adjacency, visited, noOfCities, count);
        }
    }
    return result;
}

int getResult( vector<pair<int, int>> adjacency[], int noOfCities, vector<int> count)
{
    int result = 0;
    vector<bool> visited ( noOfCities, false);
    for( int u = 0; u < noOfCities; u++)
    {
        if ( visited[u] == false)
        result += DFSUtilityTwo(u, adjacency, visited, noOfCities, count);
    }

    return result;
}


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int noOfTestCases, noOfCities, source, destination, weight;
    cin >> noOfTestCases;
    while (noOfTestCases--)
    {
        cin >> noOfCities;
        vector<pair<int, int>> adjacency [noOfCities];
        for( int i = 1; i < noOfCities; i++)
        {
            cin >> source >> destination >> weight;
            // if indexing starts from 0
            // addEdge( adjacency, source, destination, weight);
            // if indexing starts from 1
            addEdge( adjacency, source-1, destination-1, weight);
        }

        vector<int> count = DFSWeighted( adjacency, noOfCities);
        cout << getResult( adjacency, noOfCities, count);
    } 
    return EXIT_SUCCESS;
}