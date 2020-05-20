#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b= temp;
}

void displayArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';
}

int partition( int a[], int p, int r)
{
    int pivot = a[r];
    int i = p-1;
    for( int j = p; j < r; j++)
    {
        if ( a[j] <= pivot)
        {
            i++;
            swap( &a[i], &a[j]);
        }
    }

    swap( &a[i+1], &a[r]);
    return (i+1);
}

void quickSort(int a[], int p, int r)
{
    if ( r > p)
    {
        int q = partition(a, p, r);
        quickSort(a, p, q-1);
        quickSort(a, q+1, r);
    }
}

int main()
{
    int a[] = {2,7,8,6,5,1,4};
    int n = sizeof(a) / sizeof(int);

    displayArray(a, n);
    quickSort(a, 0, n-1);
    displayArray(a, n);
    return EXIT_SUCCESS;
}