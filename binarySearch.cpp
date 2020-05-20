#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch( int a[], int p, int r, int element)
{
    if (( p == r) && a[p] != element)
    {
        return -1;
    }
    int q = (p+r)/2;
    if ( a[q] == element)
    {
        return q;
    }
    else if ( a[q] > element)
    {
        return binarySearch(a, p, q-1, element);
    }
    else
    {
        return binarySearch(a, q+1, r, element);
    }
}

int main()
{
    int a[] = {1,3,4,5,7,12,15,2,11};
    int n  = sizeof(a)/sizeof(int);
    sort(a, a+n);

    int element = 3;
    cout << binarySearch(a, 0, n-1, element);

    return EXIT_SUCCESS;
}