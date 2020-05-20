#include <iostream>
#define MAX_N 100005

using namespace std;
int reset[MAX_N];

void KMPPreprocess(string pattern)
{
    reset[0] = -1;
    int i = 0, j = -1;
    while (i < pattern.size())
    {
        while (j >= 0 and pattern[i] != pattern[j])
            j = reset[j];

        i++, j++;
        reset[i] = j;
    }
}

void KMPAlgorithm(string phrase, string pattern)
{
    KMPPreprocess(pattern);
    int i = 0, j = 0;
    while (i < phrase.size())
    {
        while (j >= 0 and phrase[i] != pattern[j])
            j = reset[j];

        i++, j++;

        if (j == pattern.size())
        {
            cout << "pattern found at " << i - j << '\n';
            j = reset[j];
        }
    }
}

int main()
{
    for (int i = 0; i < MAX_N; i++)
        reset[i] = -1;
    string phrase, pattern;
    cin >> phrase >> pattern;

    KMPAlgorithm(phrase, pattern);
    return EXIT_SUCCESS;
}