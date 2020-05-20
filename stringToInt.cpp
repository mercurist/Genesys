#include <iostream>
#include <cmath>

using namespace std;

int stringToInt( string x)
{
    int result = 0;
    // iterative method
    for( int i = 0; i < x.size(); i++)
        result = (result * 10) + x[i] - '0';
    
    return result;
}

int stringToIntRecursive( string str)
{
    if ( str.length() == 1)
        return str[0] - '0';
    
    double y = stringToIntRecursive( str.substr(1));
    double x = str[0] - '0';

    x = x * pow(10, str.length() - 1) + y;
    return int(x);

}

int main()
{
    string x;
    cin >> x;
    cout << "half of " << x << " is " << stringToInt( x)/2;
    cout << "\nhalf of " << x << " is " << stringToIntRecursive( x)/2;
    return EXIT_SUCCESS;
}