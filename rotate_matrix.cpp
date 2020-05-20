#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N = 4;
    int image[N][N];
    int number = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            image[i][j] = ++number;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cout << image[i][j] << "\t\n"[j == N - 1];

    cout << "\n\n";

    for (int layer = 0; layer < (N / 2); layer++)
    {
        int first = layer;
        int last = N - 1 - layer;

        for (int i = first; i < last; i++)
        {
            int offset = i - first;
            int temp = image[first][i];
            image[first][i] = image[last - offset][first];
            image[last - offset][first] = image[last][last - offset];
            image[last][last - offset] = image[first + offset][last];
            image[first + offset][last] = temp;
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cout << image[i][j] << "\t\n"[j == N - 1];

    return 0;
}
