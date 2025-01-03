#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void dfs(int i, int j, int initialcolor, int newcolor, vector<vector<int>> &image)
{
    int n = image.size();
    int m = image[0].size();

    if (i < 0 || j < 0)
        return;
    if (i >= n || j >= m)
        return;
    if (image[i][j] != initialcolor)
        return;

    image[i][j] = newcolor;

    dfs(i - 1, j, initialcolor, newcolor, image);
    dfs(i + 1, j, initialcolor, newcolor, image);
    dfs(i, j - 1, initialcolor, newcolor, image);
    dfs(i, j + 1, initialcolor, newcolor, image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int initialcolor = image[sr][sc];
    if (initialcolor != color)
        dfs(sr, sc, initialcolor, color, image);

    return image;
}

int main()
{
    int m, n, sr, sc, newcol;
    cin >> m >> n >> sr >> sc >> newcol;

    vector<vector<int>> image(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> image[i][j];
        }
    }

    floodFill(image, sr, sc, newcol);

    for (auto si : image)
    {
        for (auto val : si)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}