/* Output ? */
#include <iostream>
using namespace std;

int main()
{
    long signed a = 2017;
    short unsigned b = -2018;
    unsigned c = -2019;
    int d = -2020;
    long long unsigned e = -2021;
    short unsigned f = 2018.9;
    long signed g = 'A';
    cout << a << endl;
    cout << b << endl
         << c << endl
         << d << endl
         << e << endl;
    cout << f << endl;
    cout << g << endl;

    return 0;
}