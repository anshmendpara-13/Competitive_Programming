#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e3 + 7;
vector<int> g[N];
int depth[N];

void dfs(int vertex, int parent = -1)
{
    for (auto child : g[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;

        dfs(child, vertex);
    }
}

int main()
{
    // diameter of tree -> max length between two nodes
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);

    int max_depth = -1;
    int max_d_node;
    for (int i = 1; i <= n; i++)
    {
        if (max_depth < depth[i])
        {
            max_depth = depth[i];
            max_d_node = i;
        }
        depth[i] = 0;
    }

    dfs(max_d_node);
    int max_depth_s = -1;
    max_depth = -1;
    for (int i = 1; i <= n; i++)
    {
        if (max_depth < depth[i])
        {
            max_depth = depth[i];
            max_depth_s = i;
        }
    }

    cout << max_d_node << " " << max_depth_s << endl;
    cout << max_depth << endl;

    return 0;
}