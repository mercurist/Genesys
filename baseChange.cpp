#include <bits/stdc++.h>
using namespace std;

vector<int> fourthOfJuly(int a)
{
    vector<int> temp;
    if (a == 0)
        return vector<int>{0};

    while (a != 0)
    {
        temp.push_back(a % 4);
        a /= 4;
    }
    return temp;
}

int main()
{
    int a;
    cin >> a;
    vector<int> result = fourthOfJuly(a);
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i];
    return 0;
}