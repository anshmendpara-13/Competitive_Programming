#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    if (matrix.empty())
    {
        return ans;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    int l = 0, r = cols - 1, t = 0, b = rows - 1;

    while (l <= r && t <= b)
    {
        for (int i = l; i <= r; i++)
        {
            ans.push_back(matrix[t][i]);
        }
        t++;
        for (int i = t; i <= b; i++)
        {
            ans.push_back(matrix[i][r]);
        }
        r--;
        if (t <= b)
        {
            for (int i = r; i >= l; i--)
            {
                ans.push_back(matrix[b][i]);
            }
            b--;
        }
        if (l <= r)
        {
            for (int i = b; i >= t; i--)
            {
                ans.push_back(matrix[i][l]);
            }
            l++;
        }

    }
        return ans;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<int> ans = spiralOrder(v);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    // for (auto sv : v)
    // {
    //     for (auto val : sv)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}