#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

pair<int, int> findfarthestnode(int n, unordered_map<int, vector<int>> &adj, int sourcenode)
{
    queue<int> que;
    vector<bool> visited(n, false);

    que.push(sourcenode);
    visited[sourcenode] = true;

    int maxdistance = 0;
    int farthestnode = sourcenode;

    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            int currentnode = que.front();
            que.pop();

            farthestnode = currentnode;
            for (int neighbor : adj[currentnode])
            {
                if (!visited[neighbor])
                {
                    que.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        if (!que.empty())
            maxdistance++;
    }
    return {farthestnode, maxdistance};
}

int finddiameter(int n, unordered_map<int, vector<int>> &adj)
{
    auto [farthestnode1, diameter1] = findfarthestnode(n, adj, 0);
    auto [farthestnode2, diameter2] = findfarthestnode(n, adj, farthestnode1);

    return diameter2;
}

int treediameter(vector<vector<int>> &edges)
{
    int n = edges.size() + 1;
    unordered_map<int, vector<int>> adj;

    for (auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    return finddiameter(n, adj);
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> edges(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> edges[i][j];
        }
    }

    cout << treediameter(edges) << endl;

    return 0;
}
