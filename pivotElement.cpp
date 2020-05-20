#include <iostream>

using namespace std;

int pivotal(int *a, int n)
{
    int s = 0, e = n - 1, mid, pivot;
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

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << pivotal(a, n);
    return EXIT_SUCCESS;
}