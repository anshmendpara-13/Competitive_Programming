#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

string convert(const string &s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }

    int size_loop = 2 * numRows - 2;
    map<int, vector<char>> mp;

    for (int i = 0; i < s.length(); i++)
    {
        int row = i % size_loop;
        if (row >= numRows)
        {
            row = size_loop - row;
        }
        mp[row].push_back(s[i]);
    }

    // for (auto i : mp)
    // {
    //     cout << i.first << endl;
    //     for (auto val : i.second)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    string result = "";
    for (int i = 0; i < numRows; i++)
    {
        for (char ch : mp[i])
        {
            result += ch;
        }
    }

    return result;
}

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;

    cout << convert(s, n) << endl;
    return 0;
}