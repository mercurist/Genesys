#include <iostream>
#include <vector>

using namespace std;

void subsequences( char* x, string str)
{
    if ( x[0] == '\0')
    {
        cout << str << ',';
        return;
    }

    subsequences(x+1, str);
    str.push_back(x[0]);
    subsequences(x+1, str);
}

void subsequencesPointers( char* in, char *out, int x, int y)
{
    if ( in[x] == '\0')
    {
        out[y] = '\0';
        cout << out << ',';
        return;
    }

    // recursive case 
    // exclude the in[x] element
    subsequencesPointers(in, out, x+1, y);
    // include the in[x] element
    out[y] = in[x];
    subsequencesPointers(in, out, x+1, y+1);

    
    

}

int main()
{
    char output[20];
    char input[] = "abc";
    // string x;
    // subsequences( input, x);
    int x= 0, y= 0;
    subsequencesPointers(input, output, x, y);
    return EXIT_SUCCESS;
}