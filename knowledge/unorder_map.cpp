#include <bits/stdc++.h>

using namespace std;
void print_ms(unordered_map<string, string> &m)
{
    for (auto &&i : m) // insertion and access time complexity log(n)
    {
        cout << i.first << " " << i.second << endl;
    }
}

int main()
{
    // inbuild implementation, -->> key hash value and use hash table use
    // time complexity, ->> O(1) average  in insertion
    // valid key datatype
    // find(), erase() ->> O(1)

    unordered_map<string, string> ms;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;
        ms.insert({x, y}); // in this time we use string as a key so time complexity is O(log(n)*string_size)
    }

    print_ms(ms);
    return 0;
}