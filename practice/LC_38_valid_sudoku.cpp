#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool isValidSudoku(vector<vector<char>> &v)
{
    vector<set<int>> rows(9), cols(9), blocks(9);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            if (v[i][j] == '.')
                continue;

            int curr = v[i][j] - '0';
            if (rows[i].count(curr) || cols[j].count(curr) || blocks[(i / 3) * 3 + j / 3].count(curr))
                return false;

            rows[i].insert(curr);
            cols[j].insert(curr);
            blocks[(i / 3) * 3 + j / 3].insert(curr);
        }
    }

    //  // Print the contents of each set in rows
    // cout << "Rows:" << endl;
    // for (int i = 0; i < 9; ++i) {
    //     cout << "Row " << i << ": ";
    //     for (int num : rows[i]) {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    // // Print the contents of each set in columns
    // cout << "\nColumns:" << endl;
    // for (int i = 0; i < 9; ++i) {
    //     cout << "Column " << i << ": ";
    //     for (int num : cols[i]) {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    // // Print the contents of each set in blocks
    // cout << "\nBlocks:" << endl;
    // for (int i = 0; i < 9; ++i) {
    //     cout << "Block " << i << ": ";
    //     for (int num : blocks[i]) {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    return true;
}

int main()
{
    vector<vector<char>> v;
    for (int i = 0; i < 9; i++)
    {
        vector<char> vv;
        for (int j = 0; j < 9; j++)
        {
            char c;
            cin >> c;
            vv.push_back(c);
        }
        v.push_back(vv);
    }

    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << isValidSudoku(v) << endl;

    // string s;
    // int cnt;

    // for (int i = 0; i < 3; i++)
    // {
    //     cnt = 0;
    //     for (int j = i; j < i + 3; j++)
    //     {
    //         if (v[i][j] != '.')
    //         {
    //             s += v[i][j];
    //         }
    //     }
    //     sort(s.begin(), s.end());
    //     cout << s << endl;
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         if (s[i] == s[i + 1])
    //         {
    //             cnt++;
    //             break;
    //         }
    //     }
    // }
    // cout << cnt << endl;

    return 0;
}