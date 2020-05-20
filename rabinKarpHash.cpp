#include <bits/stdc++.h>
#define ll long long int
#define prime 7

using namespace std;

ll createHashValue(string pattern, int patLength)
{
    ll result = 0;
    for (int i = 0; i < patLength; i++)
    {
        result += (ll)(pattern[i] * (ll)pow(prime, i));
    }

    return result;
}

ll updateHash(string pattern, int oldIndex, int newIndex, ll oldHash, int patLength)
{
    ll newHash = oldHash - pattern[oldIndex];
    newHash /= prime;
    newHash += (ll)(pattern[newIndex] * (ll)(pow(prime, patLength - 1)));
    return newHash;
}

int main()
{
    int counter = 0;
    string phrase, pattern;
    cin >> phrase >> pattern;
    int patLength = pattern.size();
    ll hashSubstring = createHashValue(phrase, patLength);
    ll hashPattern = createHashValue(pattern, patLength);
    for (int i = 0; i <= phrase.size() - pattern.size(); i++)
    {
        bool flag = true;
        if (hashSubstring == hashPattern)
        {
            for (int j = 0; j < patLength; j++)
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

        if (i < phrase.size() - pattern.size())
            hashSubstring = updateHash(pattern, i, i + patLength, hashSubstring, patLength);
    }

    cout << counter << '\n';
    return EXIT_SUCCESS;
}