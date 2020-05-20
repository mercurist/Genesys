#include <bits/stdc++.h>
using namespace std;

void displayBoard(char **arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << '\t';

        cout << '\n';
    }

    cout << '\n';
}

bool isConfigurationSafe(char **arr, int row, int col, int N)
{
    int i, j;

    for (int i = 0; i < row; i++)
        if (arr[i][col] == 'Q')
            return false;

    for (int i = 0; i < col; i++)
        if (arr[row][i] == 'Q')
            return false;

    i = row - 1;
    j = col - 1;

    while (i >= 0 and j >= 0)
    {

        if (arr[i][j] == 'Q')
            return false;

        i--, j--;
    }

    i = row - 1;
    j = col + 1;

    while (i >= 0 and j < N)
    {

        if (arr[i][j] == 'Q')
            return false;

        i--;
        j++;
    }

    return true;
}

bool nQueenUsingBacktracking(char **arr, int row, int N, int &count)
{
    if (row == N)
    {
        count++;
        // displayBoard(arr, N);
        // to display all the cases, return false as this false in the base case will revert to every other parent call and then backtrack to false in the original case
        return false;
    }
    for (int i = 0; i < N; i++)
    {

        if (isConfigurationSafe(arr, row, i, N))
        {
            arr[row][i] = 'Q';
            if (nQueenUsingBacktracking(arr, row + 1, N, count))
                return true;

            // backtracking
            arr[row][i] = '.';
        }
    }
    return false;
}

int main()
{
    int N;
    cin >> N;
    char **arr = new char *[N];
    for (int i = 0; i < N; i++)
        arr[i] = new char[N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            arr[i][j] = '.';
    }

    int count = 0;
    nQueenUsingBacktracking(arr, 0, N, count);
    cout << count;

    return EXIT_SUCCESS;
}