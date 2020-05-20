#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    char data;
    unordered_map<char, node *> hashmap;
    bool isTerminal;

    node(char ch)
    {
        data = ch;
        isTerminal = false;
    }
};

class Trie
{
private:
    node *root;

public:
    Trie()
    {
        root = new node('\0');
    }

    void addWord(char *word)
    {
        node *temp = root;

        for (int i = 0; word[i] != '\0'; i++)
        {
            char currentChar = word[i];
            if (temp->hashmap.count(currentChar) == 1)
            {
                temp = temp->hashmap[currentChar];
            }
            else
            {
                node *child = new node(currentChar);
                temp->hashmap[currentChar] = child;
                temp = child;
            }
        }

        temp->isTerminal = true;
    }

    bool LookUp(char *word)
    {
        node *temp = root;

        for (int i = 0; word[i] != '\0'; i++)
        {
            char currentChar = word[i];
            if (temp->hashmap.count(currentChar) == 1)
            {
                temp = temp->hashmap[currentChar];
            }
            else
            {
                return false;
            }
        }

        return (temp->isTerminal);
    }
};

int main()
{
    char words[10][100] = {"apple", "mango", "ape", "not", "no", "news", "pineapple", "code"};
    Trie dictionary;
    for (int i = 0; i < 8; i++)
    {
        dictionary.addWord(words[i]);
    }

    char searchWord[100];
    cin.getline(searchWord, 100);
    cout << dictionary.LookUp(searchWord);

    return EXIT_SUCCESS;
}