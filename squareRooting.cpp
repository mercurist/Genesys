#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> preCompute(vector<int> vect, int root)
{
    vector<int> blocks(root + 1, 0);
    int n = vect.size();
    for (int i = 0; i < n; i += root)
    {
        int k = (i / root);
        for (int j = i; j < i + root; j++)
            blocks[k] += vect[j];
    }

    return blocks;
}

void update(vector<int> &blocks, int position, int value, int root, int oldValue)
{
    blocks[position / root] += value - oldValue;
}

int rangeSum(vector<int> vect, vector<int> blocks, int lower, int upper, int root)
{
    int result = 0;

    // left part
    while (lower <= upper && lower != 0 && (lower % root) != 0)
    {
        result += vect[lower];
        lower++;
    }

    // middle part
    while (lower + root <= upper)
    {
        result += blocks[lower / root];
        lower += root;
    }

    // right part
    while (lower <= upper)
    {
        result += vect[lower];
        lower++;
    }

    return result;
}

int main()
{
    vector<int> vect = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = vect.size();
    int root = sqrt(n);

    if ((n % root) != 0)
        vect.resize(root * ((n / root) + 1));

    vector<int> blocks = preCompute(vect, root);

    for (int i = 0; i < blocks.size(); i++)
        cout << blocks[i] << " ";

    cout << "\nto update any element \n";
    int position, value;
    cin >> position >> value;

    int oldValue = vect[position];
    vect[position] = value;
    update(blocks, position, value, root, oldValue);

    for (int i = 0; i < blocks.size(); i++)
        cout << blocks[i] << " ";

    int lower, upper;
    cout << "\nrange sum query\n";
    cout << "lower index (included)\t";
    cin >> lower;
    cout << "upper index (included)\t";
    cin >> upper;

    cout << rangeSum(vect, blocks, lower, upper, root);

    return EXIT_SUCCESS;
}