#include <iostream>

using namespace std;

void displayArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';
}

void merge(int a[], int p, int q, int r)
{
    int temp[100];
    int i = p;
    int j = q+1;
    int k = p;

    while (( i <= q) && ( j <= r))
    {
        if ( a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while ( i <= q)
    {
        temp[k++] = a[i++];
    }
    while ( j <= r)
    {
        temp[k++] = a[j++];
    }

    for( k = p; k<=r; k++)
        a[k] = temp[k];
}

void mergeSort(int a[], int p, int r)
{
    if ( r > p)
    {
        int q = (p+r)/2;
        mergeSort( a, p, q);
        mergeSort( a, q+1, r);
        merge(a, p, q, r);
    }
}

int main()
{
    int a[] = {5,6,1,2,4,0};
    int n = sizeof(a)/ sizeof(int);

    displayArray(a, n);
    mergeSort(a, 0, n-1);
    displayArray(a, n);
    return EXIT_SUCCESS;
}