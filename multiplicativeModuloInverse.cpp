/*
the objective is to find 'b' such that 
    (a*b)%m = 1.
we have 'a' and 'm' as the input, and 'b' here is referred to as the multiplicative modulo inverse of 'a' with respect to 'm'. 
we write (a*b) mod m = 1
as follows
    (a*b) mod m = 1
    ab = mk + 1
    ab - mk = 1

substituting -k as k', we get
    ab + mk' = 1            ... equation I
this equation is similar to the one in Euclidean algorithm, where we have :
    Ax + By = GCD(A, B)     ... equation II

we draw the analogy as follows :
    A -> a
    x -> b
    B -> m
    y -> k'
    1 -> GCD( a, m)

the above inference is an integral concept to the idea of multiplicative modulo inverse which states that MMO of 'a' wrt 'm' exists iff GCD( a, m) = 1.
the variable 'b' in equation I refers to the value of 'x' in the extended Euclidean algortihm.
*/
#include <iostream>
#define ll long long int

using namespace std;

int extendedGCD( int a, int b, int &x, int &y)
{
    if ( b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    else
    {
        int x1, y1;
        int result = extendedGCD( b, a%b, x1, y1);
        x = y1;
        y = x1 - (a/b)*y1;
        return result;
    }
}

int main()
{
    int a, b, x, y;
    cin >> a >> b;
    int result = extendedGCD( a, b, x, y);

    cout << a << " * " << x << " + " << b << " * " << y << " = " << result;
    if ( x < 0)
        x = x + b;
    cout << "\n\nMultiplicative modulo inverse of " << a << " with respect to " << b << " is " << x;
    return EXIT_SUCCESS;
}