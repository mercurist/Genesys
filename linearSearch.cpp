#include <iostream>

using namespace std;

int linearSearch(int *a, int n, int b)
{
    if ( n == 0)
        return -1;
    
    if (a[0] == b)
    {
        return n;
    }
    return linearSearch(a+1, n-1, b);
}

int main()
{
    int a[] = {1,12,3,34,4,6,10};
    int n = sizeof(a)/ sizeof(int);
    int b = 6;

    int index = linearSearch( a, n, b);
    if ( index!=-1)
    {
        cout << "element " << b << " found at " << n-index;
    }
    else
    {
        cout << "element not found";
    }
    
    return EXIT_SUCCESS;
}