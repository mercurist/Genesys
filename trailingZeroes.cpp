#include <bits/stdc++.h>
using namespace std;

int countTrailer(int n)
{
    int count = 0;
    while (n != 0)
    {
        count += (n / 5);
        n /= 5;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << countTrailer(n) << '\n';
    return 0;
}