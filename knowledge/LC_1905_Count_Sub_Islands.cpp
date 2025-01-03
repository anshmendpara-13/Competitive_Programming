#include <bits/stdc++.h>
using namespace std;

bool solve(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j, int &flag)
{
    if (i < 0 || j < 0 || i >= grid2.size() || j >= grid2[0].size())
        return true;
    if (grid2[i][j] == 0)
        return true;
    if (grid2[i][j] == 1)
    {
        if (grid1[i][j] == 0)
        {
            flag = 0;
            return true;
        }
        grid2[i][j] = 0;
    }
    solve(grid1, grid2, i + 1, j, flag);
    solve(grid1, grid2, i, j + 1, flag);
    solve(grid1, grid2, i, j - 1, flag);
    solve(grid1, grid2, i - 1, j, flag);

    return false;
}

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    int count = 0;
    for (int i = 0; i < grid2.size(); i++)
    {
        for (int j = 0; j < grid2[0].size(); j++)
        {
            int flag = 1;
            if (grid2[i][j] == 1)
            {
                solve(grid1, grid2, i, j, flag);
                if (flag == 1)
                    count++;
            }
        }
    }
    return count;
}
int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid1(m, vector<int>(n));
    vector<vector<int>> grid2(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid1[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid2[i][j];
        }
    }

    cout << countSubIslands(grid1, grid2) << endl;
    return 0;
}
