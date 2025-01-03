#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// bool should_i_swap(int &a, int &b)
// {
//     return a > b;
// }

// bool should_i_swap(pair<int, int> &a, pair<int, int> &b)
// {
//     // return (a.first > b.first);
//     if (a.first != b.first)
//     {
//         if (a.first > b.first) // small is first
//         {
//             return true;
//         }
//         return false;
//     }
//     else
//     {
//         if (a.second < b.second) // small is first
//         {
//             return true;
//         }
//         return false;
//     }
// }

bool should_i_swap(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first != b.first)
    {
        if (a.first > b.first) // big is first
        {
            return false;
        }
        return true;
    }
    else
    {
        if (a.second < b.second) // big is first
        {
            return false;
        }
        return true;
    }
}
int main()
{
    int n;
    cin >> n;

    // vector<int> v(n);
    //  for (int i = 0; i < n; i++)
    // {
    //     cin >> v[i];
    // }

    // vector<int> v;
    // for (int i = 0; i < n; i++)
    // {
    //     int temp;
    //     cin >> temp;
    //     v.push_back(temp);
    // }

    // vector<pair<int, int>> v(n);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        // v.emplace_back(make_pair(x, y));

        // cin >> v[i].first >> v[i].second;
    }

    // SORTING
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (should_i_swap(v[i], v[j]))
    //         {
    //             swap(v[i], v[j]);
    //         }
    //     }
    // }

    // sort(v.begin(), v.end());                // defalut full are ascending order
    // sort(v.begin(), v.end(), should_i_swap); // comperator
    // sort(v.begin(), v.end(), greater<pair<int, int>>()); // inbuild

    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }

    // cout <<  <<endl;
    return 0;
}