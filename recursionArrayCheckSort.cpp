#include <iostream>

using namespace std;

bool isSorted(int a[], int p, int r)
{
    if ( r == p)
        return true;

    return ((a[p] <= a[p+1]) && isSorted( a, p+1, r));
}

bool isSortedViaPointers( int *a, int n)
{
    if ( n == 1)
        return true;
    if ( a[0] < a[1] && isSortedViaPointers( a+1, n-1))
        return true;
    return false;
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
    /*
        if ( isSorted(a, 0, n-1))
        {
            cout << "yes array is sorted";
        }
        else
        {
            cout << "array isnt sorted";
        }
    */
    if ( isSortedViaPointers(a, n))
    {
        cout << "yes array is sorted";
    }
    else
    {
        cout << "array isnt sorted";
    }

    return EXIT_SUCCESS;
}