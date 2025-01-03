#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e5 + 7;
vector<int> g[N];

bool visited[N];
bool isloopexist = false;

bool dfs(int vertex, int par)
{
    visited[vertex] = true;

    for (auto child : g[vertex])
    {
        if (visited[child] && child == par)
        {
            continue;
        }
        if (visited[child])
            return true;

        isloopexist |= dfs(child, vertex);
    }

    return isloopexist;
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }
    bool isloopexist = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        if (dfs(i, 0))
        {

            isloopexist = true;
            break;
        }
    }
    cout << isloopexist << endl;
    return 0;
}