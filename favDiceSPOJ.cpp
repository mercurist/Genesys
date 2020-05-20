#include <iostream>
#include <iomanip>
using namespace std;

#define ll long long int

int main()
{

    ios_base:: sync_with_stdio( false);
    cin.tie(NULL);
    short int t, x;
    cin >> t;
    double ans;
    while ( t--)
    {
        cin >> x;
        ans = 0;
        for( int i = 1; i <= x; i++)
        {
            ans += x/(i*1.0);
        }
        cout << setprecision(6) << ans << '\n';
    }

    return EXIT_SUCCESS;
}