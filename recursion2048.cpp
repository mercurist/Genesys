#include <iostream>

using namespace std;

void display(char c)
{
    switch(c)
    {
        case '0' :  cout << "zero ";
                    break;
        case '2' :  cout << "two ";
                    break;
        case '3' :  cout << "three ";
                    break;
        case '4' :  cout << "four ";
                    break;
        case '5' :  cout << "five ";
                    break;
        case '6' :  cout << "six ";
                    break;
        case '7' :  cout << "seven ";
                    break;
        case '8' :  cout << "eight ";
                    break;
        case '9' :  cout << "nine ";
                    break;
        case '1' :  cout << "one ";
    }
}

void spellIt( string:: iterator itr, int n)
{
    if ( n == 0)
        return;

   display(itr[0]);
   spellIt(itr+1, n-1);
}

int main()
{
    string x;
    string :: iterator itr = x.begin();
    
    cin >> x;
    int n = x.size();
    spellIt( itr, n);
    return EXIT_SUCCESS;
}