#include <iostream>

using namespace std;

void update(int *BITarray, int i, int value, int n)
{
    while (i <= n)
    {
        BITarray[i] = max(BITarray[i], value);
        i += (i & (-i));
    }
}

void buildBITArray(int *array, int *BITarray, int n)
{
    for (int i = 1; i <= n; i++)
        update(BITarray, i, array[i], n);
}

void display(int *BITarray, int n)
{
    for (int i = 1; i <= n; i++)
        cout << BITarray[i] << " ";
    cout << endl;
}

int query(int *BITarray, int x, int n)
{
    int maxim = INT32_MIN, i = x;
    while (i > 0)
    {
        maxim = max(maxim, BITarray[i]);
        i -= (i & (-i));
    }

    return maxim;
}

void rangeMaxQuery(int *BITarray, int upper, int n)
{
    cout << query(BITarray, upper, n);
}

int main()
{
    int n, *array, *BITarray;
    cin >> n;
    array = new int[n + 1];
    BITarray = new int[n + 1];
    BITarray[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i + 1];
        BITarray[i + 1] = 0;
    }

    buildBITArray(array, BITarray, n);
    display(BITarray, n);

    int upper;
    cin >> upper;
    rangeMaxQuery(BITarray, upper, n);
    return EXIT_SUCCESS;
}