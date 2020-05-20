#include <bits/stdc++.h>

using namespace std;

int sagheerTheHausmeister(int **matrix, int rowCount, int columnCount, int currentRow, int direction)
{
    // base case
    if (currentRow == -1)
        return -1;

    // solve the ground floor yourself dude
    if (currentRow == rowCount - 1)
    {
        int leftDistance, rightDistance;
        // traverse through all of the ground level rooms
        for (int i = 1; i < columnCount + 1; i++)
        {
            if (matrix[currentRow][i] == 1)
            {
                leftDistance = i;
                rightDistance = columnCount + 1 - i;
            }
        }

        return min(((2 * leftDistance) + 1 + sagheerTheHausmeister(matrix, rowCount, columnCount, currentRow - 1, 0)),
                   ((columnCount + 1) + 1 + sagheerTheHausmeister(matrix, rowCount, columnCount, currentRow - 1, 1)));
    }

    if (direction == 0)
    {
        int leftDistance, rightDistance;
        // traverse through all of the ground level rooms
        for (int i = 1; i < columnCount + 1; i++)
        {
            if (matrix[currentRow][i] == 1)
            {
                leftDistance = i;
                rightDistance = columnCount + 1 - i;
            }
        }

        return min(((2 * leftDistance) + 1 + sagheerTheHausmeister(matrix, rowCount, columnCount, currentRow - 1, 0)),
                   ((columnCount + 1) + 1 + sagheerTheHausmeister(matrix, rowCount, columnCount, currentRow - 1, 1)));
    }

    else
    {
        int leftDistance, rightDistance;
        // traverse through all of the ground level rooms
        for (int i = columnCount; i > 0; i--)
        {
            if (matrix[currentRow][i] == 1)
            {
                leftDistance = i;
                rightDistance = columnCount + 1 - i;
            }
        }

        return min(((2 * rightDistance) + 1 + sagheerTheHausmeister(matrix, rowCount, columnCount, currentRow - 1, 1)),
                   ((columnCount + 1) + 1 + sagheerTheHausmeister(matrix, rowCount, columnCount, currentRow - 1, 0)));
    }
}

int main()
{
    int rowCount, columnCount;
    cin >> rowCount >> columnCount;
    int **matrix = new int *[rowCount];
    for (int i = 0; i < rowCount; i++)
        matrix[i] = new int[columnCount + 2];

    // input the array
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < columnCount + 2; j++)
            cin >> matrix[i][j];

    cout << sagheerTheHausmeister(matrix, rowCount, columnCount, rowCount - 1, 0);

    return EXIT_SUCCESS;
}