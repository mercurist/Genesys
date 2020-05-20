#include <bits/stdc++.h>
using namespace std;

int levenshteinHelper(string s1, string s2, int n1, int n2, int i, int j)
{
    if (i == n1)
        return n2 - j;
    if (j == n2)
        return n1 - i;
    if (s1[i] == s2[j])
        return levenshteinHelper(s1, s2, n1, n2, i + 1, j + 1);
    else
    {
        // replacement or modification
        int q1 = 1 + levenshteinHelper(s1, s2, n1, n2, i + 1, j + 1);
        // for deletion
        int q2 = 1 + levenshteinHelper(s1, s2, n1, n2, i + 1, j);
        // for insertion
        int q3 = 1 + levenshteinHelper(s1, s2, n1, n2, i, j + 1);
        return min(q1, min(q2, q3));
    }
}

int levenshtein(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();

    return levenshteinHelper(s1, s2, n1, n2, 0, 0);
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << levenshtein(s1, s2);
    return 0;
}