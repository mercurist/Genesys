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

    return p;
}

int main()
{
    int N, count = 2;
    cin >> N;
    vector<int> listOfPrimes = sieveOfEratosthenesOptimized( N);
    vector<int> result;
    cout << "\nthe prime factors of "<< N << " are\n";

    while ( N != 1)
    {
        if( listOfPrimes[count] == 1)
        {
            while(( N % count) == 0)
            {
                N /= count;
                result.push_back(count);
                
            }
        }

        count++;
    }

    for( int i = 0;  i < result.size(); i++)
        cout << result[i] << " ";
    
    return EXIT_SUCCESS;
}