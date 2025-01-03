#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<vector<int>> findFarmland(vector<vector<int>> &land)
{
    vector<vector<int>> ans;
    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land[0].size(); j++)
        {
            if (land[i][j] == 1)
            {
                if ((i == 0 || land[i - 1][j] == 0) && (j == 0 || land[i][j - 1] == 0))
                {
                    int right = j;
                    int down = i;
                    while (down + 1 < land.size() && land[down + 1][j] == 1)
                    {
                        down++;
                    }
                    while (right + 1 < land[0].size() && land[i][right + 1] == 1)
                    {
                        right++;
                    }
                    ans.push_back({i, j, down, right});
                }
            }
        }
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> land(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> land[i][j];
        }
    }

    vector<vector<int>> ans = findFarmland(land);

    for (auto sl : ans)
    {
        for (auto s : sl)
        {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}