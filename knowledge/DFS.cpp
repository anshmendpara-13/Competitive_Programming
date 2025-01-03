#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e5 + 7;
vector<int> g[N];


bool visited[N];

void dfs(int vertex) // time complexity -> O(E+V)
{
    // take action on vertex after entering the vertex
    if (visited[vertex])
        return; // 1
    visited[vertex] = 1;

    for (auto child : g[vertex]) // O(E)
    {
        // take action on child before entering the child node
        // if (visited[child])  // 1 or
        //     continue;
        // cout << "parent :" << vertex << " : "
        //      << "child : " << child << endl;

        dfs(child);

        // take action on child after exiting child node
    }

    // take action on vertex before exiting the vertex
}

int main()
{
    /*
        depth first search
        we make visited array
    */

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);

    return 0;
}