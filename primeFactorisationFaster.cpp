#include <iostream>
#include <vector>

using namespace std;

vector<int> sieveOfEratosthenesOptimized( int N)
{
    vector<int> p(N+1, 0);
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

    vector<int> results;
    for(int i = 0; i <= N; i++)
    {
        if ( p[i] == 1)
            results.push_back(i);
    }

    return results;
}

// this returns a vector of prime factors
vector<int> factorize(int N, const vector<int> &primes)
{
    vector<int> factors;
    int i = 0;
    
    while (( primes[i]*primes[i]) <= N)
    {
        if (( N % primes[i]) == 0)
        {
            factors.push_back(primes[i]);
            while (( N % primes[i]) == 0)
            {
                N /= primes[i];
            }
        }

        i++;
    }

    if ( N != 1)
    {
        factors.push_back(N);
    }

    return factors;
}

int main()
{
    int N, count = 2;
    cin >> N;
    vector<int> listOfPrimes = sieveOfEratosthenesOptimized( N);
    vector<int> result = factorize(N, listOfPrimes);
    cout << "\nthe prime factors of "<< N << " are\n";

    for( int i = 0;  i < result.size(); i++)
        cout << result[i] << " ";
    
    return EXIT_SUCCESS;
}