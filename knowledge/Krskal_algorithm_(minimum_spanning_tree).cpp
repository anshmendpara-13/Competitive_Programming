#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int N = 1e2 + 7;
int parent[N];
int size[N];

void make(int v)
{
    size[v] = 1;
    parent[v] = v;
}

int find(int v)
{
    if (v == parent[v])
        return v;
    // below line is path compression
    return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    // size(current tree size) and rank(depth): for merge the tree
    // below line is union by rank : take the smaller one
    if (a != b)
    {
        if (size[a] > size[b])
        {
            parent[a] = b;
            size[b] += size[a];
        }
        else
        {
            parent[b] = a;
            size[a] += size[b];
        }
    }
}

int main()
{
    /*
    minimum spanning tree
    */

    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});
    }
    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++)
        make(i);

    int total_cost = 0;
    for (auto edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (find(u) == find(v))
            continue;

        Union(u, v);
        total_cost += wt;
        // cout << total_cost << endl; 
        // cout << u << " " << v << endl;
    }
    cout << total_cost << endl;

    return 0;
}