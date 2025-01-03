#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e3 + 7;
vector<int> g[N];
vector<ll> ss(N, 0);     // Initializing vectors with size N and default value 0
vector<int> ecost(N, 0); // Initializing vectors with size N and default value 0

void dfs1(int vertex, int parent = 0)
{
    if (vertex % 2 == 0)
        ecost[vertex]++;  // Increment ecost for even vertices
    ss[vertex] += vertex; // Add current vertex to subtree sum of vertex

    for (auto child : g[vertex])
    {
        if (child == parent)
            continue;

        dfs1(child, vertex);

        ss[vertex] += ss[child];       // Update subtree sum of vertex
        ecost[vertex] += ecost[child]; // Update count of even numbers in subtree of vertex
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // cin >> v; // Read the value of v

    dfs1(1, -1);

    int q;
    cin >> q; // Read the number of queries
    while (q--)
    {
        int v;
        cin >> v;                                 // Read the vertex for the query
        // cout << ss[v] << " " << ecost[v] << endl; // Print subtree sum and count of even numbers
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << ss[i] << " " << ecost[i] << endl;
    }

    return 0;
}
