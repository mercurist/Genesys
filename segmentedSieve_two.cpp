#include <iostream>
#include <cmath>
#include <cstring>
#define ll long long int

using namespace std;

void segmentedSieve( ll a, ll b)
{
    ll arr1[b-a];
    memset(arr1, -1, sizeof(arr1));
    int m = sqrt(b);
    ll arr2[m+1] = {0};
    arr2[2] = 1;
    for( int i = 3; i <= m; i+=2)
        arr2[i] = 1;
    for( int i = 3; i <= m; i+=2)
    {
        if ( arr2[i])
        {
            for( int j = i*i; j <= m; j+=2*i)
            {
                arr2[j] = 0;
            }
        }
    }

    for( int i = 1; i <= m; i++)
    {
        if ( arr2[i] == 0)
            continue;
        else
        {
            for( int j = 0; j < b-a; j++)
            {
                if ((( a + j)% i) == 0)
                {
                    for( int k = j; k < b-a; k += i)
                    {
                        arr1[k] = 0;
                    }
                }
            }
        }
    }

    for( int i = 0; i < b-a; i++)
    {
        if ( arr1[i] == -1)
            cout << a + i << " ";
    }
}

int main()
{
    ll a, b;
    cin >> a >> b;

    segmentedSieve( a, b);
    return EXIT_SUCCESS;
}