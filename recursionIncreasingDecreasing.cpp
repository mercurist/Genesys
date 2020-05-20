#include <iostream>

using namespace std;

void decreasingIncreasing( int p)
{
    if ( p == 0)
    {
        cout << endl;
    }

    else
    {
        cout << p << " ";
        decreasingIncreasing( p-1);
        cout << p << " ";
    }
}

void increasingDecreasing( int p, int n)
{
    if ( p == 0)
    {
        cout << endl;
    }
    else
    {
        cout << (n-p+1) << " ";
        increasingDecreasing( p-1, n);
        cout << (n-p+1) << " ";
    }
    
}

void increasing ( int x)
{
    if ( x == 0)
    {
        cout << endl;
        return;
    }
    increasing ( x-1);
    cout << x << " ";
}

void decreasing ( int x)
{
    if ( x == 0)
    {
        cout << endl;
        return;
    }

    cout << x << " ";
    decreasing( x-1);
}

int main()
{
    int n;
    cin >> n;

    cout << "first decreasing then increasing order\n";
    decreasingIncreasing( n);
    cout << '\n';
    cout << "first increasing then decreasing order\n";
    increasingDecreasing( n, n);

    cout << "\nsimply increasing\n";
    increasing(5);
    cout << "\nsimply decreasing\n";
    decreasing(5);
    return EXIT_SUCCESS;

}