#include <bits/stdc++.h>

using namespace std;

void print_mp(map<pair<string, string>, vector<int>> &m) // this store in sorted order of pair
{
    for (auto &pr : m)
    {
        // auto &full_name = pr.first;
        // auto &list = pr.second;

        // cout << full_name.first + " " + full_name.second << endl;
        // cout << list.size() << endl;
        // for (auto &j : list)
        // {
        //     cout << j << " ";
        // }
        // cout << endl;

        cout << pr.first.first << " " << pr.first.second << endl;

        cout << pr.second.size() << endl;

        for (auto &i : pr.second)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    map<pair<string, string>, vector<int>> m; // in map key store in sorted order

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string fn, ln;
        int ct;
        cin >> fn >> ln >> ct;
        for (int j = 0; j < ct; j++)
        {
            int x;
            cin >> x;
            m[{fn, ln}].push_back(x);
        }
    }

    print_mp(m);

    return 0;
}