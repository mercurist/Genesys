#include <bits/stdc++.h>
using namespace std;

int fibonacciFastHelper(int x, vector<int> &memo)
{
    if (memo[x] != -1)
        return memo[x];
    else
        memo[x] = fibonacciFastHelper(x - 1, memo) + fibonacciFastHelper(x - 2, memo);
    return memo[x];
}

int fibonacciFast(int x)
{
    vector<int> memo(x + 1, -1);
    memo[0] = 0;
    memo[1] = 1;
    int result = fibonacciFastHelper(x, memo);
    return result;
}

int fibonacci(int x)
{
    if (x == 0 || x == 1)
        return x;
    else
        return fibonacci(x - 1) + fibonacci(x - 2);
}

int main()
{
    int x;
    cin >> x;
    cout << fibonacciFast(x) << '\n';
    cout << fibonacci(x) << '\n';

    return 0;
}