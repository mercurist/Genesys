#include <iostream>
#include <cstring>

using namespace std;

int factorial( int n)
{
    if ( n == 0 || n == 1)
        return 1;
    else
    {
        return n * factorial( n-1);
    }
}

// C( n, r) = [n! / ( r! * ( n-r)!)]
int binomialCoefficientSoNaive( int n, int k)
{
    return factorial(n) / ( factorial(k) * factorial( n-k));
}

// time complexity = O( k)
// space complexity = O( 1)
int binomialCoefficient( int n, int k)
{
    int result = 1;
    if (k > n - k)
        k = n - k;
    for( int i = 1; i <= k; i++)
    {
        result *= (n - i + 1);
        result /= i;
    }

    return result;
}

// time complexity = O( n * k)
// space complexity = O( n * k)
int binomialCoefficientTwo( int n, int k)
{
    int C[n+1][k+1];

    for( int i = 0 ; i <=n; i++)
    {
        for( int j = 0; j <= min(i, k); j++)
        {
            if ( j == 0 || j == i)
                C[i][j] = 1.;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];              // uses the identity C( n, r) = C( n-1, r-1) + C( n-1, r)
        }
    }

    return C[n][k];
}

// time complexity = O( n * k)
// space complexity = O( k)
int binomialCoefficientButSpaceOptimized( int n, int k)
{
    int C[k+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;

    for( int i = 1; i <= n; i++)
    {
        for( int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];      // builds up the ith row by using the (i -1)th row of the pascal's triangle.
    }

    return C[k];
}

int binomialCoefficientsWithOverlappingSubproblems( int a, int b)
{
    if ( b == 0 || b == a)
    {
        return 1;
    }
    else
    {
        return binomialCoefficientsWithOverlappingSubproblems( a-1, b-1) + 
                binomialCoefficientsWithOverlappingSubproblems(a-1, b);
    }
    
}

int main()
{
    int a, b;
    cin >> a >> b;
    if ( a > b)
    {
        cout << binomialCoefficientsWithOverlappingSubproblems( a, b) << '\n';
        cout << binomialCoefficientSoNaive( a, b) << '\n';
        cout << binomialCoefficient( a, b) << '\n';
        cout << binomialCoefficientTwo( a, b) << '\n';
        cout << binomialCoefficientButSpaceOptimized( a, b) << '\n';
    }

    else
        cout << "b cannot be greater than a";
    
    return EXIT_SUCCESS;
}