#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
#define ll long long int

using namespace std;

ll a[1000006]= {0};
ll lastOcc[1000006]= {0};
ll ans[1000006]= {0};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    
    for( int i = 1; i <= N; i++)
        cin >> a[i];
    
    memset(lastOcc, 0, sizeof(lastOcc));
    memset(ans, 0, sizeof(ans));

    double sum = 0.0;
    ans[0] = 0;
    for( int i = 1; i <= N; i++)
    {
        ans[i] = ans[i-1] + ( i - lastOcc[a[i]]);
        lastOcc[a[i]] = i;
        sum += ans[i];
    }
    
    double finalAns = 0.0;
    finalAns = (2*(sum - N) + N)/ ( N*N*1.0);

    cout  << fixed << setprecision(6) << finalAns << '\n';

    return EXIT_SUCCESS;
}