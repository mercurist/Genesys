#include <bits/stdc++.h>
using namespace std;

void display(int solution[][10], int m, int n)
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << solution[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool ratInAMaze(char maze[][10], int solution[][10], int i, int j, int m, int n, int &count)
{
    if (i == m && j == n)
    {
        count++;
        solution[i][j] = 1;
        display(solution, m, n);
        return true;
    }

    if (i > m || j > n)
        return false;

    if (maze[i][j] == 'X')
        return false;

    solution[i][j] = 1;
    bool rightSuccess = ratInAMaze(maze, solution, i, j + 1, m, n, count);
    bool downSuccess = ratInAMaze(maze, solution, i + 1, j, m, n, count);

    solution[i][j] = 0;
    if (rightSuccess || downSuccess)
        return true;

    return true;
}

int main()
{
    char maze[10][10] = {"0000",
                         "00X0",
                         "000X",
                         "0X00"};

    int solution[10][10] = {0};
    int m = 4, n = 4;
    int count = 0;
    if (!ratInAMaze(maze, solution, 0, 0, m - 1, n - 1, count))
        cout << "path doesnt exist " << '\n';

    cout << count;
    return EXIT_SUCCESS;
}