#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int theGoodDays( short int days, vector<short int> prices)
{
    int count = 1;
    short int i, min;
    vector<short int> records;
    records.resize(days);
    records[0] = prices[0];
    vector<short int> :: iterator itr1, itr2;
    itr1 = records.begin();
    itr2 = itr1;
    for( i = 1; i < days; i++)
    {
        if ( i >= 5)
        {
            itr1++;
        }
        itr2++;
        records[i] = prices[i];
        if ( prices[i] < *min_element(itr1, itr2))
        {
            count++;
        }
    }

    return count;
}

int main()
{
    ios_base :: sync_with_stdio( false);
    cin.tie( NULL);

    short int testCases, days;
    vector<short int> prices;
    cin >> testCases;
    while ( testCases--)
    {
        cin >> days;
        prices.resize( days);
        for( int i = 0; i < days; i++)
            cin >> prices[i];

        cout << theGoodDays( days, prices) << '\n';
    }

    return 0;
}