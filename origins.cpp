#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    string t;
    cin >> t;
    int rx = 0;
    for (int i = 0; i < x; i++)
    {
        if (t[i] == 'L')
            rx--;
        else
            rx++;
    }

    int count = 0;
    int originalPosition = -rx;
    int currentPosition = originalPosition;
    for (int i = 0; i < x; i++)
    {
        if (t[i] == 'L')
            currentPosition -= 1;
        else
            currentPosition += 1;
        if (currentPosition == 0)
            count++;
    }

    cout << count << " " << originalPosition << '\n';
    return 0;
}