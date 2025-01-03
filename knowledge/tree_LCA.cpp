#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 7;
vector<int> g[N];
int par1[N];

void dfs(int vertex, int parent = -1)
{
    par1[vertex] = parent;
    for (auto child : g[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
    }
}

vector<int> path(int vertex)
{
    vector<int> ans;
    while (vertex != -1)
    {
        ans.push_back(vertex);
        vertex = par1[vertex];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) // Loop runs for n-1 edges in a tree
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x); // Since it's an undirected tree, add edge in both directions
    }

    dfs(1); // Assuming the root of the tree is node 1

    int node1;
    cin >> node1;
    vector<int> path_node_dest1 = path(node1);

    reverse(path_node_dest1.begin(), path_node_dest1.end());
    // for (auto val : path_node_dest1)
    // {
    //     cout << val << " ";
    // }

    cout << endl;

    int node2;
    cin >> node2;
    vector<int> path_node_dest2 = path(node2);

    reverse(path_node_dest2.begin(), path_node_dest2.end());
    // for (auto val : path_node_dest2)
    // {
    //     cout << val << " ";
    // }
    int ans = -1;
    for (int i = 0; i < min(path_node_dest1.size(), path_node_dest2.size()); i++)
    {
        if (path_node_dest1[i] != path_node_dest2[i])
        {
            break;
        }
        ans = path_node_dest1[i];
    }
    cout << ans << endl;
    return 0;
}