#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e3 + 7;
vector<int> g[N];
int depth[N];
int height[N];

void dfs(int vertex, int parent)
{
    // take action on vertex after entering the vertex

    for (auto child : g[vertex])
    {
        // take action on child before entering the child node
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;

        dfs(child, vertex);

        // take action on child after exiting child node
        height[vertex] = max(height[vertex], height[child] + 1); // max height from all child nodes
    }

    // take action on vertex before exiting the vertex
}

int main()
{
    // height and depth of particular node
    // leaf node height are zero
    // root depth are zero

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << i << ":" << depth[i] << ":" << height[i] << endl;
    }

    return 0;
}