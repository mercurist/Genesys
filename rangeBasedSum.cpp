#include <iostream>

using namespace std;

int iterativeSum(int *array, int l, int r)
{
    int sum = 0;
    for (int i = l; i <= r; i++)
        sum += array[i];

    return sum;
}

int prefixedSum(int *array, int l, int r, int n)
{
    int *prefixSum = new int[n + 1];
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++)
        prefixSum[i] = prefixSum[i - 1] + array[i - 1];

    int result = prefixSum[r + 1] - prefixSum[l];
    return result;
}

int main()
{
    int n, l, r;
    cin >> n;

    int *array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];

    cin >> l >> r;
    cout << iterativeSum(array, l, r) << endl;
    cout << prefixedSum(array, l, r, n) << endl;

    return EXIT_SUCCESS;
}