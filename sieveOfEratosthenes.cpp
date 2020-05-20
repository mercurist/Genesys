#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

bool isPrimeRootInHalf( int x)
{
    if ( x == 1)        return true;
    if ( x == 2)        return true;
    if (( x % 2) == 0)  return false;
    for( int i = 3; i*i <= x; i++)
    {
        if (( x % i) == 0)
        return false;
    }
    return true;
}

void listOfPrimesNaive( int N)
{
    for( int i = 2; i <=N; i++)
    {
        if ( isPrimeRootInHalf(i))
            cout << i << " ";
    }
}

void sieveOfEratosthenes( int N)
{
    bool primeOrNot[N+1];
    memset(primeOrNot, 1, sizeof(primeOrNot));
    primeOrNot[0] = primeOrNot[1] = 0;
    for( int i =2; i*i <= N; i++)
    {
        if ( isPrimeRootInHalf(i))
        {
            primeOrNot[i] = true;
            for( int p = 2*i; p <= N; p += i)
            {
                primeOrNot[p] = false;
            }
        }
    }

    for( int i =0; i <= N; i++)
    {
        if ( primeOrNot[i] == true)
            cout << i << " ";
    }
}

void sieveOfEratosthenesOptimized( int N)
{
    int p[N+1] = {0};
    p[2] = {1};
    for( int i = 3; i <= N; i+=2)
        p[i] = 1;
    for( int i = 3; i <= N; i+=2)
    {
        if ( p[i] == 1)
        {
            // mark all multiples of i as non-prime
            for( int j = i*i; j <= N; j+= 2*i)
            {
                p[j] = 0;
            }
        }
    }

    for( int i = 0; i <= N; i++)
    {
        if ( p[i] == 1)
            cout << i << " ";
    }
}

int main()
{
    int N;
    cin >> N;

    listOfPrimesNaive(N);
    cout << '\n';
    sieveOfEratosthenes(N);
    cout << '\n';
    sieveOfEratosthenesOptimized(N);
    return EXIT_SUCCESS;
}