#include <iostream>
#include <cstdlib>
#include <ctime>

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

void shuffle(int a[], int p, int r)
{
    srand(time(NULL));
    int i, j;
    for( i = r; i >p; i--)
    {
        j = rand() % (i+1);
        swap( &a[i], &a[j]);
    }
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

void randomizedQuicksort( int a[], int p, int r)
{
    shuffle(a, p, r);
    quickSort(a, p, r);
}

int main()
{
    int a[] = {2,7,8,6,5,1,4};
    int n = sizeof(a) / sizeof(int);

    displayArray(a, n);
    shuffle(a, 0, n-1);
    displayArray(a, n);
    randomizedQuicksort (a, 0, n-1);
    displayArray(a, n);
    return EXIT_SUCCESS;
}