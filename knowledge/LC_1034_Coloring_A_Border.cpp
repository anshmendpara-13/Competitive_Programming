#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(vector<vector<int>> &grid, int row, int col, int color)
{
    grid[row][col] = -color;
    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        int rowdash = row + dir[i][0];
        int coldash = col + dir[i][1];

        if (rowdash < 0 || coldash < 0 || rowdash >= grid.size() || coldash >= grid[0].size() || abs(grid[rowdash][coldash]) != color)
        {
            continue;
        }
        cnt++;
        if (grid[rowdash][coldash] == color)
        {
            dfs(grid, rowdash, coldash, color);
        }
    }
    if (cnt == 4)
    {
        grid[row][col] = color;
    }
}

vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
{
    int count = 0;
    for (const auto &row : grid)
    {
        for (int num : row)
        {
            if (num == 1)
            {
                count++;
            }
        }
    }
    if (count == grid.size() * grid[0].size())
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1)
                {
                    grid[i][j] = color;
                }
            }
        }
        return grid;
    }

    dfs(grid, row, col, grid[row][col]);

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] < 0)
            {
                grid[i][j] = color;
            }
        }
    }
    return grid;
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

    int row, col, color;
    cin >> row >> col >> color;

    vector<vector<int>> ans = colorBorder(grid, row, col, color);

    for (auto &sl : ans)
    {
        for (auto &s : sl)
        {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
