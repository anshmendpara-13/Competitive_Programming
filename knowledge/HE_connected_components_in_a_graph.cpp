#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e5 + 7;
vector<int> g[N];
vector<vector<int>> cc;
vector<int> current_cc;

bool visited[N];

void dfs(int vertex)
{
    visited[vertex] = true;
    current_cc.push_back(vertex);

    for (auto child : g[vertex])
    {
        if (visited[child])
        {
            continue;
        }
        dfs(child);
    }
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
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
        cnt++;
    }

    cout << cnt << endl;

    for (auto sc : cc)
    {
        for (auto val : sc)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}