#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int dfs(vector<vector<int>> &grid, int x, int y, int &ct)
{
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1)
        return 0;

    grid[x][y] = 0;
    int area = 1; // Increment the area for the current cell

    // Explore all four directions
    area += dfs(grid, x, y + 1, ct);
    area += dfs(grid, x, y - 1, ct);
    area += dfs(grid, x + 1, y, ct);
    area += dfs(grid, x - 1, y, ct);

    return area;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int maxi = 0; 
    int ct = 0;
    if (grid.empty())
        return 0;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
            if (grid[i][j] == 1)
            {
                int cnt = dfs(grid, i, j, ct);
                maxi = max(maxi, cnt);
            }
    }
    return maxi;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << maxAreaOfIsland(grid) << endl;
    return 0;
}