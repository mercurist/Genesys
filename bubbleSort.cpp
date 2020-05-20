#include <iostream>
#include <limits>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b= temp;
}

void bubbleSort(int a[], int n)
{
    for( int i = 0; i < n-1; i++)
    {
        // last i elements are already in place
        for( int j = 0; j < n-1-i; j++)
        {
            if ( a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
        }
    }
}
// the above bubble sort can be optimized by stopping the algorithm if the inner loop didnt cause any swap
void bubbleSortOptimized(int a[], int n)
{
    for( int i = 0; i < n-1; i++)
    {
        bool swapped = false;
        // last i elements are already in place
        for( int j = 0; j < n-1-i; j++)
        {
            if ( a[j] > a[j+1])
            {
                swap(&a[j], &a[j+1]);
                swapped = true;
            }
        }

        if( swapped == false)
            break;
    }
}

void bubbleSortRecursive(int a[], int n)
{
    if ( n == 1)
        return;

    // simplification
    for(int i = 0; i < n-1; i++)
    {
        if ( a[i] > a[i+1])
        {
            swap(&a[i], &a[i+1]);
        }
    }
    // recursive call
    bubbleSortRecursive(a, n-1);
}

void bubbleSortParameters( int a[], int i, int n)
{
    if ( n== 1)
        return;
    if ( i == n-1)
    {
        return bubbleSortParameters(a, 0, n-1);
    }

    if ( a[i] > a[i+1])
    {
        swap(&a[i], &a[i+1]);
    }

    bubbleSortParameters(a, i+1, n);
    
}

void displayArray( int a[], int n)
{
    for( int i = 0; i < n; i++)
        cout << a[i] << ' ';
}

int main()
{
    int a[] = {1,4,15,2,6,10,20,16};
    int n = sizeof(a) / sizeof(int);

    // bubbleSort(a, n);
    // bubbleSortOptimized(a, n);
    bubbleSortRecursive(a, n);
    displayArray(a, n);
    return EXIT_SUCCESS;
}