#include <iostream>
using namespace std;

void display(int **a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }
}

void possibilities(int **a, int m, int n)
{
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (a[0][i] == -1)
            flag = false;

        if (flag == true)
            a[0][i] = 1;
        else
            a[0][i] = 0;
    }

    flag = true;
    for (int i = 0; i < m; i++)
    {
        if (a[i][0] == -1)
            flag = false;

        if (flag == true)
            a[i][0] = 1;
        else
            a[i][0] = 0;
    }

    int i, j;
    for (i = 1; i < m; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (a[i][j] == -1)
                a[i][j] = 0;
            a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }
    cout << a[m - 1][n - 1];
}

int main()
{
    int m, n;
    cin >> m >> n;
    int **a = new int *[m];
    for (int i = 0; i < m; i++)
        a[i] = new int[n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    possibilities(a, m, n);
    return EXIT_SUCCESS;
}