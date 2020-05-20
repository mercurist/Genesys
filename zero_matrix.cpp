#include <bits/stdc++.h>
using namespace std;

int main()
{
    string uhh[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> uhh[i][j];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            if (uhh[i][j] == "0")
                uhh[i][j] = "u";
        }

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            if (uhh[i][j] == "u")
                for (int k = 0; k < 5; k++)
                {
                    uhh[i][k] = "0";
                    uhh[k][j] = "0";
                }
        }

    cout << '\n';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cout << uhh[i][j] << " \n"[j == 4];

    return 0;
}