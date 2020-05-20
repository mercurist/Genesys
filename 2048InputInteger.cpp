#include <iostream>

using namespace std;

void display(int c)
{
    switch(c)
    {
        case 0 :  cout << "zero ";
                    break;
        case 2 :  cout << "two ";
                    break;
        case 3 :  cout << "three ";
                    break;
        case 4 :  cout << "four ";
                    break;
        case 5 :  cout << "five ";
                    break;
        case 6 :  cout << "six ";
                    break;
        case 7 :  cout << "seven ";
                    break;
        case 8 :  cout << "eight ";
                    break;
        case 9 :  cout << "nine ";
                    break;
        case 1 :  cout << "one ";
    }
}

void spellIt( int x)
{

    int a = x/10;
    int b = x%10;

    // base case
    if ( a == 0)
    {
        display(b);
        return;
    }

    spellIt(a);
    display(b);
}

int main()
{
    int x;
    cin >> x;
    
    spellIt(x);
    return EXIT_SUCCESS;
}