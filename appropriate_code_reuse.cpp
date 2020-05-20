#include <bits/stdc++.h>
using namespace std;

int convertFromBase(string number, int base)
{
    assert(!(base < 2) || (base > 10 && base != 16));

    int value = 0;
    for (int i = number.length() - 1; i >= 0; i--)
    {
        int digit = int(number[i]) - int('0');

        assert(!(digit < 0 || digit >= base));

        int exp = number.length() - 1 - i;
        value += digit * (pow(base, exp));
    }
    return value;
}

bool compareBinToHex(string binary, string hex)
{
    int n1 = convertFromBase(binary, 2);
    int n2 = convertFromBase(hex, 16);

    return (n1 == n2);
}

int main()
{
    string binary, hex;
    cin >> binary >> hex;
    cout << compareBinToHex(binary, hex);
    return 0;
}