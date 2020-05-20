#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> prices(5, 0);
    for( int i = 0; i< 5; i++)
        cout << prices[i] << " ";
    cout << "\nsize\t\t" << prices.size();
    cout << "\ncapacity\t" << prices.capacity();

    vector<int> days;
    cout << "\nsize\t\t" << days.size();
    cout << "\ncapacity\t" << days.capacity();
    
    for( int i = 0; i < 16; i++)
    {
        days.push_back(i);
        cout << "\nsize\t\t" << days.size();
        cout << "\ncapacity\t" << days.capacity();
    }

    return 0;
}