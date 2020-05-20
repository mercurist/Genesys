#include <iostream>

using namespace std;

int bruteForce(int *a, int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                count++;

    return count;
}

int main()
{
    int a[] = {5, 2, 1, 4, 3};
    int n = sizeof(a) / sizeof(int);

    cout << bruteForce(a, n);
    return EXIT_SUCCESS;
}