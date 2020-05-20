#include <bits/stdc++.h>
using namespace std;

int hashValue(string x, int p, int r)
{
    int result = 0;
    for (int i = p; i < r; i++)
        result = result + int(x[i]);

    return result;
}

int main()
{
    string phrase, pattern;
    cin >> phrase >> pattern;
    int patternSize = pattern.size();
    int phraseSize = phrase.size();
    int count = 0;
    int hashPattern = hashValue(pattern, 0, patternSize);
    int hashSubstring = hashValue(phrase, 0, patternSize);

    int i = 0;
    while (i <= (phraseSize - patternSize))
    {
        if (hashPattern == hashSubstring)
        {
            bool flag = true;
            for (int j = 0; j < patternSize; j++)
            {
                if (phrase[i + j] != pattern[j])
                {
                    flag = false;
                    break;
                }
            }

            if (flag == true)
                count++;
        }

        hashSubstring += int(phrase[i + patternSize]) - int(phrase[i]);
        i++;
    }

    cout << count;
    return EXIT_SUCCESS;
}