#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, int> m;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        // ****** below both are same *******
        m[s]++;
        // m.insert({s,m[s]++});
    }

    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    // cout <<  <<endl;
    return 0;
}