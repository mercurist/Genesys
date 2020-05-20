#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int beg, int end, int x)
{
    while (beg <= end)
    {
        int mid = (beg + end) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    return -1;
}

int findPivot(int arr[], int beg, int end)
{
    if (beg < end)
        return -1;
    if (beg == end)
        return beg;

    int mid = (beg + end) / 2;
    if (mid < end && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > beg && arr[mid - 1] > arr[mid])
        return mid - 1;

    // if the first half is already sorted
    if (arr[beg] <= arr[mid])
        return findPivot(arr, mid + 1, end);

    // if the first half is NOT COMPLETELY SORTED
    return findPivot(arr, beg, mid - 1);
}

int pivotBasedSearch(int arr[], int n, int x)
{
    int pivot = findPivot(arr, 0, n - 1);
    // if we dont find a pivot, then this suggests that the array is not sorted at all
    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, x);

    if (arr[pivot] == x)
        return pivot;
    if (arr[0] <= x)
        return binarySearch(arr, 0, pivot - 1, x);
    return binarySearch(arr, pivot + 1, n - 1, x);
}

int main()
{
    int n;
    cin >> n;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    int x;
    cin >> x;

    cout << pivotBasedSearch(array, n, x) << '\n';
    return 0;
}