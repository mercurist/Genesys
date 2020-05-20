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
    vector<int> listOfPrimes;
    vector<int> result1, result2;
    int a, b;
    cin >> a >> b;
    int u = a;
    int v = b;
    if ( a>b)
        listOfPrimes = sieveOfEratosthenesOptimized(a);
    else
    {
        listOfPrimes = sieveOfEratosthenesOptimized(b);
    }
    
    int count = 2;
    while ( a != 1)
    {
        if( listOfPrimes[count] == 1)
        {
            while(( a % count) == 0)
            {
                a /= count;
                result1.push_back(count);
            }
        }

        count++;
    }

    count = 2;
    while ( b != 1)
    {
        if( listOfPrimes[count] == 1)
        {
            while(( b % count) == 0)
            {
                b /= count;
                result2.push_back(count);
            }
        }

        count++;
    }
    cout << "\nthe prime factors of " << a << " are\t";
    for( int i = 0; i < result1.size(); i++)
        cout << result1[i] << " ";
    
    cout << "\nthe prime factors of " << b << " are\t";
    for( int i = 0; i < result2.size(); i++)
        cout << result2[i] << " ";

    vector<int> result3;
    int i = 0, j = 0;
    while ( i < result1.size() && j < result2.size())
    {
        if ( result1[i] == result2[j])
        {
            result3.push_back(result1[i]);
            i++;
            j++;
        }

        if ( result1[i] < result2[j])
        {
            i++;
        }
        if ( result1[i] > result2[j])
        {
            j++;
        }
    }

    int answer = 1;
    for( int i = 0; i < result3.size(); i++)
    {
        answer *= result3[i];
    }

    cout << "\ngcd of " << u << " and " << v << " is " << answer;
    return EXIT_SUCCESS;
}