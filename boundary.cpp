#include <iostream>

using namespace std;

int lowerBound(int *a, int n, int element)
{
    int s = 0, e = n - 1, mid, ans = -1;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (a[mid] == element)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (a[mid] > element)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
}

int upperBound(int *a, int n, int element)
{
    int s = 0, e = n - 1, mid, ans = -1;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (a[mid] == element)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (a[mid] > element)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
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

    cout << "lowerBound\t" << lowerBound(a, n, element) << '\n';
    cout << "upperBound\t" << upperBound(a, n, element) << '\n';
    return EXIT_SUCCESS;
}