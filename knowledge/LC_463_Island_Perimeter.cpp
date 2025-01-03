#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int islandPerimeter(vector<vector<int>> &grid)
{
    if (grid.empty())
        return 0;

    int perimeter = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 1)
            {
                perimeter += 4; // Each land cell contributes 4 to the perimeter

                if (i > 0 && grid[i - 1][j] == 1)
                    perimeter -= 2;
                if (j > 0 && grid[i][j - 1] == 1)
                    perimeter -= 2;
            }
        }
    }

    return perimeter;
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

    cout << islandPerimeter(grid) << endl;
    return 0;
}