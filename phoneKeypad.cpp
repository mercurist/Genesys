#include <iostream>

using namespace std;

char keypad[][10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keyMap(char* input, char* output, int x, int y)
{
    if( input[x] == '\0')
    {
        output[y] = '\0';
        cout << output << ',';
        return;
    }

    int digit = input[x] - '0';
    for(int k =0; keypad[digit][k] != '\0' ; k++)
    {
        output[y] = keypad[digit][k];
        keyMap(input, output, x+1, y+1);
    }
}

int main()
{
    char input[20];
    char output[20];
    cin >> input;

    keyMap(input, output, 0, 0);
    return EXIT_SUCCESS;
}