#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 7;
const int INF = 1e9 + 7;
vector<int> g[N];
int visited[8][8];
int level[8][8];

typedef long long int ll;

int getX(string s)
{
    return s[0] - 'a';
}
int getY(string s)
{
    return s[1] - '1';
}

void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = INF;
            visited[i][j] = 0;
        }
    }
}

bool isvalid(int x, int y)
{
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

vector<pair<int, int>> movements = {
    {-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};

int bfs(string source, string destination)
{
    int sourceX = getX(source);
    int sourceY = getY(source);
    int destX = getX(destination);
    int destY = getY(destination);

    queue<pair<int, int>> q;
    q.push({sourceX, sourceY});
    visited[sourceX][sourceY] = 1;
    level[sourceX][sourceY] = 0;

    while (!q.empty())
    {
        pair<int, int> v = q.front();
        int x = v.first;
        int y = v.second;
        q.pop();

        for (auto movement : movements)
        {
            int childX = movement.first + x;
            int childY = movement.second + y;

            if (!isvalid(childX, childY))
                continue;

            if (!visited[childX][childY])
            {
                q.push({childX, childY});
                level[childX][childY] = level[x][y] + 1;
                visited[childX][childY] = 1;
            }
        }
        if (level[destX][destY] != INF)
            break;
    }

    return level[destX][destY];
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        reset();
        string s1, s2;
        cin >> s1 >> s2;
        int ans = bfs(s1, s2);
        cout << ans << endl;
    }

    return 0;
}