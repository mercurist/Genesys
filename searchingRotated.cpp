#include <iostream>

using namespace std;

int pivotal(int *a, int s, int e)
{
    int mid, pivot;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (mid < e && a[mid] > a[mid + 1])
        {
            pivot = mid;
            break;
        }
        else if (mid > s && a[mid] < a[mid - 1])
        {
            pivot = mid - 1;
            break;
        }
        else if (a[s] >= a[mid])
            e = mid - 1;
        else if (a[e] <= a[mid])
            s = mid + 1;
    }

    return pivot;
}

int binarySearch(int *a, int s, int e, int element)
{
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == element)
            return mid;
        else if (a[mid] > element)
            e = mid - 1;
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int binarySearchRotated(int *a, int s, int e, int element)
{
    int result = -1;
    int pivot = pivotal(a, s, e);
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (a[mid] == element)
            return mid;

        if (mid > pivot)
        {
            if (a[mid] <= element && element <= a[e])
                result = binarySearch(a, mid + 1, e, element);
            else
            {
                result = binarySearchRotated(a, s, mid - 1, element);
            }
        }

        else
        {
            if (a[mid] >= element && element >= a[s])
                result = binarySearch(a, s, mid - 1, element);
            else
            {
                result = binarySearchRotated(a, mid + 1, e, element);
            }
        }
    }

    return result;
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