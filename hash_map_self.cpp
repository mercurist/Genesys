#include <bits/stdc++.h>
using namespace std;

int hash_code(string x)
{
    int result = 0;
    for (size_t i = 0; i < x.size(); i++)
    {
        result += int(x[i]);
    }
    return result;
}

int main()
{
    // here we allocate a very large array and uses up alot of space (drawback)
    // alternatively, we can use a balanced binary search tree which provides lookup in 0(log N) time
    // and we can also iterate through the keys in order

    // unordered_map uses this implementation using chaining for collisions
    // in this case, if there are alot of collisions , time complexity=  O(N)
    // if there are few collisions, lookup time is O(1)

    // ordered_map uses balanced BST
    list<pair<string, int>> counts[2000];
    string list[10];

    for (int i = 0; i < 10; i++)
    {
        bool flag = false;
        cin >> list[i];
        int hash_function_result = hash_code(list[i]);
        int index = (hash_function_result % 2000);
        auto itr = counts[index].begin();
        for (auto itr = counts[index].begin(); itr != counts[index].end(); itr++)
        {
            if (itr->first == list[i])
            {
                itr->second++;
                flag = true;
            }
        }

        if (flag == true)
            continue;

        counts[index].push_back(make_pair(list[i], 1));
        cout << "at " << index << " pushed the pair " << list[i] << 1 << '\n';
    }

    for (int i = 0; i < 2000; i++)
    {
        for (auto x : counts[i])
            cout << i << " " << x.first << '\t' << x.second << '\n';
    }
    return 0;
}