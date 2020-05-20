#include <bits/stdc++.h>
using namespace std;

int occurrences(string phrase, string pattern)
{
    int counter = 0;
    for (int i = 0; i <= phrase.size() - pattern.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < pattern.size(); j++)
        {
            if (phrase[i + j] != pattern[j])
            {
                flag = false;
                break;
            }
        }

        if (flag == true)
            counter++;
    }

    return counter;
}

int main()
{
    string phrase, pattern;
    cin >> phrase >> pattern;

    cout << occurrences(phrase, pattern);
    return EXIT_SUCCESS;
}