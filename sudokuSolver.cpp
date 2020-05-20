#include <iostream>
#include <cmath>
// galat cheez hai joh bhi hai!

using namespace std;

bool canPlace(int sudoku[][9], int i, int j, int n, int number)
{
    for (int x = 0; x < number; x++)
    {
        if (sudoku[x][j] == number || sudoku[i][x] == number)
            return false;
    }

    int rn = sqrt(n);
    int sx = (i / rn) * rn;
    int sy = (j / rn) * rn;
    for (int x = sx; x < sx + rn; x++)
        for (int y = sy; y < sy + rn; y++)
            if (sudoku[x][y] == number)
                return false;

    return true;
}

bool solveSudoku(int sudoku[][9], int i, int j, int n)
{
    if (i == n)
        return true;
    if (j == n)
        return solveSudoku(sudoku, i + 1, 0, n);
    if (sudoku[i][j] != 0)
        return solveSudoku(sudoku, i, j + 1, n);

    for (int number = 1; number <= n; number++)
    {
        if (canPlace(sudoku, i, j, n, number))
        {
            sudoku[i][j] = number;
            if (solveSudoku(sudoku, i, j + 1, n) == true)
                return true;
        }
    }

    sudoku[i][j] = 0;
    return false;
}

void display(int sudoku[][9], int n)
{
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
            cout << sudoku[x][y] << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int sudoku[9][9] = {{0, 0, 0, 0, 6, 0, 0, 0, 0},
                        {0, 8, 0, 9, 0, 0, 0, 4, 1},
                        {0, 0, 0, 0, 0, 7, 0, 2, 0},
                        {0, 0, 6, 0, 3, 8, 7, 0, 0},
                        {9, 0, 0, 0, 0, 0, 0, 0, 3},
                        {0, 0, 2, 1, 4, 0, 8, 0, 0},
                        {0, 5, 0, 6, 0, 0, 0, 0, 0},
                        {4, 6, 0, 0, 0, 1, 0, 7, 0},
                        {0, 0, 0, 0, 8, 0, 0, 0, 0}};

    solveSudoku(sudoku, 0, 0, 9);
    display(sudoku, 9);
    return EXIT_SUCCESS;
}

/*
{
        {0, 0, 0, 0, 6, 0, 0, 0, 0},
        {0, 8, 0, 9, 0, 0, 0, 4, 1},
        {0, 0, 0, 0, 0, 7, 0, 2, 0},
        {0, 0, 6, 0, 3, 8, 7, 0, 0},
        {9, 0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 2, 1, 4, 0, 8, 0, 0},
        {0, 5, 0, 6, 0, 0, 0, 0, 0},
        {4, 6, 0, 0, 0, 1, 0, 7, 0},
        {0, 0, 0, 0, 8, 0, 0, 0, 0}};

*/

/*
{
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};
*/