#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e3 + 7;
const int INF = 1e9 + 7;

int val[N][N];
int visited[N][N];
int level[N][N];
int n, m;

bool isvalid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

vector<pair<int, int>> movements = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 0;
            level[i][j] = INF;
        }
    }
}

int bfs()
{
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mx = max(mx, val[i][j]);
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mx == val[i][j])
            {
                q.push({i, j});
                level[i][j] = 0;
                visited[i][j] = 1;
            }
        }
    }
    int ans = 0;
    while (!q.empty())
    {
        auto v = q.front();
        int v_x = v.first;
        int v_y = v.second;

        q.pop();
        for (auto movement : movements)
        {
            int child_x = movement.first + v_x;
            int child_y = movement.second + v_y;
            if (!isvalid(child_x, child_y))
                continue;
            if (visited[child_x][child_y])
                continue;
            q.push({child_x, child_y});
            level[child_x][child_y] = level[v_x][v_y] + 1;
            visited[child_x][child_y] = 1;
            ans = max(ans, level[child_x][child_y]);
        }
    }
    return ans;
}

int main()
{
    // CC - snakes and transition from capitalism to socialism
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        reset();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> val[i][j];
            }
        }

        cout << bfs() << endl;
    }

    return 0;
}