#include <iostream>

using namespace std;

int recursiveExpLogarithmicTime( int a, int b)
{
    if ( b == 0)
        return 1;
    else
    {
        int smallPower = recursiveExpLogarithmicTime( a, b/2);
        smallPower = smallPower*smallPower;
        if ( b & 1)
            return a * smallPower;
        else
        {
            return smallPower;
        }
    }

}

int recursiveExp( int a, int b)
{
    if ( b == 0)
        return 1;
    else
        return (a*recursiveExp( a, b-1));
}



int main()
{
    int a, b;
    cin >> a >> b;

    cout << "a (exp) b = " << recursiveExpLogarithmicTime( a, b); 
    cout << "\na (exp) b = " << recursiveExp( a, b);
    return EXIT_SUCCESS;
}