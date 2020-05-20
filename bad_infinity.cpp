#include <bits/stdc++.h>
using namespace std;

static int counting;

void function_one();
void function_two();

void function_one()
{
    cout << "one\t" << counting << '\n';
    counting++;
    /*
    if (counting > 11)
    {
        return;
    }
    */
    function_two();
}

void function_two()
{

    cout << "two\t" << counting << '\n';
    counting++;
    function_one();
}

int main()
{
    function_one();
    return 0;
}