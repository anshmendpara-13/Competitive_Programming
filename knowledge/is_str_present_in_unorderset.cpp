#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_set<string> s; // all of thing in O(1) find, insert, etc... only we add basic datatype not use set of set ...
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s.insert(str);
    }

    int q;
    cin >> q;

    while (q--)
    {
        string present;
        cin >> present;

        // s.find() == s.end() so not present else present

        auto it = s.find(present);
        if (it != s.end())
        {
            cout << "PRESENT" << endl;
        }
        else
        {
            cout << "NOT PRESENT" << endl;
        }
    }

    // cout <<  <<endl;
    return 0;
}