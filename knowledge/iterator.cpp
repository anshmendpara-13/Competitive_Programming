#include <bits/stdc++.h>

using namespace std;

int main()
{
    // vector<int> v = {2, 3, 5, 6, 9};
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << endl;
    // }

    // cout << endl;
    // vector<int>::iterator it = v.begin(); // is continueus
    // cout << *(it + 2) << endl;

    // vector<int>::iterator it; // is continueus
    // for (it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *(it) << endl;
    // }

    // vector<pair<int, int>> v_p = {{1, 2}, {3, 4}, {5, 6}};
    // vector<pair<int, int>>::iterator it;

    // for (it = v_p.begin(); it != v_p.end(); it++)
    // {
    //     // cout << (*it).first << " " << (*it).second << endl;
    //     cout << it->first << " " << it->second << endl;
    // }

    vector<pair<int, int>> v_p;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v_p.push_back({x, y});
    }

    // Print the vector of pairs
    for (const auto &p : v_p)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}