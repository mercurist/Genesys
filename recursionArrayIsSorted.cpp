#include <iostream>

using namespace std;

int minimum( int a[], int p, int q)
{
    int min = a[p];
    for( int i = p; i <= q; i++)
    {
        if ( a[i] <= min)
            min = a[i];
    }

    return min;
}

int maximum( int a[], int p, int q)
{
    int max = a[p];
    for( int i = p; i <= q; i++)
    {
        if ( a[i] >= max)
            max = a[i];
    }

    return max;
}

bool isSorted(int a[], int p, int r)
{
    if ( p == r)
        return true;
    else if ( r == p+1)
        return (a[r] >= a[p]);
    else
    {
        int q = (p+r)/2;
        return isSorted(a, p, q) && isSorted( a, q+1, r) && (maximum( a, p, q) <= minimum(a, q+1, r));
    }
}

int main()
{
    int a[20];
    int n;
    cin >> n;
    for( int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if ( isSorted(a, 0, n-1))
    {
        cout << "yes array is sorted";
    }
    else
    {
        cout << "array isnt sorted";
    }

    return EXIT_SUCCESS;
}