#include <bits/stdc++.h>

using namespace std;

int binarySearchRotated(int *a, int s, int e, int element)
{
    if (s > e)
        return -1;
    int mid = (s + e) / 2;
    if (a[mid] == element)
        return mid;

    if (a[s] <= a[mid])
    {
        if (element <= a[mid] && a[s] <= element)
            return binarySearchRotated(a, s, mid - 1, element);
        return binarySearchRotated(a, mid + 1, e, element);
    }

    if (element <= a[e] && a[mid] <= element)
        return binarySearchRotated(a, mid + 1, e, element);
    return binarySearchRotated(a, s, mid - 1, element);
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int element;
    cin >> element;

    int s = 0;
    int e = n - 1;
    cout << binarySearchRotated(a, s, e, element);
    return EXIT_SUCCESS;
}