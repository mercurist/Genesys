#include <iostream>

using namespace std;

int waysOfTheWest( int x)
{   
    if ( x <= 0)
        return 0;
    else if ( x == 1 || x == 2 || x == 3 )
        return 1;
    else if ( x == 4)
        return 2;

    return waysOfTheWest( x - 1) + waysOfTheWest( x -4);
}

int main()
{
    int n;
    cin >> n;
    cout << waysOfTheWest( n);
    return EXIT_SUCCESS;
}