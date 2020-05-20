#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void sieveOfEratosthenes(int *secondArray, ll root)
{
    for (int i = 0; i < root; i++)
        secondArray[i] = 1;

    secondArray[0] = 0;
    secondArray[1] = 0;

    for (int i = 1; i < root; i++)
    {
        int actualNumber = i;
        if (secondArray[i])
        {
            for (int j = 2 * actualNumber; j < root; j += actualNumber)
            {
                secondArray[j] = 0;
            }
        }
    }
}

void display(int *array, int n)
{
    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << '\n';
}

int main()
{
    ll tc;
    cin >> tc;

    while (tc--)
    {
        ll a, b;
        cin >> a >> b;
        ll range = b - a + 1;
        // we are doing a mapping
        // map a to 0th index in the array and b to (b-a)th index in the array
        int *array = new int[range];
        for (int i = 0; i < range; i++)
            array[i] = 1;
        ll root = sqrt(b);
        int *secondArray = new int[root + 1];
        sieveOfEratosthenes(secondArray, root + 1);
        // display(secondArray, root + 1);
        int index = 0;
        for (int i = 0; i < root + 1; i++)
        {
            index = 0;
            if (secondArray[i] == 1)
            {
                int prime = i;

                while (index < range && ((a + index) % prime) != 0)
                    index++;
                while (index < range)
                {
                    array[index] = 0;
                    index += prime;
                }
            }
        }
        index = 0;
        // display(array, range);
        while (a + index < root + 1)
        {
            array[index] = secondArray[index + 1];
            index++;
        }

        // display(array, range);

        int count = 0;
        for (int i = 0; i < range; i++)
            if (array[i] == 1)
                count++;

        cout << count << '\n';
    }
    return 0;
}