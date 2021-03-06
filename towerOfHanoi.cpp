#include <iostream>

using namespace std;

void towerOfHanoi( int n, char src, char dest, char helper)
{
    if ( n == 0)
        return;
    
    towerOfHanoi( n-1, src, helper, dest);
    cout << "move " << n << " disk from " << src << " to " << dest << endl;
    towerOfHanoi( n-1, helper, dest, src);
}

int main()
{
    int n = 4;
    towerOfHanoi(n, 'A', 'B', 'C');
    return EXIT_SUCCESS;
}