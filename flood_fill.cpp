#include <iostream>
#include <cstdlib>
using namespace std;

int r, c;

void print(char mat[][50])
{
    system("CLS");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << mat[i][j];
        cout << endl;
    }
}

void floodfill(char mat[][50], int i, int j, char ch, char color)
{
    if (i < 0 || j < 0 || i >= r || j >= c || mat[i][j] != ch)
        return;

    mat[i][j] = color;
    print(mat);
    floodfill(mat, i, j + 1, ch, color);
    floodfill(mat, i, j - 1, ch, color);
    floodfill(mat, i + 1, j, ch, color);
    floodfill(mat, i - 1, j, ch, color);
}

int main()
{
    char mat[50][50];
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];

    floodfill(mat, 6, 15, '.', 'R');
    return 0;
}

/* use this for input
15
30
.........................................#####.........................#...#....................######...######.............###.............####..........##................###.........##.................###........##................###.........###...............##...........##.............###.............###.........####................#############...................................................................................................
*/