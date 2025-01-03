#include <bits/stdc++.h>

using namespace std;

int main()
{
    // range base loop and auto key word
    // vector<int> v = {1, 2, 5, 6, 7, 8, 2};

    // for (auto i : v) // i is copy
    // {
    //     cout << i << endl;
    //     i++;
    // }
    // cout << endl;

    // for (auto &i : v) // i is reference
    // {
    //     cout << i << endl;
    // }

    // vector<pair<int, int>> v_p = {{1, 2}, {3, 4}, {5, 6}};

    // for (auto &i : v_p)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }

    vector<int> v = {2, 3, 5, 6, 9};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    cout << endl;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << endl;
    }

    return 0;
}