#include <iostream>
using namespace std;

void permutations(char *in, int i)
{
    if (in[i] == '\0')
    {
        cout << in << " ";
        return;
    }

    for (int j = i; in[j] != '\0'; j++)
    {
        swap(in[i], in[j]);
        permutations(in, i + 1);
        // backtracking to restore the original array
        swap(in[i], in[j]);
    }
}

int main()
{
    char in[100];
    cin >> in;

    permutations(in, 0);
    return EXIT_SUCCESS;
}