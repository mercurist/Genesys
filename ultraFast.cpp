#include <bits/stdc++.h>

using namespace std;

int main()
{
    string x, y;
    cin >> x >> y;
    int n = x.size();
    for( int i = 0; i < n; i++)
    {
        if ( x[i] == y[i])
            x[i] = '0';
        else
        {
            x[i] = '1';
        }
        
    }
    cout << x;
    return EXIT_SUCCESS;
}